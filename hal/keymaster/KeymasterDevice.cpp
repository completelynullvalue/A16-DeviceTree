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

#define LOG_TAG "android.hardware.keymaster@3.0-impl.gsi"

#include "KeymasterDevice.h"
#include <android-base/logging.h>
#include <keymaster/soft_keymaster_device.h>
#include <keymaster/contexts/soft_keymaster_context.h>
#include <keymaster/authorization_set.h>
#include <keymaster/keymaster_tags.h>

namespace android {
namespace hardware {
namespace keymaster {
namespace V3_0 {
namespace implementation {

KeymasterDevice::KeymasterDevice() {
    LOG(INFO) << "Initializing GSI Clean Keymaster 3.0 device";
    
    // Initialize software keymaster device
    // For now, set to nullptr until we implement proper initialization
    // This will be fixed when we implement real functionality
    soft_keymaster_device_ = nullptr;
    keymaster_device_ = nullptr;
    
    LOG(INFO) << "GSI Clean Keymaster 3.0 device initialized";
}

KeymasterDevice::~KeymasterDevice() {
    // SoftKeymasterDevice will clean up automatically
}

Return<void> KeymasterDevice::getHardwareFeatures(getHardwareFeatures_cb _hidl_cb) {
    LOG(DEBUG) << "getHardwareFeatures called";
    
    // For GSI, we don't have real hardware features
    _hidl_cb(false, false, false, false, false, hidl_string("GSI-Clean"), hidl_string("GrapheneOS GSI"));
    return Void();
}


Return<ErrorCode> KeymasterDevice::addRngEntropy([[maybe_unused]] const hidl_vec<uint8_t>& data) {
    LOG(DEBUG) << "addRngEntropy called";
    
    if (soft_keymaster_device_) {
        return ErrorCode::OK;
    }
    return ErrorCode::UNKNOWN_ERROR;
}

Return<void> KeymasterDevice::generateKey([[maybe_unused]] const hidl_vec<KeyParameter>& keyParams,
                                        generateKey_cb _hidl_cb) {
    LOG(DEBUG) << "generateKey called";
    
    KeyCharacteristics characteristics;
    hidl_vec<uint8_t> keyBlob;
    
    // For GSI, we don't support key generation
    _hidl_cb(ErrorCode::UNSUPPORTED_PURPOSE, keyBlob, characteristics);
    return Void();
}

Return<void> KeymasterDevice::getKeyCharacteristics([[maybe_unused]] const hidl_vec<uint8_t>& keyBlob,
                                                  [[maybe_unused]] const hidl_vec<uint8_t>& appId,
                                                  [[maybe_unused]] const hidl_vec<uint8_t>& appData,
                                                  getKeyCharacteristics_cb _hidl_cb) {
    LOG(DEBUG) << "getKeyCharacteristics called";
    
    KeyCharacteristics characteristics;
    
    if (soft_keymaster_device_) {
        _hidl_cb(ErrorCode::OK, characteristics);
    } else {
        _hidl_cb(ErrorCode::UNKNOWN_ERROR, characteristics);
    }
    return Void();
}

Return<void> KeymasterDevice::importKey([[maybe_unused]] const hidl_vec<KeyParameter>& keyParams,
                                      [[maybe_unused]] KeyFormat keyFormat,
                                      [[maybe_unused]] const hidl_vec<uint8_t>& keyData,
                                      importKey_cb _hidl_cb) {
    LOG(DEBUG) << "importKey called";
    
    KeyCharacteristics characteristics;
    hidl_vec<uint8_t> keyBlob;
    
    if (soft_keymaster_device_) {
        _hidl_cb(ErrorCode::OK, keyBlob, characteristics);
    } else {
        _hidl_cb(ErrorCode::UNKNOWN_ERROR, keyBlob, characteristics);
    }
    return Void();
}

Return<void> KeymasterDevice::exportKey([[maybe_unused]] KeyFormat exportFormat,
                                      [[maybe_unused]] const hidl_vec<uint8_t>& keyBlob,
                                      [[maybe_unused]] const hidl_vec<uint8_t>& appId,
                                      [[maybe_unused]] const hidl_vec<uint8_t>& appData,
                                      exportKey_cb _hidl_cb) {
    LOG(DEBUG) << "exportKey called";
    
    hidl_vec<uint8_t> keyData;
    
    if (soft_keymaster_device_) {
        _hidl_cb(ErrorCode::OK, keyData);
    } else {
        _hidl_cb(ErrorCode::UNKNOWN_ERROR, keyData);
    }
    return Void();
}

Return<void> KeymasterDevice::attestKey([[maybe_unused]] const hidl_vec<uint8_t>& keyToAttest,
                                      [[maybe_unused]] const hidl_vec<KeyParameter>& attestParams,
                                      attestKey_cb _hidl_cb) {
    LOG(DEBUG) << "attestKey called";
    
    hidl_vec<hidl_vec<uint8_t>> certChain;
    
    if (soft_keymaster_device_) {
        _hidl_cb(ErrorCode::OK, certChain);
    } else {
        _hidl_cb(ErrorCode::UNKNOWN_ERROR, certChain);
    }
    return Void();
}

Return<void> KeymasterDevice::upgradeKey([[maybe_unused]] const hidl_vec<uint8_t>& keyBlobToUpgrade,
                                       [[maybe_unused]] const hidl_vec<KeyParameter>& upgradeParams,
                                       upgradeKey_cb _hidl_cb) {
    LOG(DEBUG) << "upgradeKey called";
    
    KeyCharacteristics characteristics;
    hidl_vec<uint8_t> keyBlob;
    
    if (soft_keymaster_device_) {
        _hidl_cb(ErrorCode::OK, keyBlob);
    } else {
        _hidl_cb(ErrorCode::UNKNOWN_ERROR, keyBlob);
    }
    return Void();
}

Return<ErrorCode> KeymasterDevice::deleteKey([[maybe_unused]] const hidl_vec<uint8_t>& keyBlob) {
    LOG(DEBUG) << "deleteKey called";
    
    if (soft_keymaster_device_) {
        return ErrorCode::OK;
    }
    return ErrorCode::UNKNOWN_ERROR;
}

Return<ErrorCode> KeymasterDevice::deleteAllKeys() {
    LOG(DEBUG) << "deleteAllKeys called";
    
    if (soft_keymaster_device_) {
        return ErrorCode::OK;
    }
    return ErrorCode::UNKNOWN_ERROR;
}

Return<ErrorCode> KeymasterDevice::destroyAttestationIds() {
    LOG(DEBUG) << "destroyAttestationIds called";
    
    if (soft_keymaster_device_) {
        return ErrorCode::OK;
    }
    return ErrorCode::UNKNOWN_ERROR;
}

Return<void> KeymasterDevice::begin([[maybe_unused]] KeyPurpose purpose,
                                  [[maybe_unused]] const hidl_vec<uint8_t>& keyBlob,
                                  [[maybe_unused]] const hidl_vec<KeyParameter>& inParams,
                                  begin_cb _hidl_cb) {
    LOG(DEBUG) << "begin called";
    
    OperationHandle operationHandle = 0;
    hidl_vec<KeyParameter> outParams;
    
    if (keymaster_device_) {
        // For GSI, we don't support real keymaster operations
        // Return unsupported for now
        _hidl_cb(ErrorCode::UNSUPPORTED_PURPOSE, outParams, operationHandle);
    } else {
        LOG(ERROR) << "keymaster device not available";
        _hidl_cb(ErrorCode::UNKNOWN_ERROR, outParams, operationHandle);
    }
    return Void();
}

Return<void> KeymasterDevice::update([[maybe_unused]] uint64_t operationHandle,
                                   [[maybe_unused]] const hidl_vec<KeyParameter>& inParams,
                                   [[maybe_unused]] const hidl_vec<uint8_t>& input,
                                   update_cb _hidl_cb) {
    LOG(DEBUG) << "update called";
    
    hidl_vec<KeyParameter> outParams;
    hidl_vec<uint8_t> output;
    uint32_t input_consumed = 0;
    
    if (keymaster_device_) {
        // For GSI, we don't support real keymaster operations
        _hidl_cb(ErrorCode::UNSUPPORTED_PURPOSE, input_consumed, outParams, output);
    } else {
        LOG(ERROR) << "keymaster device not available";
        _hidl_cb(ErrorCode::UNKNOWN_ERROR, input_consumed, outParams, output);
    }
    return Void();
}

Return<void> KeymasterDevice::finish([[maybe_unused]] uint64_t operationHandle,
                                   [[maybe_unused]] const hidl_vec<KeyParameter>& inParams,
                                   [[maybe_unused]] const hidl_vec<uint8_t>& input,
                                   [[maybe_unused]] const hidl_vec<uint8_t>& signature,
                                   finish_cb _hidl_cb) {
    LOG(DEBUG) << "finish called";
    
    hidl_vec<KeyParameter> outParams;
    hidl_vec<uint8_t> output;
    
    if (keymaster_device_) {
        // For GSI, we don't support real keymaster operations
        _hidl_cb(ErrorCode::UNSUPPORTED_PURPOSE, outParams, output);
    } else {
        LOG(ERROR) << "keymaster device not available";
        _hidl_cb(ErrorCode::UNKNOWN_ERROR, outParams, output);
    }
    return Void();
}

Return<ErrorCode> KeymasterDevice::abort([[maybe_unused]] uint64_t operationHandle) {
    LOG(DEBUG) << "abort called";
    
    if (keymaster_device_) {
        // For GSI, we don't support real keymaster operations
        return ErrorCode::UNSUPPORTED_PURPOSE;
    } else {
        LOG(ERROR) << "keymaster device not available";
        return ErrorCode::UNKNOWN_ERROR;
    }
}

}  // namespace implementation
}  // namespace V3_0
}  // namespace keymaster
}  // namespace hardware
}  // namespace android