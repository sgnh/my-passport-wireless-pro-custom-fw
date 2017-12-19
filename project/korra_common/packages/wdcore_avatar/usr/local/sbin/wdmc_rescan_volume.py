#!/usr/bin/python

import sqlite3
import sys
import os

fs_rescan_file = "/tmp/wdmc_rescan"
prev_diskstats_value = "/tmp/wdmc_rescan_diskstats"
wdmc_pipe="/tmp/WDMCDispatcher.pipe"

def send_volume_add_to_crawler( base_path ):
    xml = '<?xml version="1.0"?>\
    <volume_data  version="1.0">\
    <id>volume_add</id>\
    <source>"source"</source>\
    <volume>\
    <base_path>' + base_path + '</base_path>\
    <mount_point>' + base_path + '</mount_point>\
    <dev_name>dev_name</dev_name>\
    <drive_path_raw>drive_path_raw</drive_path_raw>\
    <volume_id_fs_label>volume_id_fs_label</volume_id_fs_label>\
    <volume_id_fs_uuid>volume_id_fs_uuid</volume_id_fs_uuid>\
    <volume_id_fs_type>volume_id_fs_type</volume_id_fs_type>\
    <volume_mount_time>1</volume_mount_time>\
    <volume_read_only>false</volume_read_only>\
    <volume_scratch></volume_scratch>\
    <internal_volume>true</internal_volume>\
    </volume>\
    </volume_data>'
    data = '\x00\x00\x00\x00'
    wdmcpipe = os.open(wdmc_pipe, os.O_WRONLY | os.O_NONBLOCK)
    if wdmcpipe:
        os.write(wdmcpipe, xml)
        os.write(wdmcpipe, buffer(data))
        os.close(wdmcpipe)
    
    return

rescan_needed = 0;
try:
    if os.path.isfile(fs_rescan_file):
        rescan_needed = 1
except:
    rescan_needed = 0

if rescan_needed == 0:
    sys.exit(0);
update_write_count = {}

con = sqlite3.connect ('/usr/local/nas/orion/orion.db')

with con:
    cur = con.cursor ()
    cur.execute ("SELECT base_path, is_connected FROM Volumes where dynamic_volume != 'true'")
    while True:
        row = cur.fetchone ()
        if row == None:
            break
        if row[1] == 'true':
            base_path = row[0]
            try:
                send_volume_add_to_crawler( base_path )
            except:
                continue
