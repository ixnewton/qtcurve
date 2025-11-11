# QtCurve Status Bar Widget Fixes

## Problem
QtCurve was not correctly displaying progress bars and combo boxes in status bars (e.g., Dolphin). The widgets were too large/bulky compared to Breeze style, causing poor visual appearance.

## Solution
Added compact sizing logic for widgets when they appear in a status bar context, matching Breeze's approach.

## Changes Made

### File: `qt5/style/qtcurve_api.cpp`

#### 1. Added QStatusBar Include
```cpp
#include <QStatusBar>
```

#### 2. Enhanced CT_ComboBox Sizing (lines ~6362-6399)
- Added detection for status bar parent widgets
- Implemented compact sizing path for status bar context
- Ensures text height is accommodated without clipping: `fontMetrics.height() + 4`
- Maintains standard sizing for normal contexts

**Key Logic:**
```cpp
bool inStatusBar = widget && (qtcCheckType<QStatusBar>(widget->parentWidget()) ||
                              qtcCheckType(widget->parentWidget(), "DolphinStatusBar"));
```

#### 3. Added CT_ProgressBar Case (lines ~6490-6530)
- New case handler for progress bar sizing
- Detects status bar context using same logic as combo boxes
- Compact thickness: 8px (similar to Breeze's 6px)
- Standard thickness: 16px for normal contexts
- Properly handles text visibility - matches font height when text is shown

**Status Bar Sizing:**
- Horizontal with text: `height = max(8px, fontMetrics.height())`
- Horizontal without text: `height = 8px`
- Maintains proper width for progress display

## Benefits

1. **Visual Consistency**: Status bar widgets now match Breeze's compact appearance
2. **Text Readability**: Combo box and progress bar text is no longer clipped
3. **Context Awareness**: Different sizing for status bar vs. normal widget contexts
4. **Backward Compatible**: Standard widgets outside status bars maintain original sizing

## Testing

Test in Dolphin status bar:
- Progress bar during file operations
- View mode combo box selector
- Compare with Breeze style for visual parity

Test in widget test application:
- Verify normal progress bars and combo boxes are unaffected
- Confirm status bar widgets are compact

## Technical Details

- Uses existing `qtcCheckType<QStatusBar>()` helper for parent detection
- Also checks for "DolphinStatusBar" class name for Dolphin-specific status bars
- Leverages `QStyleOption::fontMetrics` for proper text height calculation
- Maintains all existing QtCurve styling features (borders, effects, etc.)
