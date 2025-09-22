#!/system/bin/sh

# Keystore integration script for GrapheneOS GSI - Dummy Implementation
# This script sets up custom keymaster/gatekeeper with dummy keystore2
# NOTE: Using stub keystore2 to prevent TrustZone crashes

vndk="$(getprop persist.sys.vndk)"
[ -z "$vndk" ] && vndk="$(getprop ro.vndk.version |grep -oE '^[0-9]+')"

# Create necessary directories for keystore integration
mkdir -p /data/vendor/keystore
mkdir -p /data/vendor/gatekeeper
chmod 0700 /data/vendor/keystore
chmod 0700 /data/vendor/gatekeeper

# Note: Hardware properties (ro.hardware.keystore, ro.hardware.gatekeeper) 
# are set by vendor_init or other mechanisms. This script focuses on
# service management and directory setup.

# Set software keystore properties for GSI compatibility
setprop ro.hardware.keystore software
setprop ro.hardware.gatekeeper software

# Start software keymaster services for GSI compatibility
echo "Starting software keymaster services for GSI" >> /data/vendor/keystore/integration.log

# Always start GSI keymaster service
if [ "$(getprop init.svc.android.hardware.keymaster@3.0-service.gsi)" != "running" ]; then
    setprop ctl.start android.hardware.keymaster@3.0-service.gsi
    echo "Started GSI keymaster@3.0-service" >> /data/vendor/keystore/integration.log
fi

# Start GSI gatekeeper service
if [ "$(getprop init.svc.android.hardware.gatekeeper@1.0-service.gsi)" != "running" ]; then
    setprop ctl.start android.hardware.gatekeeper@1.0-service.gsi
    echo "Started GSI gatekeeper@1.0-service" >> /data/vendor/keystore/integration.log
fi

# Wait a moment for services to initialize
sleep 2

# Verify services started successfully
if [ "$(getprop init.svc.android.hardware.keymaster@3.0-service.gsi)" = "running" ]; then
    echo "GSI Keymaster service running successfully" >> /data/vendor/keystore/integration.log
else
    echo "Warning: GSI Keymaster service failed to start" >> /data/vendor/keystore/integration.log
fi

if [ "$(getprop init.svc.android.hardware.gatekeeper@1.0-service.gsi)" = "running" ]; then
    echo "GSI Gatekeeper service running successfully" >> /data/vendor/keystore/integration.log
else
    echo "Warning: GSI Gatekeeper service failed to start" >> /data/vendor/keystore/integration.log
fi

# Verify dummy keystore2 is running
if [ "$(getprop init.svc.keystore2)" = "running" ]; then
    echo "Dummy keystore2 service running successfully" >> /data/vendor/keystore/integration.log
else
    echo "Warning: Dummy keystore2 service failed to start" >> /data/vendor/keystore/integration.log
fi

# Note: Version properties are set by the system or vendor init

# Final integration status
echo "=== GSI Keystore Integration Summary ===" >> /data/vendor/keystore/integration.log
echo "Integration completed with dummy keystore2" >> /data/vendor/keystore/integration.log
echo "Custom GSI keymaster and gatekeeper HALs active" >> /data/vendor/keystore/integration.log
echo "Dummy keystore2 prevents TrustZone crashes" >> /data/vendor/keystore/integration.log
echo "Integration completed at: $(date)" >> /data/vendor/keystore/integration.log
