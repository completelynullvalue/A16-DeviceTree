#
# Copyright (C) 2024 GrapheneOS
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# This makefile contains the product partition contents for CTS on
# GSI compliance testing. Only add something here for this purpose.
$(call inherit-product, $(SRC_TARGET_DIR)/product/media_product.mk)

PRODUCT_PACKAGES += \
    Browser2 \
    Camera2 \
    Dialer \
    LatinIME \
    frameworks-base-overlays \
    apexd \
    android.hardware.health@2.1-service.gsi \
    android.hardware.health-service.example \
    android.hardware.keymaster@3.0-service.gsi \
    android.hardware.gatekeeper@1.0-service.gsi \
    health-hal.rc \
    software-keymaster.rc \
    init.gsi_clean.rc \
    disable-vendor-services.rc \
    fix-linkerconfig.rc \
    gsi-vendor-mount.rc \

# Default AOSP sounds
$(call inherit-product-if-exists, frameworks/base/data/sounds/AllAudio.mk)

# Additional settings used in all AOSP builds
PRODUCT_PRODUCT_PROPERTIES += \
    ro.config.ringtone?=Ring_Synth_04.ogg \
    ro.config.notification_sound?=pixiedust.ogg \
    ro.com.android.dataroaming?=true \

PRODUCT_COPY_FILES += \
    device/sample/etc/apns-full-conf.xml:$(TARGET_COPY_OUT_PRODUCT)/etc/apns-conf.xml \
    device/grapheneos/gsi_clean/linkerconfig-gsi.sh:$(TARGET_COPY_OUT_SYSTEM)/bin/linkerconfig-gsi

# SELinux policy for GSI Clean (patched directly into platform policy)
# Policy definitions: /system/sepolicy/private/gsi_clean.te
# File contexts: /system/sepolicy/private/file_contexts
# Keystore GSI policy: device/grapheneos/gsi_clean/sepolicy/keystore_gsi.te

# Include GSI Clean SELinux policies in the build
BOARD_SEPOLICY_M4DEFS += \
    -D gsi_clean_sepolicy=1

# Ignore SELinux neverallow violations for GSI builds
SELINUX_IGNORE_NEVERALLOWS := true











