# Qt6Curve - AUR Package

Qt6Curve is a Qt6-only build of QtCurve that can coexist with the Qt5 version from the official Arch repositories.

## Key Features

- **Separate from qtcurve**: Uses `libqtcurve-utils-qt6.so` instead of `libqtcurve-utils.so`
- **No conflicts**: Can be installed alongside the official [qtcurve](cci:7://file:///home/www/KDE-trunk/qtcurve:0:0-0:0) package
- **Qt6 native**: Built specifically for Qt6 and KDE Frameworks 6
- **Rebranded**: Appears as "Qt6Curve" in System Settings

## Installation

```bash
git clone [https://aur.archlinux.org/qt6curve-git.git](https://aur.archlinux.org/qt6curve-git.git)
cd qt6curve-git
makepkg -si