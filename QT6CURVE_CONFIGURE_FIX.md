# Qt6Curve Configuration Button Fix

## Issue
The Configure/Edit button for Qt6Curve was not appearing in System Settings → Appearance → Application Style.

## Root Cause
The theme descriptor file (`qt6curve.themerc`) was installed in a subdirectory:
```
/usr/share/kstyle/themes/qt6curve/qt6curve.themerc  ❌ WRONG
```

Instead of directly in the themes directory:
```
/usr/share/kstyle/themes/qt6curve.themerc  ✅ CORRECT
```

KDE System Settings looks for theme files directly in `/usr/share/kstyle/themes/`, not in subdirectories.

## Fix Applied

### 1. Updated CMakeLists.txt
**File**: `/home/www/KDE-trunk/qtcurve/qt6/style/CMakeLists.txt`

**Changed line 88 from:**
```cmake
DESTINATION ${KDE_INSTALL_DATADIR}/kstyle/themes/qt6curve
```

**To:**
```cmake
DESTINATION ${KDE_INSTALL_DATADIR}/kstyle/themes
```

### 2. Reinstalled Qt6Curve
```bash
cd /home/www/KDE-trunk/qtcurve/build
make qtcurve-qt6 -j$(nproc)
sudo make install
```

### 3. Removed Old Subdirectory
```bash
sudo rm -rf /usr/share/kstyle/themes/qt6curve/
```

### 4. Rebuilt System Cache
```bash
kbuildsycoca6 --noincremental
```

## Verification

### Check Theme File Location
```bash
ls -l /usr/share/kstyle/themes/qt6curve.themerc
```

Expected output:
```
-rw-r--r-- 1 root root 2.7K Nov 11 17:22 /usr/share/kstyle/themes/qt6curve.themerc
```

### Check ConfigPage Entry
```bash
grep ConfigPage /usr/share/kstyle/themes/qt6curve.themerc
```

Expected output:
```
ConfigPage=kstyle_config/kstyle_qt6curve_config
```

### Check Configuration Module
```bash
ls -l /usr/lib/qt6/plugins/kstyle_config/kstyle_qt6curve_config.so
```

Expected output:
```
-rwxr-xr-x 1 root root 6.5M Nov 11 17:53 /usr/lib/qt6/plugins/kstyle_config/kstyle_qt6curve_config.so
```

## Testing the Fix

### Method 1: System Settings
1. Open **System Settings**
2. Navigate to **Appearance** → **Application Style**
3. Select **Qt6Curve** from the list
4. The **Configure** button should now be **active** ✅
5. Click **Configure** to open the Qt6Curve configuration panel

### Method 2: Command Line
```bash
kcmshell6 style
```
Then select Qt6Curve and click the Configure button.

## Expected Behavior

When you select Qt6Curve in System Settings:
- ✅ The Configure button becomes active
- ✅ Clicking Configure opens the Qt6Curve configuration dialog
- ✅ All configuration tabs are accessible (General, Frames, Shading, Colors, Advanced)
- ✅ Changes can be saved and applied
- ✅ Settings are stored in `~/.config/qt6curve/stylerc`

## Comparison with Other Styles

All working KDE styles have their theme files directly in `/usr/share/kstyle/themes/`:

```bash
$ ls /usr/share/kstyle/themes/
breeze.themerc
oxygen.themerc
qt6curve.themerc  ← Now correct!
qtcurve.themerc
qtcde.themerc
qtcleanlooks.themerc
qtgtk.themerc
qtmotif.themerc
qtplastique.themerc
qtwindows.themerc
```

## Troubleshooting

If the Configure button is still not active:

### 1. Restart System Settings
```bash
killall systemsettings
systemsettings
```

### 2. Rebuild Cache Again
```bash
kbuildsycoca6 --noincremental
```

### 3. Check for Multiple Theme Files
```bash
find /usr/share -name "qt6curve.themerc" 2>/dev/null
```

Should only show:
```
/usr/share/kstyle/themes/qt6curve.themerc
```

### 4. Verify Permissions
```bash
ls -l /usr/share/kstyle/themes/qt6curve.themerc
ls -l /usr/lib/qt6/plugins/kstyle_config/kstyle_qt6curve_config.so
```

Both should be readable by all users.

### 5. Check System Logs
```bash
journalctl --user -f
```

Then open System Settings and select Qt6Curve. Watch for any error messages.

## Summary

The fix ensures that:
1. ✅ Theme file is in the correct location
2. ✅ ConfigPage entry points to the correct module
3. ✅ Configuration module is properly installed
4. ✅ System cache is updated
5. ✅ Configure button is now active in System Settings

The Qt6Curve configuration panel is now fully accessible through System Settings!
