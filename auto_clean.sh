#!/bin/bash

for file in $@; do

	echo "Processing $file"

	unifdef -K -k \
		-UCONFIG_SSV_SUPPORT_ANDROID \
		-DCONFIG_SSV_BUILD_AS_ONE_KO \
		-DCONFIG_FW_ALIGNMENT_CHECK \
		-DCONFIG_PLATFORM_SDIO_OUTPUT_TIMING=3 \
		-DCONFIG_PLATFORM_SDIO_BLOCK_SIZE=128 \
		-DKTHREAD_BIND \
		-DCONFIG_SSV_RSSI \
		-DCONFIG_SSV_VENDOR_EXT_SUPPORT \
		-DCONFIG_SSV_CABRIO_E \
		-DCONFIG_SSV_TX_LOWTHRESHOLD \
		-DRATE_CONTROL_REALTIME_UPDATA \
		-DCONFIG_SSV6200_HAS_RX_WORKQUEUE \
		-DUSE_THREAD_TX \
		-DENABLE_AGGREGATE_IN_TIME \
		-DENABLE_INCREMENTAL_AGGREGATION \
		-DUSE_GENERIC_DECI_TBL \
		-UUSE_LOCAL_CRYPTO \
		-UUSE_LOCAL_WEP_CRYPTO \
		-UUSE_LOCAL_SMS4_CRYPTO \
		-UCONFIG_SSV_WAPI \
		-DFW_WSID_WATCH_LIST \
		-DSSV6200_ECO \
		-DHAS_CRYPTO_LOCK \
		-DENABLE_TX_Q_FLOW_CONTROL \
		-DLINUX_VERSION_CODE=0x04046A \
		-UCONFIG_SSV_CABRIO_A \
		-UKTHREAD_BIND \
		-UMULTI_THREAD_ENCRYPT $file | indent -linux > /tmp/auto_clean.tmp

	cp /tmp/auto_clean.tmp $file

done
