#!/usr/bin/perl
#
# This script processes udev events for the addition or removal of USB devices and their
# associated partitions.  It only supports Image and Media Storage Class devices.  For
# media storage class devices, it only supports partitions with the following filesystems:
# ext2, ext3, ext4, fat16, fat32, hfs+, ntfs, and xfs.  The script will attempt to mount
# and export as a share all partitions of supported filesystems from USB devices when
# discovered.  When removed, the partitions will be unmounted and their associated shares
# will be deleted.
#
# Copyright (c) [2011-2013] Western Digital Technologies, Inc. All rights reserved.

use strict;
use warnings;
use lib '/usr/local/lib';
use wdAutoMountLib;

# Global Variables - return codes, inquiry data values, and config parameters.

my $TRUE = 1;
my $FALSE = 0;
my $STATUS_SUCCESS = 0;
my $STATUS_FAILURE = 1;
my $WD_VENDOR_ID = '1058';
my $INQ_DATA_SCSI_LEVEL_2 = 3;
my $INQ_DATA_SCSI_LEVEL_3 = 4;
my $INQ_DATA_DIRECT_ACCESS_BLOCK_DEVICE = 0;
my %configParams = ();

# Process the udev event and always return success.

&processUdevEvent();
exit $STATUS_SUCCESS;

# Process the udev Event
#
# @global   configParams    global configuration parameters (such as file locations)
#
# Process the udev event based on its event type.  The script is called by a process monitoring
# udev events and will call the script one event at a time.

sub processUdevEvent {

    # Load the auto-mount configuration parameters and obtain a lock on all the resources
    # associated with auto-mount (which is locked to process udev events and auto-mount
    # administrative requests).

    &wdAutoMountLib::loadParams(\%configParams, '/etc/nas/wdAutoMount.conf', '.+');
    my $lockHandle = &wdAutoMountLib::lockDatabase(\%configParams);

    # Load the alert parameters and then process the event.

    &wdAutoMountLib::loadParams(\%configParams, '/etc/nas/alert-param.sh', '^usb');

    # Build the description of the event to be processed by combining the action with the devtype or
    # subsystem (if the devtype is not specified, which is the case for scsi generic device events).

    my $action = &wdAutoMountLib::getEnv('ACTION');
    my $subsystem = &wdAutoMountLib::getEnv('SUBSYSTEM');
    my $devtype = &wdAutoMountLib::getEnv('DEVTYPE');
    my $event = $action . ' ' . ((length($devtype) > 0) ? $devtype : $subsystem);

    # Process the event.

    if ($event eq 'add usb device') {
        &processUsbDeviceAddedEvent();
    }
    elsif ($event eq 'remove usb device') {
        &processUsbDeviceRemovedEvent();
    }
    elsif ($event eq 'add scsi generic') {
        &processScsiGenericAddedEvent();
    }
    elsif ($event eq 'add disk') {
        &processDiskAddedEvent();
    }
    elsif ($event eq 'remove disk') {
        &processDiskRemovedEvent();
    }
    elsif ($event eq 'add partition') {
        &processPartitionAddedEvent();
    }
    elsif ($event eq 'remove partition') {
        &processPartitionRemovedEvent();
    }

    # Release the lock.

    &wdAutoMountLib::unlockDatabase($lockHandle);
}

# Process a "USB Device Added" udev Event
#
# @global   configParams    global configuration parameters (such as file locations)
#
# For a supported USB device, record information about the device in the USB database, which will be
# used to obtain device information when their associated partitions are added and to report device
# information to the controller management client.  If the device is not supported, an alert is
# generated.  If the device supports PTP (and not MSC), also create a partition for the device.

sub processUsbDeviceAddedEvent {

    # Initialize a record to describe the added device (from udev environment variables).

    my $deviceRecord = &createUsbDeviceRecord();

    # If the device is supported (a Media Storage Class or PTP device), record it in the database.
    # If it was already in the database, it will be updated to show that it is now connected.  Also,
    # log an event in the system log that a device was added and signal that a change has been made
    # to the USB database (to allow a polling storage management client to detect a change).

    if (&supportedDevice($deviceRecord)) {
        &wdAutoMountLib::updateDatabaseForAddedDevice(\%configParams, $deviceRecord);
        &wdAutoMountLib::logDeviceEvent('info', 'Device added', $deviceRecord);
        &wdAutoMountLib::databaseChangeNotification();

        # Create a partition for a PTP device if it doesn't also support MSC.  If it supports both,
        # the MSC will be used instead of PTP (we will receive udev events for the MSC partitions).

        if (($deviceRecord->{ptp} eq 'true') && ($deviceRecord->{msc} ne 'true')) {
            processPartitionAddedEvent();
        }
    }

    # If the device is not supported and is not to be ignored (such as a USB hub), send an alert
    # and log an event that a unsupported device was detected.

    elsif (!&ignoreDevice($deviceRecord)) {
        &wdAutoMountLib::sendAlert($configParams{usbUnsupportedDevice}, "\"$deviceRecord->{vendor}\" \"$deviceRecord->{model}\" \"$deviceRecord->{serial_number}\"");
        &wdAutoMountLib::logDeviceEvent('warn', 'Unsupported device', $deviceRecord);
    }
}

# Process a "USB Device Removed" udev Event
#
# @global   configParams    global configuration parameters (such as file locations)
#
# For a supported USB device that is still recorded as connected in the database, update the
# database to indicate that it is no longer connected.  If the user had ejected the drive prior
# to removal, the device will already be marked as "not connected" in the database so no additional
# work must be done.

sub processUsbDeviceRemovedEvent {

    # Initialize a record to describe the removed device (from udev environment variables).

    my $deviceRecord = &createUsbDeviceRecord();

    # If a device was removed that is still recorded as connected in the database, remove any
    # partitions that have not been removed, update the database to show it as removed, and send
    # an alert that the device was unsafely removed.  If the device had gone through a software
    # "eject", the device would not still be "connected" in the database.  Also, signal that a
    # change has been made to the USB database.

    if ($deviceRecord->{connected}) {
        &wdAutoMountLib::removeDevicePartitions(\%configParams, $deviceRecord, 0);
        &wdAutoMountLib::markDeviceAsRemoved(\%configParams, "WHERE connected='1' AND devpath='$deviceRecord->{devpath}'");
        &wdAutoMountLib::databaseChangeNotification();
    }

    # If the device was known, log an event that it was removed.

    if ($deviceRecord->{in_database}) {
        &wdAutoMountLib::logDeviceEvent('info', 'Device removed', $deviceRecord);
    }
}

# Process a "SCSI Generic (Device) Added" udev Event
#
# @global   ENV{DEVNAME}      udev event device name environment variable
# @global   ENV{DEVPATH}      udev event device path environment variable
# @global   configParams      global configuration parameters (such as file locations)
#
# To spin down a drive on eject, unlock a locked WD drive, get a drives standby timer, or obtain
# the SMART and lock status of a WD drives, SCSI commands must be performed through a SCSI generic
# device associated with the USB device.  So, discovery of SCSI generic devices must be for all
# drives.  However, we are only interested in the SCSI direct access block device (and the first
# one we find if there are multiple).  We need to find SCSI generic device associated with a USB
# device, its scsi_devname will be 'pending' or is empty ('').  When 'pending' is set, we know the
# device has a SCSI generic device associated with it and we will not report the device to the UI
# will it found and additional device information is obtained (SMART and/or lock status).  If the
# name is not set, the device may or may not have a SCSI generic device associated with it.
# If we find a SCSI generic device whose device type is 'direct access block device', we will save
# the SCSI devname.  We will then correct the SCSI level (if possible) and attempt to get the
# standby timer value.  If the drive may support SMART, we attempt to get its SMART status.  The
# devname of the SCSI generic device may be used later to unlock, spin down, or set the standby
# timer of the drive.

sub processScsiGenericAddedEvent {

    # Find the USB device associated with the SCSI generic device by checking the device paths.
    # The SCSI generic device path will contain the device path of its associated USB device.  A
    # USB device that needs to find its associated SCSI generic device will have an empty SCSI
    # devname or it will be set to 'pending'.

    my $deviceRecord = undef;
    my $devpath = &wdAutoMountLib::getEnv('DEVPATH', 1);
    my @deviceList = &wdAutoMountLib::getDeviceList(\%configParams, "WHERE connected='1'");
    foreach my $record (@deviceList) {
        if (($record->{scsi_devname} eq 'pending') || ($record->{scsi_devname} eq '')) {
            if ($devpath =~ /^$record->{devpath}/) {
                $deviceRecord = $record;
                last;
            }
        }
    }

    # If the associated USB device was found (which may not happen if this associated USB device
    # is not supported), check if it is a direct access block device.  If it is, we can take
    # additional actions.

    if (defined($deviceRecord)) {
        $deviceRecord->{scsi_devname} = &wdAutoMountLib::getEnv('DEVNAME');
        my $peripheralDeviceType = &wdAutoMountLib::getPeripheralDeviceType($deviceRecord);
        if ($peripheralDeviceType == $INQ_DATA_DIRECT_ACCESS_BLOCK_DEVICE) {

            # The SCSI driver for USB devices forces SCSI 3 device to report as SCSI 2.  To get the
            # encryption commands to work, we need to change the level back to SCSI 3.

            my $scsiLevel = `cat /sys$devpath/../../scsi_level`;
            chomp($scsiLevel);
            if ($scsiLevel == $INQ_DATA_SCSI_LEVEL_2) {
                &wdAutoMountLib::performSystemCommand("echo $INQ_DATA_SCSI_LEVEL_3 > /sys$devpath/../../scsi_level");
                my $newScsiLevel = `cat /sys$devpath/../../scsi_level`;
                chomp($newScsiLevel);
                &wdAutoMountLib::logEvent('info', "Changed SCSI level from $scsiLevel to $newScsiLevel for $deviceRecord->{vendor} $deviceRecord->{model}");
            }

            # Attempt to get the drive's standby timer.

            $deviceRecord->{standby_timer} = &wdAutoMountLib::getStandbyTimer($deviceRecord);

            # If the may supports SMART, attempt to get its SMART status.  Send an alert if the
            # drive's SMART status has transitioned to bad.

            if (&supportedSmartDrive($deviceRecord)) {
                my $smart_status = &wdAutoMountLib::getSmartStatus($deviceRecord);
                if (($smart_status eq 'bad') && ($deviceRecord->{smart_status} ne 'bad'))  {
                    &wdAutoMountLib::sendAlert($configParams{usbBadSmartStatus}, "\"$deviceRecord->{vendor}\" \"$deviceRecord->{model}\" \"$deviceRecord->{serial_number}\"");
                }
                $deviceRecord->{smart_status} = $smart_status;
                &wdAutoMountLib::logEvent('info', "SMART status $smart_status");
            }

            # Update the database with the SCSI devname and any newly discovered drive values.

            &wdAutoMountLib::performDatabaseCommand(\%configParams, "UPDATE Devices SET smart_status='$deviceRecord->{smart_status}', standby_timer='$deviceRecord->{standby_timer}', scsi_devname='$deviceRecord->{scsi_devname}' WHERE handle='$deviceRecord->{handle}'");
            &wdAutoMountLib::databaseChangeNotification();
        }
    }
}

# Process a "Disk Added" udev Event
#
# @global   ENV{DEVNAME}        udev event device name environment variable
# @global   ENV{DEVPATH}        udev event device path environment variable
# @global   ENV{ID_FS_USAGE}    udev event partition usage environment variable
# @global   ENV{ID_FS_TYPE}     udev event partition type environment variable
# @global   ENV{ID_FS_LABEL}    udev event partition label environment variable
# @global   configParams        global configuration parameters (such as file locations)
#
# To force the kernel to discover partitions from a locked drive after it has been unlocked, a
# command must be issued to the disk device.  This function gets the devname of a block device
# associated with a lockable drive that has not yet obtained the needed devname.  If the device
# supports encryption, its encryption status will be obtained.  If the device is locked, the
# password hint will read from the device's handy store.  An Attempt to unlock the drive will be
# made if the password hash was previously saved.  If the device was successfully unlocked, the
# kernel will be signaled to reread the partition table so that partition discovery will be
# performed. If this device reports its partition on its disk (instead of reporting it separately
# as a partition), add it now because we will not get a partition added event.

sub processDiskAddedEvent {

    # Initialize the drive's performance related setting.

    my ($name) = (&wdAutoMountLib::getEnv('DEVNAME')) =~ /\/dev\/(.+)/;
    &wdAutoMountLib::performSystemCommand("run-parts --arg=\"$name\" /etc/nas/drive-init.d");

    my $deviceRecord = undef;
    my $devpath = &wdAutoMountLib::getEnv('DEVPATH', 1);
    my @deviceList = &wdAutoMountLib::getDeviceList(\%configParams, "WHERE connected='1'");
    foreach my $record (@deviceList) {
        if ($devpath =~ /^$record->{devpath}/) {
            if (($record->{lock_state} eq 'pending') && ($record->{devname} eq '')) {
                $deviceRecord = $record;
            }
            last;
        }
    }

    # If the disk device was found, it's a WD drive that supports encryption.  Get it's lock state
    # and password hint.  Attempt to unlock the drive if we have a password hash saved.  If the
    # disk was unlocked, force Linux to read the partition table and discover partitions.

    if (defined($deviceRecord)) {
        $deviceRecord->{devname} = &wdAutoMountLib::getEnv('DEVNAME');
        $deviceRecord->{lock_state} = &wdAutoMountLib::getLockState($deviceRecord, 1);
        $deviceRecord->{password_hint} = '';
        if ($deviceRecord->{lock_state} eq 'locked') {
            my $securityRecord = &wdAutoMountLib::getSecurityInfo($deviceRecord);
            $deviceRecord->{password_hint} = $securityRecord->{password_hint};
            if ($deviceRecord->{password_hash} ne '') {
                $deviceRecord->{lock_state} = &wdAutoMountLib::unlockDrive($deviceRecord, $securityRecord);
            }
        }

        # If the device is locked, send an alert.  Then, update the database with the devname and
        # any newly discovered drive values.

        if ($deviceRecord->{lock_state} eq 'locked') {
            &wdAutoMountLib::sendAlert($configParams{usbLockedDevice}, "\"$deviceRecord->{vendor}\" \"$deviceRecord->{model}\" \"$deviceRecord->{serial_number}\"");
        }

        &wdAutoMountLib::performDatabaseCommand(\%configParams, "UPDATE Devices SET devname='$deviceRecord->{devname}', lock_state='$deviceRecord->{lock_state}', password_hint='$deviceRecord->{password_hint}' WHERE handle='$deviceRecord->{handle}'");
    }

    # Some devices don't have a partition table and put the partition on the block device.  If this
    # device reports having a supported filesystem, treat it as a partition.

    my %partitionRecord = ();
    $partitionRecord{usage} = &wdAutoMountLib::getEnv('ID_FS_USAGE');
    $partitionRecord{type} = &wdAutoMountLib::getEnv('ID_FS_TYPE');
    $partitionRecord{label} = &wdAutoMountLib::getEnv('ID_FS_LABEL');

    if (&supportedPartition(\%partitionRecord)) {
        processPartitionAddedEvent();
    }
}

# Process a "Disk Removed" udev Event
#
# @global   ENV{ID_FS_USAGE}    udev event partition usage environment variable
# @global   ENV{ID_FS_TYPE}     udev event partition type environment variable
# @global   ENV{ID_FS_LABEL}    udev event partition label environment variable
#
# If this device reports its partition on its disk (instead of reporting it separately as a
# partition), remove it now because we will not get a partition removed event.

sub processDiskRemovedEvent {

    # Some devices don't have a partition table and put the partition on the block device.  If this
    # device reports having a supported filesystem, treat it as a partition.

    my %partitionRecord = ();
    $partitionRecord{usage} = &wdAutoMountLib::getEnv('ID_FS_USAGE');
    $partitionRecord{type} = &wdAutoMountLib::getEnv('ID_FS_TYPE');
    $partitionRecord{label} = &wdAutoMountLib::getEnv('ID_FS_LABEL');

    if (&supportedPartition(\%partitionRecord)) {
        processPartitionRemovedEvent();
    }
}

# Process a "Partition Added" udev Event
#
# @global   configParams    global configuration parameters (such as file locations)
#
# If the partition is supported and it's associated drive is still connected, attempt to mount the
# partition and create a share for it.  If a share could not be successfully created, notify the
# user by sending an alert.

sub processPartitionAddedEvent {

    my $partitionRecord = &createPartitionRecord();
    my $deviceRecord = $partitionRecord->{deviceRecord};

    # If the device associated with the partition couldn't be found, do not process the
    # partition event.

    if (!defined($deviceRecord)) {
        &wdAutoMountLib::logPartitionEvent('warn', 'Device not found for partition', $partitionRecord);
        return;
    }

    # If the partition is not supported (for reasons such as having an unsupported filesystem), do
    # not process it and send an alert if it is not also to be ignored.  Only perform this check on
    # devices reported as partitions (partitions for PTP devices will have a devtype of usb device).

    if ((&wdAutoMountLib::getEnv('DEVTYPE') eq 'partition') && (!&supportedPartition($partitionRecord))) {
        &wdAutoMountLib::logPartitionEvent('warn', 'Unsupported partitions', $partitionRecord);
        if (!&ignorePartition($partitionRecord)) {
            &wdAutoMountLib::sendAlert($configParams{usbUnsupportedFilesystem}, "\"$deviceRecord->{vendor}\" \"$deviceRecord->{model}\" \"$deviceRecord->{serial_number}\" \"$partitionRecord->{type}\" \"$partitionRecord->{label}\"");
        }
        return;
    }

    # Create a share name for the partition.  Then, attempt to mount the partition and create a
    # share for it.  If the operation failed, send an alert.  Otherwise, update the database
    # with the partition information.

    &wdAutoMountLib::createShareName(\%configParams, $partitionRecord);

    if (&wdAutoMountLib::mountAndCreateShare(\%configParams, $partitionRecord, 'total') != $STATUS_SUCCESS) {
        &wdAutoMountLib::sendAlert($configParams{usbUnableToCreateShare}, "\"$deviceRecord->{vendor}\" \"$deviceRecord->{model}\" \"$deviceRecord->{serial_number}\" \"$partitionRecord->{type}\" \"$partitionRecord->{label}\" \"$partitionRecord->{share_name}\"");
    }
    else {
        &wdAutoMountLib::updateDatabaseForAddedPartition(\%configParams, $partitionRecord);
        &wdAutoMountLib::logPartitionEvent('info', 'Partition added', $partitionRecord);
        &wdAutoMountLib::databaseChangeNotification();
        if ($partitionRecord->{read_only} eq 'true') {
            &wdAutoMountLib::sendAlert($configParams{usbReadOnlyPartition}, "\"$partitionRecord->{share_name}\"");
        }
    }
}

# Process a "Partition Removed" udev Event
#
# @global   configParams    global configuration parameters (such as file locations)
#
# If the partition is recorded as connected (which it won't if the user ejected the device
# through the UI), unmount it, delete its share, update the database to indicate that it's no
# longer connected, and send an alert that an unsafe removal was performed.

sub processPartitionRemovedEvent {

    my $partitionRecord = &createPartitionRecord();

    # If the removed partition is still recorded as connected, unmount it, delete its share, update
    # the database to show the partition as removed, and signal that the USB database has changed.
    # If the user performed an ejected on the device before removing it, the partition will not
    # show up as connected and there will be no additional work to do.  Also, send an alert that an
    # unsafe removal was performed.  The user should have ejected the drive before removing it.  If
    # an ejected was performed on the device before removing it, the partition will not show up as
    # connected and there will be no additional work to do.

    if ($partitionRecord->{connected}) {
        my $deviceRecord = $partitionRecord->{deviceRecord};
        &wdAutoMountLib::unmountAndDeleteShare(\%configParams, $partitionRecord, 'remove');
        &wdAutoMountLib::markPartitionAsRemoved(\%configParams, $partitionRecord);
        &wdAutoMountLib::sendAlert($configParams{usbUnsafeDeviceRemoval}, "\"$deviceRecord->{vendor}\" \"$deviceRecord->{model}\" \"$deviceRecord->{serial_number}\" \"$partitionRecord->{share_name}\"");
        &wdAutoMountLib::logPartitionEvent('info', 'Partition removed', $partitionRecord);
        &wdAutoMountLib::databaseChangeNotification();
    }
}

# Create USB Device Record
#
# @global   ENV{ACTION}             udev event action (add/remove) environment variable
# @global   ENV{DEVPATH}            udev event device path environment variable
# @global   ENV{ID_VENDOR}          udev event vendor environment variable
# @global   ENV{ID_MODEL}           udev event model environment variable
# @global   ENV{ID_SERIAL_SHORT}    udev event serial number environment variable
# @global   ENV{ID_REVISION}        udev event revision environment variable
# @global   ENV{ID_USB_INTERFACES}  udev event USB interface descriptor environment variable
# @global   ENV{GPHOTO2_DRIVER}     udev event Gphoto2 driver support environment variable
# @global   ENV{DEVNUM}             udev event device number environment variable
# @global   ENV{BUSNUM}             udev event bus number environment variable
# @global   configParams            global configuration parameters (such as file locations)
#
# Create a record to describe the USB device being added or removed.

sub createUsbDeviceRecord {

    # Process the event differently based on whether the device is being added or removed.  When
    # added, information about the device is obtained from the udev event and sysfs.  When removed,
    # it's taken from the database.

    my %deviceRecord = ();
    $deviceRecord{devpath} = &wdAutoMountLib::getEnv('DEVPATH', $TRUE);
    if (&wdAutoMountLib::getEnv('ACTION') eq 'add') {

        # First, initialize the attributes of the device that are described in the udev event.

        $deviceRecord{vendor} = &wdAutoMountLib::getEnv('ID_VENDOR');
        $deviceRecord{model} = &wdAutoMountLib::getEnv('ID_MODEL');
        $deviceRecord{serial_number} = &wdAutoMountLib::getEnv('ID_SERIAL_SHORT');
        $deviceRecord{revision} = &wdAutoMountLib::getEnv('ID_REVISION');
        $deviceRecord{interfaces} = &wdAutoMountLib::getEnv('ID_USB_INTERFACES');

        # Based on the specified interface and Gphoto2 driver, record if the device supports PTP
        # and/or the Media Storage Class (MSC).  The driver may support communication with cameras
        # that use a proprietary protocol.  We will treat them as PTP devices.

        my $driver = &wdAutoMountLib::getEnv('GPHOTO2_DRIVER');
        $deviceRecord{ptp} = (($deviceRecord{interfaces} =~ /:060101:/) || ($driver eq 'PTP') || ($driver eq 'proprietary')) ? 'true' : 'false';
        $deviceRecord{msc} = ($deviceRecord{interfaces} =~ /:08/) ? 'true' : 'false';

        # If the device is not supported, the record has been sufficiently initialized.
        # Unsupported devices are not recorded in the database.  They do cause an alert to be
        # sent so only the basic identification information needed to be initialized.

        if (!&supportedDevice(\%deviceRecord)) {
            return \%deviceRecord;
        }

        # Obtain more USB characteristics.

        $deviceRecord{usb_port} = &wdAutoMountLib::getUsbPortNumber($deviceRecord{devpath});
        $deviceRecord{usb_version} = &wdAutoMountLib::getUsbVersion($deviceRecord{devpath});
        $deviceRecord{usb_speed} = &wdAutoMountLib::getUsbSpeed($deviceRecord{devpath});
        $deviceRecord{vendor_id} = &wdAutoMountLib::getVendorId($deviceRecord{devpath});
        $deviceRecord{product_id} = &wdAutoMountLib::getProductId($deviceRecord{devpath});

        # Initialize variables that may be updated later if SMART or encryption are supported.

        $deviceRecord{devname} = '';
        $deviceRecord{scsi_devname} = '';
        $deviceRecord{password_hash} = '';
        $deviceRecord{password_hint} = '';
        $deviceRecord{standby_timer} = 'unsupported';
        $deviceRecord{smart_status} = 'unsupported';
        $deviceRecord{lock_state} = 'unsupported';

        # If the device supports SMART commands (not necessarily the functionality), we need to
        # discover the associated SCSI device, so set the SCSI devname to pending, which will
        # cause the processing of SCSI generic events in order to find it.  Set the SMART status
        # to pending, which will be updated once the SCSI device is found.  Do the same thing for
        # lockable drives, which are in the same situation.

        if (&supportedSmartDrive(\%deviceRecord)) {
            $deviceRecord{scsi_devname} = 'pending';
            $deviceRecord{smart_status} = 'pending';
        }

        if (&supportedLockableDrive(\%deviceRecord)) {
            $deviceRecord{scsi_devname} = 'pending';
            $deviceRecord{lock_state} = 'pending';
        }

        # For PTP devices, attempt to load the vendor, model, version, and serial number of the
        # device (because the PTP values are often more descriptive than the USB values).

        if ($deviceRecord{ptp} eq 'true') {
            $deviceRecord{devname} = 'usb:' . &wdAutoMountLib::getEnv('BUSNUM') . ',' . &wdAutoMountLib::getEnv('DEVNUM');
            my $data = `gphoto2 --port="$deviceRecord{devname}" --summary`;
            if (defined($data)) {
                &wdAutoMountLib::updateRecordValue(\%deviceRecord, 'vendor', 'Manufacturer', $data);
                &wdAutoMountLib::updateRecordValue(\%deviceRecord, 'model', 'Model', $data);
                &wdAutoMountLib::updateRecordValue(\%deviceRecord, 'revision', 'Version', $data);
                &wdAutoMountLib::updateRecordValue(\%deviceRecord, 'serial_number', 'Serial Number', $data);
            }
        }

        # If a device with the same vendor, model, and serial number is currently connected, make
        # sure its still connected.  If it's not, remove it and its partitions.

        my $deviceDatabaseRecord = &wdAutoMountLib::getDeviceDatabaseRecord(\%configParams, "WHERE vendor='$deviceRecord{vendor}' AND model='$deviceRecord{model}' AND serial_number='$deviceRecord{serial_number}' AND connected='1'");
        if (defined($deviceDatabaseRecord)) {
            my $contents = `ls /sys$deviceDatabaseRecord->{devpath} 2> /dev/null`;
            if ($contents eq '') {
                &wdAutoMountLib::removeDevicePartitions(\%configParams, $deviceDatabaseRecord, $TRUE);
            }
        }

        # Check if the device is already in the database (which means it had previously been
        # attached). We use vendor, model, and serial number to identify the device.  Unfortunately,
        # serial number may not be supported, in which case this is a weak method to identify a
        # device.  We check database entries for devices not connected to avoid devices with the
        # same vendor and model and no serial number from grabbing the same handle.  If the device
        # is found in the database, we use the unique handle previously assigned the device.  We
        # also get it previous SMART status so we can detect the transition from good to bad.  If
        # the device is not in the database, create a unique handle for the device.

        $deviceDatabaseRecord = &wdAutoMountLib::getDeviceDatabaseRecord(\%configParams, "WHERE vendor='$deviceRecord{vendor}' AND model='$deviceRecord{model}' AND serial_number='$deviceRecord{serial_number}' AND connected='0'");
        if (defined($deviceDatabaseRecord) && defined($deviceDatabaseRecord->{handle})) {
            $deviceRecord{handle} = $deviceDatabaseRecord->{handle};
            $deviceRecord{smart_status} = $deviceDatabaseRecord->{smart_status};
            $deviceRecord{in_database} = $TRUE;
        }
        else {
            $deviceRecord{handle} = &wdAutoMountLib::createDriveHandle(\%configParams);
            $deviceRecord{in_database} = $FALSE;
        }

        # Lastly, mark the device as connected and record the time it was connected.

        $deviceRecord{connected} = $TRUE;
        $deviceRecord{timestamp} = &wdAutoMountLib::getTimestamp();
    }

    # If the device is being removed, find it in the database based on its devpath, which is unique
    # for all connected devices.  If the user performed a software "eject", the device would have
    # been marked as disconnected, so it would not be found in the database.  If that's the case,
    # indicate that its not connected and not in the database.  Otherwise, set the device's
    # attributes based on the values saved in the database.

    else {
        my $deviceDatabaseRecord = &wdAutoMountLib::getDeviceDatabaseRecord(\%configParams, "WHERE devpath='$deviceRecord{devpath}' AND connected='1'");
        if (defined($deviceDatabaseRecord) && defined($deviceDatabaseRecord->{handle})) {
            $deviceRecord{handle} = $deviceDatabaseRecord->{handle};
            $deviceRecord{timestamp} = $deviceDatabaseRecord->{timestamp};
            $deviceRecord{vendor} = $deviceDatabaseRecord->{vendor};
            $deviceRecord{model} = $deviceDatabaseRecord->{model};
            $deviceRecord{serial_number} = $deviceDatabaseRecord->{serial_number};
            $deviceRecord{revision} = $deviceDatabaseRecord->{revision};
            $deviceRecord{ptp} = $deviceDatabaseRecord->{ptp};
            $deviceRecord{usb_port} = $deviceDatabaseRecord->{usb_port};
            $deviceRecord{usb_version} = $deviceDatabaseRecord->{usb_version};
            $deviceRecord{usb_speed} = $deviceDatabaseRecord->{usb_speed};
            $deviceRecord{vendor_id} = $deviceDatabaseRecord->{vendor_id};
            $deviceRecord{product_id} = $deviceDatabaseRecord->{product_id};
            $deviceRecord{devname} = $deviceDatabaseRecord->{devname};
            $deviceRecord{scsi_devname} = $deviceDatabaseRecord->{scsi_devname};
            $deviceRecord{password_hash} = $deviceDatabaseRecord->{password_hash};
            $deviceRecord{password_hint} = $deviceDatabaseRecord->{password_hint};
            $deviceRecord{standby_timer} = $deviceDatabaseRecord->{standby_timer};
            $deviceRecord{smart_status} = $deviceDatabaseRecord->{smart_status};
            $deviceRecord{lock_state} = $deviceDatabaseRecord->{lock_state};
            $deviceRecord{in_database} = $TRUE;
            $deviceRecord{connected} = $TRUE;
        }
        else {
            $deviceRecord{in_database} = $FALSE;
            $deviceRecord{connected} = $FALSE;
        }
    }
    return \%deviceRecord;
}

# Create Partition Record
#
# @global   ENV{ACTION}             udev event action (add/remove) environment variable
# @global   ENV{DEVNAME}            udev event device name environment variable
# @global   ENV{DEVPATH}            udev event device path environment variable
# @global   ENV{DEVTYPE}            udev event device type environment variable
# @global   ENV{ID_FS_TYPE}         udev event partition type environment variable
# @global   ENV{ID_FS_USAGE}        udev event partition usage environment variable
# @global   ENV{ID_FS_UUID}         udev event partition UUID environment variable
# @global   configParams            global configuration parameters (such as file locations)
#
# Create a record to describe the discovered MSC partition or manufactured PTP partition.

sub createPartitionRecord {

    # Process the event differently based on whether the partition is being added or removed.  When
    # added, information about the device is obtained from the udev event.  When removed, it's taken
    # from the database.

    my %partitionRecord = ();
    if (&wdAutoMountLib::getEnv('ACTION') eq 'add') {

        # Attempt to find the USB device associated with the partition.  Exit initialization if it
        # could not be found (because some setting are based on USB device attributes).

        $partitionRecord{deviceRecord} = '';
        $partitionRecord{device_handle} = '';
        my $devpath = &wdAutoMountLib::getEnv('DEVPATH', $TRUE);
        my @deviceList = &wdAutoMountLib::getDeviceList(\%configParams, "WHERE connected='1'");
        foreach my $deviceRecord (@deviceList) {
            if ($devpath =~ /^$deviceRecord->{devpath}/) {
                $partitionRecord{deviceRecord} = $deviceRecord;
                $partitionRecord{device_handle} = $deviceRecord->{handle};
                last;
            }
        }
        if (length($partitionRecord{deviceRecord}) == 0) {
            return \%partitionRecord;
        }

        # If this is an MSC partition (whose DEVTYPE would be 'disk' or 'partition'), initialize
        # the record from values in the udev event.  Get the partition label using the blkid
        # utility.  Do not allow it to use a cache file because it may return the wrong label for
        # partitions with no label.  When a partition has no defined label, set it as an empty
        # string.  Replace unsupported characters in the volume label with underscores.

        my $deviceRecord = $partitionRecord{deviceRecord};
        if (&wdAutoMountLib::getEnv('DEVTYPE') ne 'usb device') {

            $partitionRecord{devname} = &wdAutoMountLib::getEnv('DEVNAME');
            $partitionRecord{type} = &wdAutoMountLib::getEnv('ID_FS_TYPE');
            $partitionRecord{usage} = &wdAutoMountLib::getEnv('ID_FS_USAGE');
            $partitionRecord{uuid} = &wdAutoMountLib::getEnv('ID_FS_UUID');
            ($partitionRecord{partition_number}) = $partitionRecord{devname} =~ /[a-z,A-Z]([0-9]+)/;
            if (!defined($partitionRecord{partition_number})) {
                $partitionRecord{partition_number} = 0;
            }
            my $result = `/sbin/blkid $partitionRecord{devname} -s LABEL  -c /dev/null`;
            chomp($result);
            ($partitionRecord{label}) = $result =~ /LABEL=\"(.+)\"/;
            if (!defined($partitionRecord{label})) {
                $partitionRecord{label} = '';
            }
            $partitionRecord{label} =~ s/[\$\`\'"\\]/_/g;
        }

        # If this is a PTP partition (whose DEVTYPE would be 'usb device'), the udev event is for
        # the PTP device. So we will manufacture a partition from the PTP device.

        else {
            $partitionRecord{devname} = $deviceRecord->{devname};
            $partitionRecord{type} = 'fuse.gphotofs';
            $partitionRecord{usage} = 'filesystem';
            $partitionRecord{uuid} = $deviceRecord->{serial_number};
            $partitionRecord{partition_number} = 1;
            $partitionRecord{label} = '';
        }

        # The partition will be considered read-only if the device supports PTP.  The mount time
        # will be updated when the partition is mounted.

        $partitionRecord{read_only} = $deviceRecord->{ptp};
        $partitionRecord{mount_time} = '';

        # Check if the partition is already in the database (which means it had previously been
        # attached).  If it is, initialize the setting from the values saved in the database.

        my $partitionDatabaseRecord = &wdAutoMountLib::getPartitionDatabaseRecord(\%configParams, "WHERE device_handle='$partitionRecord{device_handle}' AND partition_number='$partitionRecord{partition_number}' AND uuid='$partitionRecord{uuid}' AND connected='0'");
        if (defined($partitionDatabaseRecord)) {
            $partitionRecord{id} = $partitionDatabaseRecord->{id};
            $partitionRecord{share_name} = $partitionDatabaseRecord->{share_name};
            $partitionRecord{description} = $partitionDatabaseRecord->{description};
            $partitionRecord{media_serving} = $partitionDatabaseRecord->{media_serving};
            $partitionRecord{public_access} = $partitionDatabaseRecord->{public_access};
            $partitionRecord{in_database} = $TRUE;

            # If the label has changed (and it not empty), attempt to change the share name to
            # match the new label.  Update the database so that the partition and its associated
            # share access use the new share name.

            if (($partitionRecord{label} ne $partitionDatabaseRecord->{label}) && ($partitionRecord{label} ne ''))  {
                my $oldShareName = $partitionRecord{share_name};
                &wdAutoMountLib::createShareName(\%configParams, \%partitionRecord, "forcedUpdate");
                &wdAutoMountLib::performDatabaseCommands(\%configParams,
                    "UPDATE ShareAccess SET share_name='$partitionRecord{share_name}' WHERE share_name='$oldShareName'",
                    "UPDATE Partitions SET label='$partitionRecord{label}', share_name='$partitionRecord{share_name}' WHERE share_name='$oldShareName'");
                &wdAutoMountLib::logEvent('info', "Renamed share $oldShareName to $partitionRecord{share_name} due to label change");
            }
        }

        # If the partition is not in the database, assign it an unique ID and set its parameters
        # to their default value (which depends on whether the device support PTP or is unlocked).

        else {
            $partitionRecord{id} = &wdAutoMountLib::createPartitonId(\%configParams);
            $partitionRecord{share_name} = '';
            $partitionRecord{description} = '';
            $partitionRecord{media_serving} = $deviceRecord->{ptp} eq 'true' ? 'none' : 'any';
            $partitionRecord{public_access} = $deviceRecord->{lock_state} eq 'unlocked' ? 'false' : 'true';
            $partitionRecord{in_database} = $FALSE;
        }
    }

    # If the partition is being removed, find it in the database based on its devname, which is unique
    # for all connected partitions.  If the user performed a software "eject", the partition would have
    # been marked as disconnected, so it would not be found in the database.  If that's the case,
    # simply indicate that its not connected.  Otherwise, set the partition's attributes based on the
    # values saved in the database.

    else {
        $partitionRecord{devname} = &wdAutoMountLib::getEnv('DEVNAME');
        my $partitionDatabaseRecord = &wdAutoMountLib::getPartitionDatabaseRecord(\%configParams, "WHERE devname='$partitionRecord{devname}' AND connected='1'");
        if (defined($partitionDatabaseRecord)) {
            $partitionRecord{device_handle} = $partitionDatabaseRecord->{device_handle};
            $partitionRecord{deviceRecord} = &wdAutoMountLib::getDeviceDatabaseRecord(\%configParams, "WHERE handle='$partitionRecord{device_handle}' AND connected='1'");
            $partitionRecord{devname} = $partitionDatabaseRecord->{devname};
            $partitionRecord{type} = $partitionDatabaseRecord->{type};
            $partitionRecord{uuid} = $partitionDatabaseRecord->{uuid};
            $partitionRecord{partition_number} = $partitionDatabaseRecord->{partition_number};
            $partitionRecord{label} = $partitionDatabaseRecord->{label};
            $partitionRecord{read_only} = $partitionDatabaseRecord->{read_only};
            $partitionRecord{id} = $partitionDatabaseRecord->{id};
            $partitionRecord{share_name} = $partitionDatabaseRecord->{share_name};
            $partitionRecord{description} = $partitionDatabaseRecord->{description};
            $partitionRecord{media_serving} = $partitionDatabaseRecord->{media_serving};
            $partitionRecord{public_access} = $partitionDatabaseRecord->{public_access};
            $partitionRecord{mount_time} = $partitionDatabaseRecord->{mount_time};
            $partitionRecord{connected} = $TRUE;
        }
        else {
            $partitionRecord{connected} = $FALSE;
        }
    }
    return \%partitionRecord;
}

# Supported Partition
#
# @param    partitionRecord    record that describes the partition to be checked
#
# @return   true if the partition is supported, false otherwise
#
# Currently, only the following filesystems are supported: XFS, NTFS, EXT2, EXT3, EXT4, HFS+, and
# VFAT (FAT16 & FAT32).  A partition that is to be ignored (such as Apple's hidden partitions) will
# be treated as unsupported.

sub supportedPartition {
    my($partitionRecord) = @_;
    return (defined($partitionRecord->{usage}) && defined($partitionRecord->{type}) && defined($partitionRecord->{label})
           && ($partitionRecord->{usage} eq 'filesystem') && ($partitionRecord->{type} =~ /^(xfs|ntfs|vfat|hfsplus|ext[234])$/)
           && !ignorePartition($partitionRecord));
}

# Ignore Partition
#
# @param    partitionRecord    record that describes the partition to be checked
#
# @return   true if the partition is to be ignored, false otherwise
#
# Ignore both swap and unnamed filesystems.  Also ignore Apple's hidden partitions which are either
# a vfat partition that is labeled 'EFI' or an hfsplus partition that is labeled 'Boot OS X' (with
# or without a space between 'OS' and 'X'). Ignored partitions will not be added to the database
# and won't cause unsupported filesystem alerts.

sub ignorePartition {
    my($partitionRecord) = @_;
    return (($partitionRecord->{type} eq 'swap') || ($partitionRecord->{type} eq '')
           || (($partitionRecord->{type} eq 'vfat') && ($partitionRecord->{label} eq 'EFI'))
           || (($partitionRecord->{type} eq 'hfsplus') && ($partitionRecord->{label} =~ /^Boot OS( |)X$/i)));
}

# Supported Device
#
# @param    deviceRecord    record that describes the device to be checked
#
# @return   true if the device is supported, false otherwise
#
# Currently, the only Media Storage Class and PTP devices are supported.

sub supportedDevice {
    my($deviceRecord) = @_;
    return (($deviceRecord->{msc} eq 'true') || ($deviceRecord->{ptp} eq 'true'));
}

# Ignore Device
#
# @param    deviceRecord    record that describes the device to be checked
#
# @return   true if the device is to be ignored, false otherwise
#
# Ignore the device is it is an USB hub, which means it wouldn't be added to the database and won't
# cause an unsupported device alert.

sub ignoreDevice {
    my($deviceRecord) = @_;
    return ($deviceRecord->{interfaces} =~ /:09/);
}

# Supported Lockable Drive
#
# @param    deviceRecord    record that describes the device to be checked
#
# @return   true if the device is a supported lockable WD drive, false otherwise
#
# The only lockable drives supported are WD drives that are on a white list.

sub supportedLockableDrive {
    my($deviceRecord) = @_;

    # If the vendor ID is support (WD), read the file of support product IDs and compare them to
    # the device's product ID.  If one matches, the device is supported.

    my $status = $FALSE;
    if ($deviceRecord->{vendor_id} eq $WD_VENDOR_ID) {

        my $inputFilename = '/etc/nas/wdLockableDrives';
        open(INPUT_FILE, "$inputFilename");
        while (<INPUT_FILE>) {
            my $whiteListProductId = lc($_);
            chomp($whiteListProductId);

            if ($whiteListProductId eq $deviceRecord->{product_id}) {
                $status = $TRUE;
                last;
            }
        }
        close(INPUT_FILE);
    }
    return $status;
}

# Supported SMART Drive
#
# @param    deviceRecord    record that describes the device to be checked
#
# @return   true if we can attempt to get SMART data from the drive, false otherwise
#
# Currently, the reading of SMART status is only supported on WD drives.

sub supportedSmartDrive {
    my($deviceRecord) = @_;
    return ($deviceRecord->{vendor_id} eq $WD_VENDOR_ID) ? $TRUE : $FALSE;
}


