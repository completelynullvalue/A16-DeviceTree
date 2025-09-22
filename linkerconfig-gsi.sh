#!/system/bin/sh
# Wrapper for linkerconfig to handle GSI compatibility issues

# Set required environment variables
export SANITIZER_DEFAULT_VENDOR=""

# Check if VNDK APEX exists and create symlink if needed
if [ -f /system/system_ext/apex/com.android.vndk.v31.apex ] && [ ! -f /apex/com.android.vndk.v31.apex ]; then
    mkdir -p /apex
    ln -sf /system/system_ext/apex/com.android.vndk.v31.apex /apex/com.android.vndk.v31.apex
fi

# Run the original linkerconfig command
exec /system/bin/linkerconfig "$@"












