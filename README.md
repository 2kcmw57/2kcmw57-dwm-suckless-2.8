
# 2kcmw57-dwm-suckless-2.8

<p align="center">
  <strong>A customized DWM + Suckless Linux desktop environment.</strong>
</p>

<p align="center">
  Lightweight • Keyboard-driven • Modular • Themeable • X11
</p>

<p align="center">
  <a href="https://github.com/2kcmw57/2kcmw57-dwm-suckless-2.8">Repository</a>
  •
  <a href="https://github.com/sponsors/2kcmw57">Sponsor</a>
</p>

---

## 📸 Overview ## https://github.com/2kcmw57/2kcmw57-dwm-suckless-2.8/blob/main/Examples/Example%201.png

**2kcmw57-dwm-suckless-2.8** is my personal Linux desktop configuration made by me Kgotso Chidera Molefe Wisdom built around the [Suckless](https://suckless.org/) philosophy.

The project combines a customized **DWM** window manager with Suckless utilities and additional desktop tools such as **slstatus, st, tabbed, Rofi, Dunst, Picom and sxhkd**.

The goal is a desktop that is:

* ⚡ Lightweight and responsive
* ⌨️ Keyboard-driven
* 🧩 Modular
* 🎨 Themeable
* 🔧 Easy to customize
* 🖥️ Focused on the X11 workflow
* 📦 Reproducible through configuration and installation scripts

---

## ✨ Features

### DWM

The DWM configuration includes custom functionality and a collection of patches covering areas such as:

* Vanity gaps
* Multiple layouts
* Stack manipulation
* Scratch-tag windows
* Scratchpads
* Named scratchpads
* Per-tag configuration
* Sticky windows
* Window centering
* Fullscreen support
* Fake fullscreen
* Multi-monitor support
* EWMH support
* Status bar improvements
* Xresources support
* DWM restart/persistence functionality
* Custom autostart functionality

### Desktop utilities

| Component    | Purpose                        |
| ------------ | ------------------------------ |
| **dwm**      | Window manager                 |
| **slstatus** | Status bar                     |
| **st**       | Suckless terminal              |
| **tabbed**   | Tabbed X11 container           |
| **Rofi**     | Application launcher and menus |
| **Dunst**    | Notifications                  |
| **Picom**    | X11 compositor                 |
| **sxhkd**    | Global hotkeys                 |

---

## 🎨 Themes

The repository includes multiple coordinated themes for DWM and Rofi.

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

Theme files are located in:

```text
dwm/themes/
```

Most themes contain:

```text
colors.rasi
dwm.xresources
theme.conf
```

This allows the DWM and Rofi appearance to be coordinated from the same theme collection.

---

## 🪟 DWM Patches

The repository contains the following patch files:

```text
dwm-alwayscenter
dwm-attachbottom
dwm-cool_autostart
dwm-ewmhtags
dwm-fakefullscreen
dwm-focusadjacenttag
dwm-focusonnetactive
dwm-fullscreen
dwm-movestack
dwm-namedscratchpads
dwm-pertag
dwm-preserveonrestart
dwm-restartsig
dwm-scratchtagwins
dwm-status2d-barpadding-systray
dwm-statusallmons
dwm-sticky
dwm-togglefloatingcenter
dwm-vanitygaps
dwm-windowfollow
dwm-xresources
```

They are stored in:

```text
dwm/patches/
```

> **Note:** Some functionality from these patches has already been integrated into the current DWM source. Do not blindly apply every patch to the existing source tree.

---

## 📊 Slstatus

The customized `slstatus` configuration provides system information through a collection of components.

Included components cover areas such as:

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

## 🖥️ ST

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

Patch files are located in:

```text
st/patches/
```

The desktop configuration can use **Alacritty** as the preferred terminal while the customized `st` source remains included as part of the Suckless environment.

---

## 🗂️ Tabbed

The repository includes Suckless `tabbed`, providing a lightweight tabbed container for X11 applications.

```text
tabbed/
```

---

## 🚀 Rofi

Rofi is used for application launching and desktop menus.

Configuration files:

```text
rofi/
├── colors.rasi
├── config.rasi
├── keybinds.rasi
├── power.rasi
└── window.rasi
```

---

## 🔔 Dunst

Dunst provides desktop notifications.

Configuration:

```text
dunst/dunstrc
```

---

## 🪟 Picom

Picom provides X11 compositing.

Configuration:

```text
picom/picom.conf
```

Depending on the configuration, Picom can provide effects such as:

* Transparency
* Shadows
* Fading
* Window compositing

---

## ⌨️ SXHKD

`sxhkd` provides additional global keyboard shortcuts outside of DWM's native keybindings.

Configuration:

```text
sxhkd/sxhkdrc
```

---

## 🛠️ Scripts

Custom utilities are stored in:

```text
scripts/
```

Current scripts include:

```text
autostart.sh
changevolume
power
```

### `autostart.sh`

Used to start the desktop services and applications required by the environment.

### `changevolume`

Provides volume control and desktop notifications through Dunst.

### `power`

Provides power-management actions through the desktop environment.

---

## 🖼️ Wallpaper

The repository includes a 4K wallpaper:

```text
wallpaper/
└── trafalgar-law-3840x2160-18362.jpg
```

---

## 📁 Repository Structure

```text
2kcmw57-dwm-suckless-2.8/
│
├── ArchLinux.sh
├── Fedora 44.sh
├── Ubuntu26.04.sh
├── README.md
│
├── dunst/
├── dwm/
│   ├── patches/
│   └── themes/
│
├── picom/
├── rofi/
├── scripts/
├── slstatus/
│   └── components/
├── st/
│   └── patches/
├── sxhkd/
├── tabbed/
└── wallpaper/
```

---

## 💿 Supported Distributions

Installation scripts are included for:

* Arch Linux
* Fedora 44
* Ubuntu 26.04

Installers:

```text
ArchLinux.sh
Fedora 44.sh
Ubuntu26.04.sh
```

> Always review an installation script before running it on your system.

---

⚙️ Setup Scripts

The repository includes installation scripts for several Linux distributions.

### Fedora 44
```bash
chmod +x Fedora44.sh
./Fedora44.sh
```

### Ubuntu 26.04
```bash
chmod +x Ubuntu26.04.sh
./Ubuntu26.04.sh
```

### Arch Linux
```bash
chmod +x ArchLinux.sh
./ArchLinux.sh
```

## 🔨 Building the Suckless Components

Each Suckless component can be built from its respective directory.

### DWM

```bash
cd dwm
make
sudo make install
```

### Slstatus

```bash
cd slstatus
make
sudo make install
```

### ST

```bash
cd st
make
sudo make install
```

### Tabbed

```bash
cd tabbed
make
sudo make install
```

---

## ⚙️ Customization

The main configuration files are:

```text
dwm/config.h
slstatus/config.h
st/config.h
tabbed/config.h
```

Source modifications can be found throughout the respective component directories.

For DWM, themes and patches are located under:

```text
dwm/themes/
dwm/patches/
```

Configuration files can be modified and rebuilt according to the normal Suckless workflow.

---

## ⌨️ Keybindings

DWM keyboard bindings are documented in:

```text
dwm/keybindings.txt
```

Additional desktop shortcuts are configured through:

```text
sxhkd/sxhkdrc
```

---

## 🔄 Updating

Because this is a customized Suckless setup, updates should be performed carefully.

Before changing the source:

1. Back up `config.h`.
2. Review custom source modifications.
3. Review the patches in `dwm/patches/`.
4. Check compatibility with the current DWM source.
5. Rebuild the affected component.
6. Test the desktop before replacing the installed binary.

Do not blindly apply all patches to an already modified source tree.

---

## 🧹 Clean Builds

To clean and rebuild a component:

```bash
make clean
make
```

For example:

```bash
cd dwm
make clean
make
```

---

## 🧠 Philosophy

This project follows the general philosophy behind the Suckless ecosystem:

> Keep software small, simple, modular and controlled by the user.

Instead of relying on a large desktop environment, this setup combines several small programs that each perform a specific role.

The result is a desktop environment assembled from components that can be independently configured, rebuilt and replaced.

---

## ❤️ Support the Project

If you find this project useful and would like to support its continued development, you can sponsor me through GitHub Sponsors:

<p align="center">
  <a href="https://github.com/sponsors/2kcmw57">
    <strong>❤️ Sponsor 2kcmw57</strong>
  </a>
</p>

Your support helps with continued development, maintenance, experimentation and improvements to this DWM + Suckless desktop environment.

Every sponsorship is appreciated.

---

## 📜 License

This repository contains software based on multiple Suckless projects.

Individual components retain their respective upstream licenses.

See the `LICENSE` files inside the relevant project directories for licensing information.

In particular, review:

```text
dwm/LICENSE
st/LICENSE
slstatus/LICENSE
tabbed/LICENSE
```

Patch authors and upstream projects should be credited according to their respective licenses.

---

## 👤 2kcmw57

**KCMW57 DWM + Suckless Desktop**

A personal Linux desktop environment built around:

```text
             ┌─────────────┐
             │     DWM     │
             └──────┬──────┘
                    │
       ┌────────────┼────────────┐
       │            │            │
   slstatus         st        tabbed
       │
       ├── Rofi
       ├── Dunst
       ├── Picom
       ├── SXHKD
       ├── Themes
       ├── Scripts
       └── Wallpapers
```

Built for a **fast, minimal, keyboard-driven and highly customizable Linux workflow**.

---

### ⭐ If you find it useful

Consider giving the repository a **star** and, if you'd like to support continued development, consider becoming a **GitHub Sponsor**.

**Repository:**
https://github.com/2kcmw57/2kcmw57-dwm-suckless-2.8

**Sponsors:**
https://github.com/sponsors/2kcmw57
