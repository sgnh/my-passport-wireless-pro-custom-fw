#############################################################
#
# libav
#
#############################################################

LIBAV_VERSION = 0.8.17
LIBAV_SOURCE = libav-$(LIBAV_VERSION).tar.xz
LIBAV_SITE = http://libav.org/releases
LIBAV_INSTALL_STAGING = YES
LIBAV_INSTALL_TARGET = NO

#define LIBAV_EXTRACT_CMDS
#	tar zxvf $(DL_DIR)/$(LIBAV_SOURCE) -C $(@D)
#endef

LIBAV_CONF_OPTS = \
	--prefix=/usr		\
	--enable-shared 	\
	$(if $(BR2_HAVE_DOCUMENTATION),,--disable-doc)

ifeq ($(BR2_PACKAGE_LIBAV_GPL),y)
LIBAV_CONF_OPTS += --enable-gpl
else
LIBAV_CONF_OPTS += --disable-gpl
endif

ifeq ($(BR2_PACKAGE_LIBAV_NONFREE),y)
LIBAV_CONF_OPTS += --enable-nonfree
else
LIBAV_CONF_OPTS += --disable-nonfree
endif

#ifeq ($(BR2_PACKAGE_LIBAV_FFMPEG),y)
#LIBAV_CONF_OPTS += --enable-ffmpeg
#else
#LIBAV_CONF_OPTS += --disable-ffmpeg
#endif

#ifeq ($(BR2_PACKAGE_LIBAV_FFPLAY),y)
#LIBAV_DEPENDENCIES += sdl
#LIBAV_CONF_OPTS += --enable-ffplay
#LIBAV_CONF_ENV += SDL_CONFIG=$(STAGING_DIR)/usr/bin/sdl-config
#else
#LIBAV_CONF_OPTS += --disable-ffplay
#endif

#ifeq ($(BR2_PACKAGE_LIBAV_FFSERVER),y)
#LIBAV_CONF_OPTS += --enable-ffserver
#else
#LIBAV_CONF_OPTS += --disable-ffserver
#endif

#ifeq ($(BR2_PACKAGE_LIBAV_POSTPROC),y)
#LIBAV_CONF_OPTS += --enable-postproc
#else
#LIBAV_CONF_OPTS += --disable-postproc
#endif

ifeq ($(BR2_PACKAGE_LIBAV_SWSCALE),y)
LIBAV_CONF_OPTS += --enable-swscale
else
LIBAV_CONF_OPTS += --disable-swscale
endif

ifeq ($(BR2_PACKAGE_LIBAV_AVCODEC),y)
LIBAV_CONF_OPTS += --enable-avcodec
else
LIBAV_CONF_OPTS += --disable-avcodec
endif

ifeq ($(BR2_PACKAGE_LIBAV_AVFORMAT),y)
LIBAV_CONF_OPTS += --enable-avformat
else
LIBAV_CONF_OPTS += --disable-avformat
endif

ifeq ($(BR2_PACKAGE_LIBAV_AVDEVICE),y)
LIBAV_CONF_OPTS += --enable-avdevice
else
LIBAV_CONF_OPTS += --disable-avdevice
endif

ifeq ($(BR2_PACKAGE_LIBAV_AVFILTER),y)
LIBAV_CONF_OPTS += --enable-avfilter
else
LIBAV_CONF_OPTS += --disable-avfilter
endif

ifneq ($(call qstrip,$(BR2_PACKAGE_LIBAV_ENCODERS)),all)
LIBAV_CONF_OPTS += --disable-encoders \
	$(foreach x,$(call qstrip,$(BR2_PACKAGE_LIBAV_ENCODERS)),--enable-encoder=$(x))
endif

ifneq ($(call qstrip,$(BR2_PACKAGE_LIBAV_DECODERS)),all)
LIBAV_CONF_OPTS += --disable-decoders \
	$(foreach x,$(call qstrip,$(BR2_PACKAGE_LIBAV_DECODERS)),--enable-decoder=$(x))
endif

ifneq ($(call qstrip,$(BR2_PACKAGE_LIBAV_MUXERS)),all)
LIBAV_CONF_OPTS += --disable-muxers \
	$(foreach x,$(call qstrip,$(BR2_PACKAGE_LIBAV_MUXERS)),--enable-muxer=$(x))
endif

ifneq ($(call qstrip,$(BR2_PACKAGE_LIBAV_DEMUXERS)),all)
LIBAV_CONF_OPTS += --disable-demuxers \
	$(foreach x,$(call qstrip,$(BR2_PACKAGE_LIBAV_DEMUXERS)),--enable-demuxer=$(x))
endif

ifneq ($(call qstrip,$(BR2_PACKAGE_LIBAV_PARSERS)),all)
LIBAV_CONF_OPTS += --disable-parsers \
	$(foreach x,$(call qstrip,$(BR2_PACKAGE_LIBAV_PARSERS)),--enable-parser=$(x))
endif

ifneq ($(call qstrip,$(BR2_PACKAGE_LIBAV_BSFS)),all)
LIBAV_CONF_OPTS += --disable-bsfs \
	$(foreach x,$(call qstrip,$(BR2_PACKAGE_LIBAV_BSFS)),--enable-bsf=$(x))
endif

ifneq ($(call qstrip,$(BR2_PACKAGE_LIBAV_PROTOCOLS)),all)
LIBAV_CONF_OPTS += --disable-protocols \
	$(foreach x,$(call qstrip,$(BR2_PACKAGE_LIBAV_PROTOCOLS)),--enable-protocol=$(x))
endif

ifneq ($(call qstrip,$(BR2_PACKAGE_LIBAV_FILTERS)),all)
LIBAV_CONF_OPTS += --disable-filters \
	$(foreach x,$(call qstrip,$(BR2_PACKAGE_LIBAV_FILTERS)),--enable-filter=$(x))
endif

ifeq ($(BR2_PACKAGE_LIBAV_INDEVS),y)
LIBAV_CONF_OPTS += --enable-indevs
else
LIBAV_CONF_OPTS += --disable-indevs
endif

ifeq ($(BR2_PACKAGE_LIBAV_OUTDEVS),y)
LIBAV_CONF_OPTS += --enable-outdevs
else
LIBAV_CONF_OPTS += --disable-outdevs
endif

ifeq ($(BR2_TOOLCHAIN_HAS_THREADS),y)
LIBAV_CONF_OPTS += --enable-pthreads
else
LIBAV_CONF_OPTS += --disable-pthreads
endif

ifeq ($(BR2_PACKAGE_ZLIB),y)
LIBAV_CONF_OPTS += --enable-zlib
LIBAV_DEPENDENCIES += zlib
else
LIBAV_CONF_OPTS += --disable-zlib
endif

# MMX on is default for x86, disable it for lowly x86-type processors
ifeq ($(BR2_x86_i386)$(BR2_x86_i486)$(BR2_x86_i586)$(BR2_x86_i686)$(BR2_x86_pentiumpro)$(BR2_x86_geode),y)
LIBAV_CONF_OPTS += --disable-mmx
endif

# ARM defaults to v5: clear if less, add extra if more
ifeq ($(BR2_generic_arm)$(BR2_arm7tdmi)$(BR2_arm610)$(BR2_arm710)$(BR2_arm720t)$(BR2_arm920t)$(BR2_arm922t),y)
LIBAV_CONF_OPTS += --disable-armv5te
endif
ifeq ($(BR2_arm1136jf_s)$(BR2_arm1176jz_s)$(BR2_arm1176jzf-s),y)
LIBAV_CONF_OPTS += --enable-armv6
endif
# not suit for libav-9.12, but available for libavl-0.8.15
#ifeq ($(BR2_arm10)$(BR2_arm1136jf_s)$(BR2_arm1176jz_s)$(BR2_arm1176jzf-s)$(BR2_cortex_a8)$(BR2_cortex_a9),y)
#LIBAV_CONF_OPTS += --enable-armvfp
#endif
# NEON is optional for A9
ifeq ($(BR2_cortex_a8),y)
LIBAV_CONF_OPTS += --enable-neon
endif
# Set powerpc altivec appropriately
ifeq ($(BR2_powerpc),y)
ifeq ($(BR2_powerpc_7400)$(BR2_powerpc_7450)$(BR2_powerpc_970),y)
LIBAV_CONF_OPTS -= --enable-altivec
else
LIBAV_CONF_OPTS += --disable-altivec
endif
endif

LIBAV_CONF_OPTS += $(call qstrip,$(BR2_PACKAGE_LIBAV_EXTRACONF))

# Override LIBAV_CONFIGURE_CMDS: FFmpeg does not support --target and others
define LIBAV_CONFIGURE_CMDS
	(cd $(LIBAV_SRCDIR) && rm -rf config.cache && \
	$(TARGET_CONFIGURE_OPTSS) \
	$(TARGET_CONFIGURE_ARGS) \
	$(LIBAV_CONF_ENV) \
	./configure \
		--enable-cross-compile	\
		--cross-prefix=$(TARGET_CROSS) \
		--sysroot=$(STAGING_DIR) \
		--host-cc="$(HOSTCC)" \
		--arch=$(BR2_ARCH) \
		--target-os=linux \
		--extra-cflags=-fPIC \
		$(SHARED_STATIC_LIBS_OPTSS) \
		$(LIBAV_CONF_OPTS) \
	)
endef

$(eval $(autotools-package))
