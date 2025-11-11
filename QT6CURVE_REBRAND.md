# Qt6Curve Rebranding Summary

This document summarizes the changes made to rebrand QtCurve as Qt6Curve for Qt6-specific installations.

## Overview

The Qt6 version of QtCurve has been rebranded as **Qt6Curve** to distinguish it from Qt4/Qt5 versions. This includes:

- Renamed executables and plugins
- Separate configuration directory: `~/.config/qt6curve/`
- Distinct style name in System Settings: "Qt6Curve"
- Separate installation paths to avoid conflicts with QtCurve Qt5

## Key Changes

### 1. Project Name
- **File**: `CMakeLists.txt`
- **Change**: Project renamed from `QtCurve` to `Qt6Curve`
- Added `QT6CURVE_VERSION_*` variables

### 2. Style Plugin
- **File**: `qt6/style/CMakeLists.txt`
- **Change**: Plugin output name changed from `qtcurve.so` to `qt6curve.so`
- **Location**: Installed to Qt6 plugins/styles directory

### 3. Plugin Metadata
- **File**: `qt6/style/qt6curvestyle.json` (NEW)
- **Content**: `{"Keys": ["Qt6Curve"]}`
- **File**: `qt6/style/qtcurve_plugin.h`
- **Change**: Updated to use `qt6curvestyle.json`
- **File**: `qt6/style/qtcurve_plugin.cpp`
- **Change**: Plugin recognizes both "Qt6Curve" and "QtCurve" keys for compatibility

### 4. Theme Files
- **File**: `qt6/style/qt6curve.themerc` (NEW)
- **Content**: KDE theme descriptor with name "Qt6Curve"
- **Installation**: `${KDE_INSTALL_DATADIR}/kstyle/themes/qt6curve/`
- **ConfigPage**: `kstyle_config/kstyle_qt6curve_config`

### 5. Configuration Module
- **File**: `qt6/config/CMakeLists.txt`
- **Changes**:
  - Library renamed: `kstyle_qtcurve6_config` → `kstyle_qt6curve_config`
  - UI resource file: `QtCurveui.rc` → `Qt6Curveui.rc`
  - Installation: `${KDE_INSTALL_KXMLGUIDIR}/Qt6Curve/`

### 6. Configuration Directory
- **File**: `lib/utils/dirs.cpp`
- **Change**: Config directory changed from `~/.config/qtcurve/` to `~/.config/qt6curve/`
- **Environment Variables**:
  - Primary: `QT6CURVE_CONFIG_DIR`
  - Fallback: `QTCURVE_CONFIG_DIR` (for compatibility)

### 7. Translation Domain
- **File**: `qt6/CMakeLists.txt`
- **Change**: Translation domain changed from `qtcurve` to `qt6curve`

### 8. GTK2 Theme Directory
- **File**: `CMakeLists.txt`
- **Change**: GTK2 theme directory changed from `QtCurve` to `Qt6Curve`
- **Path**: `${GTK2_PREFIX}/share/themes/Qt6Curve/`

### 9. KWin Decoration
- **File**: `qt6/kwin/CMakeLists.txt`
- **Changes**:
  - Variables renamed: `kwin3_qtcurve_*` → `kwin3_qt6curve_*`
  - Plugin output: `kwin3_qt6curve`
  - Desktop file: `qt6curve.desktop`

- **File**: `qt6/kwin/qt6curve.desktop` (NEW)
- **Content**: KWin decoration descriptor with name "Qt6Curve"
- **Library**: `kwin3_qt6curve`

### 10. UI Resource Files
- **File**: `qt6/config/Qt6Curveui.rc` (NEW)
- **Content**: KPart GUI descriptor for Qt6Curve configuration

## Installation Paths

### Qt6 Style Plugin
```
${QT6_PLUGIN_DIR}/styles/qt6curve.so
```

### KDE Theme Files
```
${KDE_INSTALL_DATADIR}/kstyle/themes/qt6curve/qt6curve.themerc
```

### Configuration Module
```
${QT6_PLUGIN_DIR}/kstyle_config/kstyle_qt6curve_config.so
```

### KWin Decoration
```
${PLUGIN_INSTALL_DIR}/kwin3_qt6curve.so
${DATA_INSTALL_DIR}/kwin/qt6curve.desktop
```

### UI Resources
```
${KDE_INSTALL_KXMLGUIDIR}/Qt6Curve/Qt6Curveui.rc
```

## Configuration

### User Configuration Directory
```
~/.config/qt6curve/
```

### Configuration Files
- Main config: `~/.config/qt6curve/stylerc`
- Old config (for migration): `~/.config/qt6curve/qtcurvestylerc`

### Environment Variables
- `QT6CURVE_CONFIG_DIR`: Override config directory location
- `QTCURVE_CONFIG_DIR`: Fallback for compatibility

## System Settings Integration

### Style Name
The style appears in KDE System Settings as **"Qt6Curve"** with the description:
- English: "Highly configurable Qt6 style"
- (Localized versions available)

### Configuration Panel
Accessible via:
- System Settings → Appearance → Application Style → Configure (when Qt6Curve is selected)
- Module: `kstyle_qt6curve_config`

## Compatibility Notes

1. **Plugin Key Recognition**: The Qt6 plugin recognizes both "Qt6Curve" and "QtCurve" as valid style keys for backward compatibility.

2. **Environment Variables**: The config directory lookup checks `QT6CURVE_CONFIG_DIR` first, then falls back to `QTCURVE_CONFIG_DIR`.

3. **Separate from Qt5**: Qt6Curve installs completely separately from QtCurve Qt5, allowing both to coexist on the same system.

## Building Qt6Curve

```bash
cd /home/www/KDE-trunk/qtcurve/build
cmake .. -DENABLE_QT6=ON -DENABLE_QT5=OFF -DENABLE_QT4=OFF
make qt6curve
sudo make install
```

## Testing

After installation, Qt6Curve should appear in:
1. System Settings → Appearance → Application Style (as "Qt6Curve")
2. Qt6 applications can use it via: `QT_STYLE_OVERRIDE=Qt6Curve`
3. Configuration saved to: `~/.config/qt6curve/stylerc`

## Migration from QtCurve

Users can migrate their QtCurve Qt5 settings by:
1. Copying `~/.config/qtcurve/stylerc` to `~/.config/qt6curve/stylerc`
2. Or setting `QT6CURVE_CONFIG_DIR=~/.config/qtcurve` to use the old location

## Files Modified

### CMake Build System
- `/CMakeLists.txt`
- `/qt6/CMakeLists.txt`
- `/qt6/style/CMakeLists.txt`
- `/qt6/config/CMakeLists.txt`
- `/qt6/kwin/CMakeLists.txt`

### Source Code
- `/lib/utils/dirs.cpp`
- `/qt6/style/qtcurve_plugin.h`
- `/qt6/style/qtcurve_plugin.cpp`

### New Files Created
- `/qt6/style/qt6curvestyle.json`
- `/qt6/style/qt6curve.themerc`
- `/qt6/config/Qt6Curveui.rc`
- `/qt6/kwin/qt6curve.desktop`
- `/QT6CURVE_REBRAND.md` (this file)

## Notes

- All internal code still uses the QtCurve namespace and class names for consistency
- Only user-facing names, file names, and installation paths have been changed
- The rebranding is specific to Qt6 builds; Qt4 and Qt5 builds remain as "QtCurve"
