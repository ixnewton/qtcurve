# Qt6Curve Configuration Panel Guide

## Overview

Qt6Curve includes a comprehensive configuration panel that integrates with KDE System Settings. The configuration module is automatically linked to the Qt6Curve style entry in System Settings.

## Accessing the Configuration Panel

### Method 1: Through System Settings (Recommended)

1. Open **System Settings**
2. Navigate to **Appearance** → **Application Style**
3. Select **Qt6Curve** from the style list
4. Click the **Configure** button (or **Configure Style** button)
5. The Qt6Curve configuration dialog will open

### Method 2: Direct Access (Advanced)

You can also access the configuration directly using:
```bash
kcmshell6 style
```
Then select Qt6Curve and click Configure.

## Configuration Module Details

### Installed Files

- **Configuration Module**: `/usr/lib/qt6/plugins/kstyle_config/kstyle_qt6curve_config.so`
- **Theme Descriptor**: `/usr/share/kstyle/themes/qt6curve/qt6curve.themerc`
- **UI Resources**: `/usr/share/kxmlgui5/Qt6Curve/Qt6Curveui.rc`

### Theme File Configuration

The `qt6curve.themerc` file contains the link to the configuration module:

```ini
[Misc]
Name=Qt6Curve
Comment=Highly configurable Qt6 style
ConfigPage=kstyle_config/kstyle_qt6curve_config

[KDE]
WidgetStyle=Qt6Curve
```

The `ConfigPage` entry tells KDE System Settings which configuration module to load when the "Configure" button is clicked.

## Configuration Storage

### User Configuration Directory

All Qt6Curve settings are stored in:
```
~/.config/qt6curve/
```

### Main Configuration File

The primary configuration file is:
```
~/.config/qt6curve/stylerc
```

This file contains all your Qt6Curve style preferences including:
- Colors and gradients
- Widget appearance
- Border styles
- Shadow effects
- Menu and toolbar settings
- And much more...

### Environment Variable Override

You can override the configuration directory location using:
```bash
export QT6CURVE_CONFIG_DIR=/path/to/custom/config/
```

For backward compatibility, the following environment variable is also supported:
```bash
export QTCURVE_CONFIG_DIR=/path/to/custom/config/
```

## Configuration Options

The Qt6Curve configuration panel provides extensive customization options organized into several tabs:

### General Tab
- Rounded corners
- Button appearance
- Default button indicator
- Focus rectangle style
- Mouse-over effects

### Frames Tab
- Frame styles for various widgets
- Group box appearance
- Tab widget styling

### Shading Tab
- Gradient configurations
- Custom shading options
- Appearance customization

### Colors Tab
- Custom color schemes
- Progress bar colors
- Selection colors
- Menu stripe colors

### Advanced Tab
- Fine-tuning options
- Performance settings
- Compatibility options

## Troubleshooting

### Configuration Button Not Appearing

If the Configure button doesn't appear in System Settings:

1. Rebuild the system cache:
   ```bash
   kbuildsycoca6
   ```

2. Restart System Settings:
   ```bash
   killall systemsettings
   systemsettings
   ```

3. Verify the configuration module is installed:
   ```bash
   ls -l /usr/lib/qt6/plugins/kstyle_config/kstyle_qt6curve_config.so
   ```

### Configuration Not Saving

If changes don't persist:

1. Check directory permissions:
   ```bash
   ls -ld ~/.config/qt6curve/
   ```

2. Verify the configuration file is writable:
   ```bash
   ls -l ~/.config/qt6curve/stylerc
   ```

3. Check for error messages:
   ```bash
   journalctl --user -f
   ```
   Then open the configuration panel and watch for errors.

### Configuration Module Not Loading

If the configuration panel fails to open:

1. Check if the module can be loaded:
   ```bash
   ldd /usr/lib/qt6/plugins/kstyle_config/kstyle_qt6curve_config.so
   ```

2. Verify all dependencies are satisfied

3. Check System Settings logs:
   ```bash
   journalctl --user -xe | grep -i qt6curve
   ```

## Migrating from QtCurve Qt5

If you want to use your existing QtCurve Qt5 configuration with Qt6Curve:

### Option 1: Copy Configuration

```bash
cp ~/.config/qtcurve/stylerc ~/.config/qt6curve/stylerc
```

### Option 2: Share Configuration Directory

Set Qt6Curve to use the QtCurve directory:
```bash
export QT6CURVE_CONFIG_DIR=~/.config/qtcurve/
```

Add this to your `~/.bashrc` or `~/.profile` to make it permanent.

## Testing the Configuration

To test if Qt6Curve is using your configuration:

1. Open the configuration panel and make a distinctive change (e.g., change button rounding)
2. Apply the changes
3. Open a Qt6 application:
   ```bash
   QT_STYLE_OVERRIDE=Qt6Curve dolphin
   ```
4. Verify your changes are visible

## Integration with KDE

Qt6Curve integrates seamlessly with KDE Plasma:

- **Automatic Detection**: KDE automatically detects Qt6Curve through the theme file
- **Configuration Integration**: The configuration panel appears in System Settings
- **Color Scheme Integration**: Qt6Curve respects KDE color schemes
- **Icon Theme Integration**: Works with your selected icon theme

## Advanced Configuration

### Custom Presets

Qt6Curve supports custom presets stored in:
```
~/.config/qt6curve/
```

You can create multiple configuration files and switch between them.

### Per-Application Settings

Qt6Curve can be configured on a per-application basis using environment variables:
```bash
QT_STYLE_OVERRIDE=Qt6Curve QT6CURVE_CONFIG_DIR=/path/to/app/config/ myapp
```

## Support and Documentation

For more information:

- **Main Documentation**: `/home/www/KDE-trunk/qtcurve/QT6CURVE_REBRAND.md`
- **Source Code**: `/home/www/KDE-trunk/qtcurve/qt6/config/`
- **Configuration Module**: `qtcurveconfig.cpp`

## Summary

The Qt6Curve configuration panel is fully integrated with KDE System Settings and provides comprehensive style customization options. Access it through:

**System Settings → Appearance → Application Style → Qt6Curve → Configure**

All settings are stored in `~/.config/qt6curve/stylerc` and can be easily backed up or shared.
