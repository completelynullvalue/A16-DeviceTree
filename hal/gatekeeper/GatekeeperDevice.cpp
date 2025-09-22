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

#define LOG_TAG "android.hardware.gatekeeper@1.0-impl.gsi"

#include "GatekeeperDevice.h"
#include <android-base/logging.h>
#include <gatekeeper/gatekeeper.h>
#include <android/hardware/gatekeeper/1.0/types.h>

namespace android {
namespace hardware {
namespace gatekeeper {
namespace V1_0 {
namespace implementation {

GatekeeperDevice::GatekeeperDevice() {
    LOG(INFO) << "Initializing GSI Clean Gatekeeper 1.0 device";
    
    // For GSI, we don't have real gatekeeper hardware
    LOG(INFO) << "GSI Clean Gatekeeper 1.0 device initialized";
}

GatekeeperDevice::~GatekeeperDevice() {
    // GateKeeper will clean up automatically
}

Return<void> GatekeeperDevice::enroll(uint32_t uid,
                                    [[maybe_unused]] const hidl_vec<uint8_t>& currentPasswordHandle,
                                    [[maybe_unused]] const hidl_vec<uint8_t>& currentPassword,
                                    [[maybe_unused]] const hidl_vec<uint8_t>& desiredPassword,
                                    enroll_cb _hidl_cb) {
    LOG(DEBUG) << "enroll called for user " << uid;
    
    // For GSI, we don't have real hardware, so return not supported
    GatekeeperResponse response;
    response.data.setToExternal(nullptr, 0);
    
    _hidl_cb(response);
    return Void();
}

Return<void> GatekeeperDevice::verify(uint32_t uid,
                                    [[maybe_unused]] uint64_t challenge,
                                    [[maybe_unused]] const hidl_vec<uint8_t>& enrolledPasswordHandle,
                                    [[maybe_unused]] const hidl_vec<uint8_t>& providedPassword,
                                    verify_cb _hidl_cb) {
    LOG(DEBUG) << "verify called for user " << uid;
    
    // For GSI, we don't have real hardware, so return not supported
    GatekeeperResponse response;
    response.data.setToExternal(nullptr, 0);
    
    _hidl_cb(response);
    return Void();
}

Return<void> GatekeeperDevice::deleteUser(uint32_t userId, deleteUser_cb _hidl_cb) {
    LOG(DEBUG) << "deleteUser called for user " << userId;
    
    // For GSI, we don't have real hardware, so return not supported
    GatekeeperResponse response;
    response.data.setToExternal(nullptr, 0);
    
    _hidl_cb(response);
    return Void();
}

Return<void> GatekeeperDevice::deleteAllUsers(deleteAllUsers_cb _hidl_cb) {
    LOG(DEBUG) << "deleteAllUsers called";
    
    // For GSI, we don't have real hardware, so return not supported
    GatekeeperResponse response;
    response.data.setToExternal(nullptr, 0);
    
    _hidl_cb(response);
    return Void();
}


}  // namespace implementation
}  // namespace V1_0
}  // namespace gatekeeper
}  // namespace hardware
}  // namespace android