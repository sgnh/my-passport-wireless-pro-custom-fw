################################################################################ 
# 
# minizip 
# 
################################################################################ 
 
MINIZIP_VERSION = 1.1
MINIZIP_SITE = https://github.com/nmoinvaz/minizip.git
MINIZIP_SITE_METHOD = git
MINIZIP_SOURCE = minizip-$(MINIZIP_VERSION).tar.gz
MINIZIP_DEPENDENCIES = zlib 
MINIZIP_AUTORECONF = YES
MINIZIP_INSTALL_STAGING = YES 
MINIZIP_INSTALL_TARGET = YES
MINIZIP_CONF_OPTS = --enable-demos
MINIZIP_LICENSE = zlib license 
MINIZIP_LICENSE_FILES = LICENSE

$(eval $(autotools-package))
