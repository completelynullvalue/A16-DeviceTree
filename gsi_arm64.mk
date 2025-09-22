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

# The system image of gsi_arm64-userdebug is the GSI for devices with:
# - ARM 64-bit userspace
# - 64-bit binder interface
# - system-as-root
# - VNDK enforcement
# - compatible property override enabled

#
# All components inherited here go to system image
#
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/handheld_system.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/telephony_system.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/languages_default.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/updatable_apex.mk)
# Add adb keys to debuggable AOSP builds (if they exist)
$(call inherit-product-if-exists, vendor/google/security/adb/vendor_key.mk)

# Shared java libs
PRODUCT_PACKAGES += \
    com.android.nfc_extras \

# Disable artifact path requirements checking for GSI
PRODUCT_ENFORCE_ARTIFACT_PATH_REQUIREMENTS := false

# Always build modules from source
MODULE_BUILD_FROM_SOURCE := true

# Disable system_other partition creation for GSI
PRODUCT_BUILD_SYSTEM_OTHER_IMAGE := false

# Override system_other packages to prevent creation
PRODUCT_PACKAGES := $(filter-out cppreopts.sh otapreopt_script,$(PRODUCT_PACKAGES))

# Disable dexpreopt to prevent system_other creation
PRODUCT_DEX_PREOPT_DEFAULT := false
PRODUCT_DEX_PREOPT_BOOT_IMAGE_DEFAULT := false
PRODUCT_DEX_PREOPT_SYSTEM_OTHER := false

# Global dexpreopt disable
DEX_PREOPT_DEFAULT := false
WITH_DEXPREOPT := false
WITH_DEXPREOPT_PIC := false

#
# All components inherited here go to system_ext image
#
$(call inherit-product, device/grapheneos/gsi_clean/gsi_system_ext.mk)

# pKVM
$(call inherit-product, packages/modules/Virtualization/apex/product_packages.mk)

#
# All components inherited here go to product image
#
$(call inherit-product, device/grapheneos/gsi_clean/gsi_product.mk)

#
# Special settings for GSI releasing
#
$(call inherit-product, $(SRC_TARGET_DIR)/product/gsi_release.mk)

PRODUCT_NAME := gsi_arm64
PRODUCT_DEVICE := gsi_clean
PRODUCT_BRAND := GrapheneOS
PRODUCT_MODEL := GrapheneOS GSI Clean
PRODUCT_MANUFACTURER := GrapheneOS

PRODUCT_SOONG_DEFINED_SYSTEM_IMAGE := android_gsi
PRODUCT_USE_SOONG_NOTICE_XML := true
USE_SOONG_DEFINED_SYSTEM_IMAGE := true

# AVB DISABLED to get build working
# PRODUCT_SOONG_DEFINED_SYSTEM_IMAGE_USE_AVB := true

# Additional GSI AVB settings - DISABLED
# PRODUCT_PACKAGES += \
#     avbctl

# GSI-specific AVB properties - DISABLED
# PRODUCT_PROPERTY_OVERRIDES += \
#     ro.boot.verifiedbootstate=orange \
#     ro.boot.veritymode=enforcing

# Essential GSI properties
PRODUCT_PACKAGE_OVERLAYS := device/grapheneos/gsi_clean/overlays
PRODUCT_ENFORCE_ARTIFACT_PATH_REQUIREMENTS := relaxed

# GSI-specific properties
PRODUCT_PROPERTY_OVERRIDES += \
    ro.gsi.build=true \
    ro.gsi.clean=true

# Keystore properties for GSI compatibility
PRODUCT_PROPERTY_OVERRIDES += \
    ro.hardware.keystore=software \
    ro.hardware.gatekeeper=software

# Additional GSI settings
PRODUCT_PACKAGES += \
    gsi_skip_mount.cfg \
    init.gsi.rc

# Keystore integration script is copied in gsi_product.mk

# GSI HAL Services - Custom implementations (AOSP keystore2 is now dummy)
# Note: Using GSI-specific services defined in hal/Android.bp
PRODUCT_PACKAGES += \
    android.hardware.keymaster@3.0-service.gsi \
    android.hardware.gatekeeper@1.0-service.gsi \
    android.hardware.health@2.1-service.gsi

# Additional health implementations for compatibility
PRODUCT_PACKAGES += \
    android.hardware.health@2.0-impl \
    android.hardware.health@2.1-impl

# Force Scudo malloc implementation and disable hardened malloc
PRODUCT_MALLOC_IMPL := scudo
BOARD_HARDENED_MALLOC := false

# Explicitly disable hardened malloc packages
PRODUCT_PACKAGES := $(filter-out libhardened_malloc libhardened_malloc.hwasan,$(PRODUCT_PACKAGES))

# Additional Scudo configuration
PRODUCT_PROPERTY_OVERRIDES += \
    ro.debuggable=1 \
    ro.malloc.impl=scudo
