################################################################################
#
# dpkg
#
################################################################################

DPKG_VERSION = 1.16.16
DPKG_SOURCE = dpkg_$(DPKG_VERSION).tar.xz
DPKG_SITE = http://ftp.de.debian.org/debian/pool/main/d/dpkg
DPKG_LICENSE = GPLv2+
DPKG_LICENSE_FILES = COPYING

DPKG_DEPENDENCIES = host-pkgconf
DPKG_CONF_OPTS = \
	--localstatedir=/var \
	--disable-dselect \
	--disable-start-stop-daemon \
	--disable-update-alternatives

HOST_DPKG_DEPENDENCIES = host-pkgconf
HOST_DPKG_CONF_OPTS = \
	--disable-dselect \
	--disable-start-stop-daemon \
	--disable-update-alternatives

$(eval $(autotools-package))
$(eval $(host-autotools-package))

# variables used by other packages
DPKG:=$(HOST_DIR)/usr/bin/dpkg
