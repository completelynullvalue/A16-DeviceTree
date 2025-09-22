/*
 * Copyright (C) 2024 GrapheneOS
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "android.hardware.health@2.1-impl.gsi"

#include "HealthDevice.h"
#include <android-base/logging.h>

namespace android {
namespace hardware {
namespace health {
namespace V2_1 {
namespace implementation {

HealthDevice::HealthDevice() {
    LOG(INFO) << "Initializing GSI Clean Health 2.1 device";
    LOG(INFO) << "GSI Clean Health 2.1 device initialized";
}

HealthDevice::~HealthDevice() {
    // Health will clean up automatically
}

Return<void> HealthDevice::getChargeCounter(getChargeCounter_cb _hidl_cb) {
    LOG(DEBUG) << "getChargeCounter called";
    
    int32_t charge_counter = 0;
    Result result = Result::NOT_SUPPORTED;
    
    // For GSI, we don't have real hardware, so return not supported
    result = Result::NOT_SUPPORTED;
    
    _hidl_cb(result, charge_counter);
    return Void();
}

Return<void> HealthDevice::getCurrentNow(getCurrentNow_cb _hidl_cb) {
    LOG(DEBUG) << "getCurrentNow called";
    
    int32_t current = 0;
    Result result = Result::NOT_SUPPORTED;
    
    // For GSI, we don't have real hardware
    result = Result::NOT_SUPPORTED;
    
    _hidl_cb(result, current);
    return Void();
}

Return<void> HealthDevice::getCurrentAverage(getCurrentAverage_cb _hidl_cb) {
    LOG(DEBUG) << "getCurrentAverage called";
    
    int32_t current = 0;
    Result result = Result::NOT_SUPPORTED;
    
    // For GSI, we don't have real hardware
    result = Result::NOT_SUPPORTED;
    
    _hidl_cb(result, current);
    return Void();
}

Return<void> HealthDevice::getCapacity(getCapacity_cb _hidl_cb) {
    LOG(DEBUG) << "getCapacity called";
    
    int32_t capacity = 0;
    Result result = Result::NOT_SUPPORTED;
    
    // For GSI, we don't have real hardware
    result = Result::NOT_SUPPORTED;
    
    _hidl_cb(result, capacity);
    return Void();
}

Return<void> HealthDevice::getEnergyCounter(getEnergyCounter_cb _hidl_cb) {
    LOG(DEBUG) << "getEnergyCounter called";
    
    int64_t energy = 0;
    Result result = Result::NOT_SUPPORTED;
    
    // For GSI, we don't have real hardware
    result = Result::NOT_SUPPORTED;
    
    _hidl_cb(result, energy);
    return Void();
}

Return<void> HealthDevice::getChargeStatus(getChargeStatus_cb _hidl_cb) {
    LOG(DEBUG) << "getChargeStatus called";
    
    BatteryStatus status = BatteryStatus::UNKNOWN;
    Result result = Result::NOT_SUPPORTED;
    
    // For GSI, we don't have real hardware
    result = Result::NOT_SUPPORTED;
    
    _hidl_cb(result, status);
    return Void();
}

Return<void> HealthDevice::getHealthInfo(getHealthInfo_cb _hidl_cb) {
    LOG(DEBUG) << "getHealthInfo called";
    
    HealthInfo health_info;
    // Use default values for GSI environment
    
    Result result = Result::SUCCESS;  // This should succeed with default values
    
    // For GSI, we don't have real hardware
    result = Result::SUCCESS;
    
    _hidl_cb(result, health_info);
    return Void();
}

Return<Result> HealthDevice::update() {
    LOG(DEBUG) << "update called";
    
    // For GSI, we don't have real hardware, so return not supported
    return Result::NOT_SUPPORTED;
}

Return<void> HealthDevice::getHealthConfig(getHealthConfig_cb _hidl_cb) {
    LOG(DEBUG) << "getHealthConfig called";
    
    HealthConfig config;
    // Use default values for GSI environment
    
    Result result = Result::SUCCESS;  // Configuration should be available
    
    // For GSI, we don't have real hardware
    result = Result::SUCCESS;
    
    _hidl_cb(result, config);
    return Void();
}

Return<void> HealthDevice::getHealthInfo_2_1(getHealthInfo_2_1_cb _hidl_cb) {
    LOG(DEBUG) << "getHealthInfo_2_1 called";
    
    ::android::hardware::health::V2_1::HealthInfo health_info;
    // Use default values for GSI environment
    
    Result result = Result::SUCCESS;  // This should succeed with default values
    
    // For GSI, we don't have real hardware
    result = Result::SUCCESS;
    
    _hidl_cb(result, health_info);
    return Void();
}

Return<Result> HealthDevice::registerCallback([[maybe_unused]] const ::android::sp<::android::hardware::health::V2_0::IHealthInfoCallback>& callback) {
    LOG(DEBUG) << "registerCallback called";
    
    // For GSI, we don't support callbacks
    return Result::NOT_SUPPORTED;
}

Return<Result> HealthDevice::unregisterCallback([[maybe_unused]] const ::android::sp<::android::hardware::health::V2_0::IHealthInfoCallback>& callback) {
    LOG(DEBUG) << "unregisterCallback called";
    
    // For GSI, we don't support callbacks
    return Result::NOT_SUPPORTED;
}

Return<void> HealthDevice::getStorageInfo(getStorageInfo_cb _hidl_cb) {
    LOG(DEBUG) << "getStorageInfo called";
    
    hidl_vec<StorageInfo> storage_info;
    Result result = Result::NOT_SUPPORTED;
    
    // For GSI, we don't have real storage info
    _hidl_cb(result, storage_info);
    return Void();
}

Return<void> HealthDevice::getDiskStats(getDiskStats_cb _hidl_cb) {
    LOG(DEBUG) << "getDiskStats called";
    
    hidl_vec<DiskStats> disk_stats;
    Result result = Result::NOT_SUPPORTED;
    
    // For GSI, we don't have real disk stats
    _hidl_cb(result, disk_stats);
    return Void();
}

Return<void> HealthDevice::shouldKeepScreenOn(shouldKeepScreenOn_cb _hidl_cb) {
    LOG(DEBUG) << "shouldKeepScreenOn called";
    
    bool should_keep_screen_on = false;
    Result result = Result::NOT_SUPPORTED;
    
    // For GSI, we don't have real battery management
    _hidl_cb(result, should_keep_screen_on);
    return Void();
}

}  // namespace implementation
}  // namespace V2_1
}  // namespace health
}  // namespace hardware
}  // namespace android