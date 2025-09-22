# GrapheneOS GSI Clean Device Tree

This is a clean, minimal GSI device tree implementation that avoids problematic dependencies that can cause build issues.

## Key Features

- **Clean AVB Configuration**: Properly configured AVB rollback index without timestamp conflicts
- **No Mainline Dependencies**: Avoids `BoardConfigMainlineCommon.mk` which causes rollback index issues
- **Minimal Configuration**: Only essential settings for GSI builds
- **GrapheneOS Branded**: Properly branded for GrapheneOS

## Files

- `BoardConfig.mk`: Main board configuration with clean AVB settings
- `gsi_arm64.mk`: Product configuration for ARM64 GSI
- `gsi_system_ext.mk`: System extension configuration
- `gsi_product.mk`: Product partition configuration
- `AndroidProducts.mk`: Product makefiles list
- `fstab.gsi`: Filesystem table for GSI
- `gsi_skip_mount.cfg`: Skip mount configuration
- `init.gsi.rc`: GSI-specific init configuration

## Key Differences from Original

1. **No Mainline Dependencies**: Removed `BoardConfigMainlineCommon.mk` include
2. **Clean AVB Configuration**: Fixed rollback index location issues
3. **Simplified Structure**: Removed problematic MGSI dependencies
4. **Direct Configuration**: All settings defined directly without inheritance conflicts

## Building

To build with this device tree:

```bash
lunch gsi_arm64-userdebug
mka adbd recoveryimage
```

## AVB Configuration

The AVB configuration is properly set with:
- `BOARD_AVB_ROLLBACK_INDEX := 3`
- `BOARD_AVB_ROLLBACK_INDEX_LOCATION := 1`
- `BOARD_AVB_SYSTEM_ROLLBACK_INDEX := 3`
- `BOARD_AVB_SYSTEM_ROLLBACK_INDEX_LOCATION := 1`

This avoids the timestamp-based rollback index that causes build failures.











