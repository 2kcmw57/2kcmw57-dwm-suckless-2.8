Yes — you mean a **proper GitHub-style `README.md` for the whole `2kcmw57-dwm+suckless2.8` project**, not a file-by-file inventory.

Here is a cleaner version you can put directly at:

`2kcmw57-dwm+suckless2.8/README.md`

# 2kcmw57-dwm+suckless2.8

A personal, modular and highly customized **Suckless-based Linux desktop environment** built around `dwm`.

This setup combines a patched and customized `dwm` with `slstatus`, `st`, `tabbed`, `Rofi`, `Dunst`, `Picom`, `sxhkd`, custom shell utilities, theme management, and wallpaper automation.

The goal is to keep the desktop **minimal, fast, keyboard-driven and highly configurable** while providing the features normally expected from a complete desktop environment.

---

## ✨ Features

* 🪟 Customized **dwm**
* 📐 Vanity gaps and additional layouts
* 🖥️ Multi-monitor support
* 🏷️ Per-tag configuration
* 📌 Sticky windows
* 🎯 Window centering
* 🔲 Fullscreen support
* 📝 Scratchpads and scratch-tag windows
* 🔄 DWM restart/persistence support
* 📊 Customized **slstatus**
* 🖥️ Customized **st**
* 🗂️ **tabbed**
* 🚀 **Rofi** application launcher
* 🔔 **Dunst** notifications
* 🪟 **Picom** compositor
* ⌨️ **sxhkd** global hotkeys
* 🎨 Multiple desktop themes
* 🖼️ Wallpaper automation
* 🔧 Custom shell utilities
* 📦 Fedora installation script
* 🌈 Xresources theme support
* ⚡ Lightweight X11 workflow

---

## 📁 Project Structure

```text
2kcmw57-dwm+suckless2.8/
├── dunst/
│   └── dunstrc
│
├── dwm/
│   ├── config.h
│   ├── config.def.h
│   ├── config.mk
│   ├── dwm.c
│   ├── drw.c
│   ├── drw.h
│   ├── dwmtabs.c
│   ├── movestack.c
│   ├── scratchtagwins.c
│   ├── transient.c
│   ├── vanitygaps.c
│   ├── patches/
│   └── themes/
│
├── picom/
│   └── picom.conf
│
├── rofi/
│   ├── colors.rasi
│   ├── config.rasi
│   ├── keybinds.rasi
│   ├── power.rasi
│   └── window.rasi
│
├── scripts/
│   ├── autostart.sh
│   ├── changevolume
│   ├── dwm-layout-menu.sh
│   ├── dwm-thememenu
│   ├── gen-keybinds
│   ├── help
│   └── power
│
├── slstatus/
│   └── components/
│
├── st/
│   └── patches/
│
├── sxhkd/
│   └── sxhkdrc
│
├── tabbed/
│
├── wallpaper/
│   └── trafalgar-law-3840x2160-18362.jpg
│
├── Fedora.sh
│
└── README.md
```

---

# 🪟 DWM

The heart of the desktop is a customized version of **dwm**.

The configuration includes a collection of patches and custom source modifications for additional window-management functionality.

### Included functionality

* Vanity gaps
* Multiple layouts
* Stack manipulation
* Scratchpads
* Scratch-tag windows
* Named scratchpads
* Per-tag configuration
* Sticky windows
* Fullscreen
* Fake fullscreen
* Window centering
* Window following
* Adjacent tag focus
* EWMH tags
* Multi-monitor status bars
* System tray
* Status2D
* Bar padding
* Xresources
* Restart persistence
* Signal-based restart
* Custom autostart

---

# 🧩 DWM Patches

The repository contains the following DWM patches:

```text
alwayscenter
attachbottom
cool_autostart
ewmhtags
fakefullscreen
focusadjacenttag
focusonnetactive
fullscreen
movestack
namedscratchpads
pertag
preserveonrestart
restartsig
scratchtagwins
status2d-barpadding-systray
statusallmons
sticky
togglefloatingcenter
vanitygaps
windowfollow
xresources
```

Patch files are stored in:

```text
dwm/patches/
```

Some functionality is already integrated into the current source tree. **Do not blindly reapply patches** to the existing source.

---

# 📊 Slstatus

`slstatus` is used as the DWM status bar.

The configuration contains custom components for system information such as:

```text
CPU
RAM
Battery
Disk
Temperature
Volume
Wi-Fi
Network speed
IP address
Kernel
Hostname
Uptime
Load average
Swap
Date / time
Keyboard indicators
Keymap
File counts
Entropy
User
```

Custom components are located in:

```text
slstatus/components/
```

---

# 🖥️ ST

A customized version of the Suckless terminal is included.

### ST patches

```text
alpha
anysize
bold-is-not-bright
clipboard
delkey
font2
scrollback
scrollback-mouse
xresources
xresources-signal-reloading
```

Patch files:

```text
st/patches/
```

The desktop configuration currently uses **Alacritty** as the preferred terminal, while the customized `st` build remains available as the native Suckless terminal.

---

# 🗂️ Tabbed

The repository includes Suckless `tabbed`.

`tabbed` provides a lightweight tabbed container for X11 applications.

```text
tabbed/
```

---

# 🚀 Rofi

Rofi is used for application launching, window switching, power management and theme selection.

Configuration:

```text
rofi/
├── colors.rasi
├── config.rasi
├── keybinds.rasi
├── power.rasi
└── window.rasi
```

Custom scripts provide integration with DWM:

```text
scripts/dwm-layout-menu.sh
scripts/dwm-thememenu
scripts/power
```

---

# 🔔 Dunst

Dunst provides desktop notifications.

Configuration:

```text
dunst/dunstrc
```

Installed configuration:

```text
~/.config/dunst/dunstrc
```

---

# 🪟 Picom

Picom provides X11 compositing effects.

Configuration:

```text
picom/picom.conf
```

Installed configuration:

```text
~/.config/picom/picom.conf
```

The compositor can provide:

* Transparency
* Shadows
* Fading
* Window effects
* Compositing

---

# ⌨️ SXHKD

`sxhkd` provides additional global keyboard shortcuts outside of DWM's native keybindings.

Configuration:

```text
sxhkd/sxhkdrc
```

---

# 🎨 Themes

The project includes a collection of coordinated DWM and Rofi themes.

Available themes:

```text
Catppuccin
Doom One
Dracula
Everforest
GitHub Dark
Gruvbox
Kanagawa
Monokai
Moonfly
Nord
Retro
Rose Pine
Tundra
```

Theme files are stored under:

```text
dwm/themes/
```

Most themes contain:

```text
colors.rasi
dwm.xresources
theme.conf
```

This allows DWM and Rofi to share a consistent color palette.

---

# 🛠️ Custom Scripts

The `scripts/` directory contains utilities used by the desktop environment.

### `autostart.sh`

Starts the desktop environment services:

```text
Picom
Dunst
slstatus
sxhkd
Wallpaper
```

It also defines environment variables such as:

```sh
TERMINAL=alacritty
BROWSER=firefox
```

### `changevolume`

Controls system volume.

### `dwm-layout-menu.sh`

Provides a Rofi-based DWM layout selector.

### `dwm-thememenu`

Provides theme selection.

### `gen-keybinds`

Generates or assists with DWM keyboard-binding information.

### `help`

Displays available desktop commands and shortcuts.

### `power`

Provides system power-management options.

---

# 🖼️ Wallpaper

The project includes a 4K Trafalgar Law wallpaper:

```text
wallpaper/
└── trafalgar-law-3840x2160-18362.jpg
```

The autostart configuration uses `feh` to load the wallpaper automatically.

Expected installation location:

```text
~/.local/share/wallpapers/
```

---

# ⚙️ Installation

The project includes a Fedora installation script:

```text
Fedora.sh
```

Make it executable:

```bash
chmod +x Fedora.sh
```

Run:

```bash
./Fedora.sh
```

The installer is intended to install and configure the components contained in this repository.

---

# 🔨 Manual Installation

Individual Suckless components can also be built manually.

## DWM

```bash
cd dwm
make
sudo make install
```

## Slstatus

```bash
cd slstatus
make
sudo make install
```

## ST

```bash
cd st
make
sudo make install
```

## Tabbed

```bash
cd tabbed
make
sudo make install
```

---

# 📂 Configuration Installation

Create the required directories:

```bash
mkdir -p ~/.config/{dunst,picom,rofi,sxhkd}
mkdir -p ~/.local/bin
mkdir -p ~/.local/share/wallpapers
```

Copy configurations:

```bash
cp dunst/dunstrc ~/.config/dunst/
cp picom/picom.conf ~/.config/picom/
cp rofi/*.rasi ~/.config/rofi/
cp sxhkd/sxhkdrc ~/.config/sxhkd/
```

Install scripts:

```bash
cp scripts/* ~/.local/bin/
chmod +x ~/.local/bin/*
```

Install wallpaper:

```bash
cp wallpaper/* ~/.local/share/wallpapers/
```

---

# 🚀 DWM Autostart

The DWM autostart script is:

```text
scripts/autostart.sh
```

The preferred installation path is:

```text
~/.local/bin/autostart.sh
```

The DWM configuration can launch it through the `cool_autostart` functionality.

Example:

```c
static const char *const autostart[] = {
    "sh", "-c", "exec \"$HOME/.local/bin/autostart.sh\"", NULL,
    NULL
};
```

---

# 🧹 Clean Builds

To perform a clean DWM build:

```bash
cd dwm
make clean
make
```

For Slstatus:

```bash
cd slstatus
make clean
make
```

For ST:

```bash
cd st
make clean
make
```

For Tabbed:

```bash
cd tabbed
make clean
make
```

---

# ⚠️ Configuration Notes

This repository contains customized Suckless source code.

Important files include:

```text
dwm/config.h
dwm/dwm.c
slstatus/config.h
st/config.h
tabbed/config.h
```

These files contain local modifications and should be backed up before making major changes.

The repository also contains historical files such as:

```text
*.orig
*.2
```

These should be treated as backups/reference files rather than automatically replacing the active configuration.

---

# 🔄 Updating DWM

Before updating or replacing DWM source:

1. Back up `config.h`.
2. Back up custom `.c` files.
3. Review the patches.
4. Compare the new DWM source against the current source.
5. Reapply only the functionality that is not already integrated.
6. Rebuild and test.

Do not blindly apply every patch in `dwm/patches/`.

---

# 💻 Environment

This configuration is primarily designed around:

```text
OS              Fedora Linux
Display Server  X11
Window Manager  dwm
Terminal        Alacritty / st
Launcher        Rofi
Notifications   Dunst
Compositor      Picom
Hotkeys         sxhkd
Status Bar      slstatus
Wallpaper       feh
```

---

# 🎯 Philosophy

This project follows the general philosophy of the Suckless ecosystem:

> Keep the system lightweight, simple, modular and under direct user control.

Rather than relying on a large desktop environment, functionality is provided by small independent programs that work together.

The result is a desktop that can be rebuilt, modified and maintained from source.

---

# 📜 License

Individual components retain their original licenses.

DWM, ST, slstatus and tabbed are based on software from the Suckless project and retain their respective licenses.

See the `LICENSE` files included in each component for details.

---

# 👤 Project

**2kcmw57-dwm+suckless2.8**

A personal customized Suckless desktop environment.

```text
dwm
├── slstatus
├── st
├── tabbed
├── rofi
├── dunst
├── picom
├── sxhkd
├── scripts
├── themes
└── wallpaper
```

**Built for a fast, minimal and highly customizable Linux workflow.**
