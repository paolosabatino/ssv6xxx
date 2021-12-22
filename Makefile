KMODULE_NAME=ssv6051

KBUILD_TOP := $(PWD)

ifeq ($(KERNELRELEASE),)

KVERS_UNAME ?= $(shell uname -r)
KVERS_ARCH ?= $(shell arch)

KBUILD ?= $(shell readlink -f /lib/modules/$(KVERS_UNAME)/build)

ifeq (,$(KBUILD))
$(error kernel build tree not found - set KBUILD to configured kernel)
endif

#KCONFIG := $(KBUILD)/config
#ifeq (,$(wildcard $(KCONFIG)))
#$(error No .config found in $(KBUILD), set KBUILD to configured kernel)
#endif

ifneq (,$(wildcard $(KBUILD)/include/linux/version.h))
ifneq (,$(wildcard $(KBUILD)/include/generated/uapi/linux/version.h))
$(error Multiple copied of version.h found, clean build tree)
endif
endif

# Kernel Makefile doesn't always know the exact kernel version, so we
# get it from the kernel headers instead and pass it to make.
VERSION_H := $(KBUILD)/include/generated/utsrelease.h
ifeq (,$(wildcard $(VERSION_H)))
VERSION_H := $(KBUILD)/include/linux/utsrelease.h
endif
ifeq (,$(wildcard $(VERSION_H)))
VERSION_H := $(KBUILD)/include/linux/version.h
endif
ifeq (,$(wildcard $(VERSION_H)))
$(error Please run 'make modules_prepare' in $(KBUILD))
endif

KVERS := $(shell sed -ne 's/"//g;s/^\#define UTS_RELEASE //p' $(VERSION_H))

ifeq (,$(KVERS))
$(error Cannot find UTS_RELEASE in $(VERSION_H), please report)
endif

INST_DIR = /lib/modules/$(KVERS)/misc

#include $(KCONFIG)

endif

include $(KBUILD_TOP)/ssv6051.cfg
include $(KBUILD_TOP)/platform-config.mak

EXTRA_CFLAGS := -I$(KBUILD_TOP) -I$(KBUILD_TOP)/include #-Wno-error=missing-attributes
DEF_PARSER_H = $(KBUILD_TOP)/include/ssv_conf_parser.h
$(shell env ccflags="$(ccflags-y)" $(KBUILD_TOP)/parser-conf.sh $(DEF_PARSER_H))

OBJS := ssvdevice/ssvdevice.c \
	ssvdevice/ssv_cmd.c \
	hci/ssv_hci.c \
	smac/init.c \
	smac/dev.c \
	smac/ssv_rc.c \
	smac/ssv_ht_rc.c \
	smac/ap.c \
	smac/ampdu.c \
	smac/ssv6xxx_debugfs.c \
	smac/sec_ccmp.c \
	smac/sec_tkip.c \
	smac/sec_wep.c \
	smac/wapi_sms4.c \
	smac/sec_wpi.c \
	smac/efuse.c \
	smac/ssv_pm.c \
	smac/sar.c \
	smac/ssv_cfgvendor.c \
	hwif/sdio/sdio.c \
	ssv6051-generic-wlan.c

ifeq ($(findstring -DCONFIG_SSV_SMARTLINK, $(ccflags-y)), -DCONFIG_SSV_SMARTLINK)
OBJS += smac/smartlink.c
endif

ifeq ($(findstring -DCONFIG_SSV_SUPPORT_AES_ASM, $(ccflags-y)), -DCONFIG_SSV_SUPPORT_AES_ASM)
OBJS += crypto/aes_glue.c
OBJS += crypto/sha1_glue.c
ASMS := crypto/aes-armv4.S
ASMS += crypto/sha1-armv4-large.S
endif

$(KMODULE_NAME)-y += $(ASMS:.S=.o)
$(KMODULE_NAME)-y += $(OBJS:.c=.o)

obj-$(CONFIG_SSV6200_CORE) += $(KMODULE_NAME).o

all: modules

modules:
	ARCH=arm $(MAKE) -C $(KBUILD) M=$(KBUILD_TOP)

clean:
	rm -f *.o *.ko .*.cmd *.mod.c *.symvers modules.order
	rm -rf .tmp_versions

install: modules
	mkdir -p -m 755 $(DESTDIR)$(INST_DIR)
	install -m 0644 $(KMODULE_NAME).ko $(DESTDIR)$(INST_DIR)
ifndef DESTDIR
	-/sbin/depmod -a $(KVERS)
endif

.PHONY: all modules clean install
