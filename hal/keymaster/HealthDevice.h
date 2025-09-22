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

#ifndef ANDROID_HARDWARE_HEALTH_V2_1_GSI_HEALTH_DEVICE_H
#define ANDROID_HARDWARE_HEALTH_V2_1_GSI_HEALTH_DEVICE_H

#include <android/hardware/health/2.1/IHealth.h>
#include <android/hardware/health/2.0/types.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace health {
namespace V2_1 {
namespace implementation {

using ::android::hardware::health::V2_1::IHealth;
using ::android::hardware::health::V2_0::Result;
using ::android::hardware::health::V1_0::BatteryStatus;
using ::android::hardware::health::V1_0::BatteryHealth;
using ::android::hardware::health::V2_0::HealthInfo;
using ::android::hardware::health::V2_1::HealthConfig;
using ::android::hardware::health::V2_0::StorageInfo;
using ::android::hardware::health::V2_0::DiskStats;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hardware::hidl_vec;
using ::android::hardware::hidl_string;

struct HealthDevice : public IHealth {
    HealthDevice();
    ~HealthDevice();

    // Methods from ::android::hardware::health::V2_0::IHealth follow.
    Return<void> getChargeCounter(getChargeCounter_cb _hidl_cb) override;
    Return<void> getCurrentNow(getCurrentNow_cb _hidl_cb) override;
    Return<void> getCurrentAverage(getCurrentAverage_cb _hidl_cb) override;
    Return<void> getCapacity(getCapacity_cb _hidl_cb) override;
    Return<void> getEnergyCounter(getEnergyCounter_cb _hidl_cb) override;
    Return<void> getChargeStatus(getChargeStatus_cb _hidl_cb) override;
    Return<void> getHealthInfo(getHealthInfo_cb _hidl_cb) override;
    Return<Result> update() override;

    // Methods from ::android::hardware::health::V2_1::IHealth follow.
    Return<void> getHealthConfig(getHealthConfig_cb _hidl_cb) override;
    Return<void> getHealthInfo_2_1(getHealthInfo_2_1_cb _hidl_cb) override;
    Return<Result> registerCallback(const ::android::sp<::android::hardware::health::V2_0::IHealthInfoCallback>& callback) override;
    Return<Result> unregisterCallback(const ::android::sp<::android::hardware::health::V2_0::IHealthInfoCallback>& callback) override;
    Return<void> getStorageInfo(getStorageInfo_cb _hidl_cb) override;
    Return<void> getDiskStats(getDiskStats_cb _hidl_cb) override;
    Return<void> shouldKeepScreenOn(shouldKeepScreenOn_cb _hidl_cb) override;

private:
    // No private members needed for GSI implementation
};

}  // namespace implementation
}  // namespace V2_1
}  // namespace health
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_HEALTH_V2_1_GSI_HEALTH_DEVICE_H
