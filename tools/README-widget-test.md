# QtCurve Widget Test Application

## Overview

The `qtcurve-widget-test` application is a comprehensive Qt6 test tool that displays various styled widgets to help test and verify QtCurve theme styling.

## Features

The application includes multiple tabs showcasing different widget categories:

### 1. Buttons Tab
- **Push Buttons**: Normal, Default, Disabled, and Flat variants
- **Tool Buttons**: Standard, Raised, and Auto-raise variants
- **Check Boxes**: Unchecked, Checked, Partially Checked, and Disabled states
- **Radio Buttons**: Multiple options with enabled/disabled states

### 2. Inputs Tab
- **Line Edits**: Normal, with text, disabled, and password fields
- **Combo Boxes**: Standard dropdown (including Filelight, Baloo, Disk Usage options), editable combo, and disabled combo
- **Spin Boxes**: Integer and double precision spin boxes
- **Text Edit**: Multi-line text editor

### 3. Progress & Sliders Tab
- **Progress Bars**: Various completion levels (25%, 50%, 75%)
- **Animated Progress**: Live updating progress bar
- **Busy Indicator**: Indeterminate progress bar
- **Sliders**: Horizontal and vertical sliders with tick marks
- **Dial**: Rotary control widget
- **Scroll Bars**: Horizontal and vertical scroll bars

### 4. Views Tab
- **List Widget**: Scrollable list with alternating row colors
- **Tree Widget**: Hierarchical tree view with expandable items
- **Table Widget**: Grid view with multiple columns and rows

### 5. Containers Tab
- **Group Boxes**: Standard and checkable group boxes
- **Splitter**: Resizable split panes

### Additional UI Elements
- **Menu Bar**: File, Edit, View, and Help menus with keyboard shortcuts
- **Tool Bar**: Common actions with separator groups
- **Status Bar**: Includes a progress bar showing "Disk Usage" (similar to Dolphin)

## Building

The test application is automatically built when QtCurve is compiled with Qt6 support:

```bash
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make qtcurve-widget-test
```

## Running

### With QtCurve Style
```bash
./tools/qtcurve-widget-test -style QtCurve
```

### With System Default Style
```bash
./tools/qtcurve-widget-test
```

### Compare Styles
Open multiple instances with different styles:
```bash
./tools/qtcurve-widget-test -style QtCurve &
./tools/qtcurve-widget-test -style Breeze &
./tools/qtcurve-widget-test -style Fusion &
```

## Use Cases

1. **Visual Testing**: Verify QtCurve renders all widget types correctly
2. **Theme Development**: Test theme changes in real-time
3. **Comparison**: Compare QtCurve with other Qt styles side-by-side
4. **Bug Reporting**: Identify and document rendering issues
5. **Performance Testing**: Check animation smoothness and responsiveness

## Testing Specific Features

### Dolphin-like Elements
- **Status Bar Progress**: Bottom-right corner shows a progress bar similar to Dolphin's disk usage indicator
- **Combo Box**: The "Select View" combo box mimics Dolphin's view selector (Filelight, Baloo, etc.)

### Interactive Elements
- **Animated Progress**: Automatically cycles from 0-100% to test progress bar rendering
- **Hover Effects**: Move mouse over buttons, sliders, and other widgets to test hover states
- **Focus States**: Tab through widgets to test focus indicators
- **Disabled States**: Various disabled widgets show how QtCurve handles inactive elements

## Tips

- Use the **View** menu to toggle toolbar and statusbar visibility
- The application demonstrates both light and dark theme compatibility
- All widgets support keyboard navigation
- Progress bars update in real-time to show animation smoothness

## Related Files

- Source: `tools/qtcurve-widget-test.cpp`
- CMake: `tools/CMakeLists.txt`
- Binary: `build/tools/qtcurve-widget-test`
