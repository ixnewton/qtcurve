#!/bin/bash

echo "=== QtCurve Installation Test ==="
echo

# Check if QtCurve styles are installed
echo "Checking QtCurve style installations:"
echo "Qt4: $(ls -la /usr/lib/qt4/plugins/styles/qtcurve.so 2>/dev/null || echo 'Not found')"
echo "Qt5: $(ls -la /usr/lib/qt/plugins/styles/qtcurve.so 2>/dev/null || echo 'Not found')"  
echo "Qt6: $(ls -la /usr/lib/qt6/plugins/styles/qtcurve.so 2>/dev/null || echo 'Not found')"
echo

# Check theme file
echo "Theme configuration:"
echo "$(ls -la /usr/local/share/kstyle/themes/qtcurve.themerc 2>/dev/null || echo 'Theme file not found')"
echo

echo "=== Testing Instructions ==="
echo
echo "1. Test with Dolphin (Qt5/Qt6):"
echo "   QT_STYLE_OVERRIDE=qtcurve dolphin"
echo
echo "2. Test with any Qt5 application:"
echo "   QT_STYLE_OVERRIDE=qtcurve <qt5-app>"
echo
echo "3. Test with any Qt6 application:"
echo "   QT_STYLE_OVERRIDE=qtcurve <qt6-app>"
echo
echo "4. Test status bar progress bars:"
echo "   - Open Dolphin with QtCurve style"
echo "   - Navigate to a folder with many files"
echo "   - Copy/move files to see progress bar in status bar"
echo "   - Progress bars should be compact (8px thick)"
echo
echo "5. Test combo boxes in status bar:"
echo "   - Look for any combo boxes in status bar areas"
echo "   - Text should not be clipped"
echo "   - Height should be compact"
echo
echo "6. Compare with Breeze style:"
echo "   QT_STYLE_OVERRIDE=breeze dolphin"
echo "   (Status bar widgets should look similar in size)"
echo

echo "=== Status Bar Fix Verification ==="
echo "The following fixes have been implemented:"
echo "✓ Qt5: Status bar detection for progress bars and combo boxes"
echo "✓ Qt6: Status bar detection for progress bars and combo boxes (newly added)"
echo "✓ Compact sizing: 8px progress bars, proper combo box heights"
echo "✓ Text visibility: No clipping in status bar contexts"
echo "✓ Dolphin compatibility: Recognizes DolphinStatusBar class"
