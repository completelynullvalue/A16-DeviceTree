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

#define LOG_TAG "android.hardware.health@2.1-service.gsi"

#include <android-base/logging.h>
#include <hidl/HidlLazyUtils.h>
#include <hidl/HidlTransportSupport.h>

#include "HealthDevice.h"

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::hardware::health::V2_1::IHealth;
using android::hardware::health::V2_1::implementation::HealthDevice;

int main() {
    LOG(INFO) << "Starting GSI Clean Health 2.1 service";

    android::sp<IHealth> health = new HealthDevice();
    
    configureRpcThreadpool(1, true);
    
    const android::status_t status = health->registerAsService();
    if (status != android::OK) {
        LOG(FATAL) << "Could not register Health 2.1 service: " << status;
    }

    LOG(INFO) << "GSI Clean Health 2.1 service started";
    joinRpcThreadpool();
    return 0;
}



