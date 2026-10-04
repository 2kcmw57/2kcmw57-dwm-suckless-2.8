```bash
#!/usr/bin/env bash

# ============================================================
# KCMW Suckless Desktop Installer
# Ubuntu / Debian Linux | dwm + slstatus + st + tabbed
#
# Source: ~/Templates/2kcmw57-dwm+suckless2.8
# ============================================================

set -Eeuo pipefail

# -------------------------
# Configuration
# -------------------------

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"

INSTALL_PREFIX="/usr/local"

DWM_DIR="$SCRIPT_DIR/dwm"
SLSTATUS_DIR="$SCRIPT_DIR/slstatus"
ST_DIR="$SCRIPT_DIR/st"
TABBED_DIR="$SCRIPT_DIR/tabbed"

CONFIG_DIR="$HOME/.config"

BACKUP_DIR="$HOME/.config/suckless-backup-$(date +%Y%m%d-%H%M%S)"

# -------------------------
# Colors
# -------------------------

GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
RESET='\033[0m'

info() {
    echo -e "${BLUE}[INFO]${RESET} $*"
}

success() {
    echo -e "${GREEN}[OK]${RESET} $*"
}

warn() {
    echo -e "${YELLOW}[WARN]${RESET} $*"
}

error() {
    echo -e "${RED}[ERROR]${RESET} $*" >&2
}

# -------------------------
# Error handling
# -------------------------

trap 'error "Installation failed at line $LINENO"' ERR

# -------------------------
# Check Ubuntu / Debian
# -------------------------

if [[ ! -f /etc/os-release ]]; then
    error "Cannot determine operating system."
    exit 1
fi

source /etc/os-release

case "${ID:-}" in
    ubuntu|debian)
        success "Detected $PRETTY_NAME"
        ;;
    linuxmint|pop|zorin|elementary)
        success "Detected Ubuntu/Debian-based system: $PRETTY_NAME"
        ;;
    *)
        warn "This installer is intended for Ubuntu/Debian-based Linux."
        read -rp "Continue anyway? [y/N]: " answer

        [[ "$answer" =~ ^[Yy]$ ]] || exit 1
        ;;
esac

# -------------------------
# Check source directory
# -------------------------

if [[ ! -d "$SCRIPT_DIR" ]]; then
    error "Source directory not found."
    exit 1
fi

info "Source directory: $SCRIPT_DIR"

# -------------------------
# Check required projects
# -------------------------

for dir in "$DWM_DIR" "$SLSTATUS_DIR" "$ST_DIR" "$TABBED_DIR"; do
    if [[ ! -f "$dir/Makefile" ]]; then
        error "Missing Makefile: $dir"
        exit 1
    fi
done

success "All Suckless projects found."

# -------------------------
# Install dependencies
# -------------------------

info "Updating package lists..."

sudo apt update

info "Installing build dependencies..."

sudo apt install -y \
    build-essential \
    gcc \
    make \
    git \
    pkg-config \
    libimlib2-dev \
    thunar \
    geany \
    libx11-dev \
    libxft-dev \
    libxinerama-dev \
    libxrender-dev \
    libxrandr-dev \
    libxext-dev \
    libxfixes-dev \
    libxdamage-dev \
    libxcomposite-dev \
    libxcursor-dev \
    libxres-dev \
    libfreetype6-dev \
    libfontconfig1-dev \
    libdrm-dev \
    libnotify-bin \
    dunst \
    picom \
    rofi \
    sxhkd \
    feh \
    xserver-xorg \
    xinit \
    xauth

success "Dependencies installed."

# -------------------------
# Backup existing configs
# -------------------------

info "Creating configuration backup..."

mkdir -p "$BACKUP_DIR"

for item in \
    "$CONFIG_DIR/dunst" \
    "$CONFIG_DIR/rofi" \
    "$CONFIG_DIR/picom" \
    "$CONFIG_DIR/sxhkd" \
    "$CONFIG_DIR/suckless"
do
    if [[ -e "$item" ]]; then
        cp -a "$item" "$BACKUP_DIR/"
    fi
done

success "Backup created: $BACKUP_DIR"

# -------------------------
# Build and install helper
# -------------------------

build_install() {

    local name="$1"
    local dir="$2"

    if [[ ! -d "$dir" ]]; then
        warn "$name directory missing. Skipping."
        return
    fi

    info "Building $name..."

    make -C "$dir" clean || true

    make -C "$dir"

    sudo make -C "$dir" PREFIX="$INSTALL_PREFIX" install

    success "$name installed."
}

# -------------------------
# Build Suckless programs
# -------------------------

build_install "dwm" "$DWM_DIR"

build_install "slstatus" "$SLSTATUS_DIR"

build_install "st" "$ST_DIR"

build_install "tabbed" "$TABBED_DIR"

# -------------------------
# Install configuration files
# -------------------------

info "Installing configuration files..."

mkdir -p \
    "$CONFIG_DIR/dunst" \
    "$CONFIG_DIR/rofi" \
    "$CONFIG_DIR/picom" \
    "$CONFIG_DIR/sxhkd" \
    "$CONFIG_DIR/suckless"

# Dunst
if [[ -f "$SCRIPT_DIR/dunst/dunstrc" ]]; then
    cp "$SCRIPT_DIR/dunst/dunstrc" \
        "$CONFIG_DIR/dunst/dunstrc"
fi

# Rofi
for file in "$SCRIPT_DIR/rofi"/*.rasi; do
    [[ -f "$file" ]] || continue
    cp "$file" "$CONFIG_DIR/rofi/"
done

# Picom
if [[ -f "$SCRIPT_DIR/picom/picom.conf" ]]; then
    cp "$SCRIPT_DIR/picom/picom.conf" \
        "$CONFIG_DIR/picom/picom.conf"
fi

# sxhkd
if [[ -f "$SCRIPT_DIR/sxhkd/sxhkdrc" ]]; then
    cp "$SCRIPT_DIR/sxhkd/sxhkdrc" \
        "$CONFIG_DIR/sxhkd/sxhkdrc"
fi

success "Configuration files installed."

# -------------------------
# Install themes
# -------------------------

info "Installing dwm themes..."

THEME_DEST="$CONFIG_DIR/suckless/themes"

mkdir -p "$THEME_DEST"

if [[ -d "$DWM_DIR/themes" ]]; then
    cp -a "$DWM_DIR/themes/." "$THEME_DEST/"
fi

success "Themes installed."

# -------------------------
# Install scripts
# -------------------------

info "Installing helper scripts..."

SCRIPT_DEST="$HOME/.local/bin"

mkdir -p "$SCRIPT_DEST"

if [[ -d "$SCRIPT_DIR/scripts" ]]; then

    for script in "$SCRIPT_DIR/scripts"/*; do

        [[ -f "$script" ]] || continue

        cp "$script" "$SCRIPT_DEST/"

        chmod +x "$SCRIPT_DEST/$(basename "$script")"

    done

fi

success "Helper scripts installed."

# -------------------------
# Install wallpaper
# -------------------------

info "Installing wallpaper..."

WALLPAPER_DEST="$HOME/.local/share/wallpapers"

mkdir -p "$WALLPAPER_DEST"

if [[ -d "$SCRIPT_DIR/wallpaper" ]]; then

    cp -a "$SCRIPT_DIR/wallpaper/." \
        "$WALLPAPER_DEST/"

fi

success "Wallpaper installed."

# -------------------------
# Create autostart directory
# -------------------------

mkdir -p "$CONFIG_DIR/dwm"

# Copy autostart script
if [[ -f "$SCRIPT_DIR/scripts/autostart.sh" ]]; then

    cp "$SCRIPT_DIR/scripts/autostart.sh" \
        "$CONFIG_DIR/dwm/autostart.sh"

    chmod +x "$CONFIG_DIR/dwm/autostart.sh"

fi

# -------------------------
# Update PATH
# -------------------------

if ! grep -qF 'export PATH="$HOME/.local/bin:$PATH"' \
    "$HOME/.bashrc" 2>/dev/null; then

    echo 'export PATH="$HOME/.local/bin:$PATH"' >> "$HOME/.bashrc"

fi

# -------------------------
# Create dwm session
# -------------------------

info "Creating dwm session file..."

sudo mkdir -p /usr/share/xsessions

sudo tee /usr/share/xsessions/dwm.desktop > /dev/null <<EOF
[Desktop Entry]
Name=dwm
Comment=Dynamic Window Manager
Exec=$INSTALL_PREFIX/bin/dwm
TryExec=$INSTALL_PREFIX/bin/dwm
Type=Application
DesktopNames=dwm
EOF

success "dwm session created."

# -------------------------
# Update desktop database
# -------------------------

if command -v update-desktop-database >/dev/null 2>&1; then
    sudo update-desktop-database /usr/share/applications 2>/dev/null || true
fi

# -------------------------
# Verify installation
# -------------------------

info "Verifying installed programs..."

for program in dwm slstatus st tabbed; do

    if command -v "$program" >/dev/null 2>&1; then
        success "$program: $(command -v "$program")"
    else
        warn "$program was not found in PATH."
    fi

done

# -------------------------
# Finish
# -------------------------

echo
echo "============================================================"
echo -e "${GREEN} KCMW Suckless installation complete!${RESET}"
echo "============================================================"
echo
echo "Installed:"
echo "  dwm"
echo "  slstatus"
echo "  st"
echo "  tabbed"
echo "  Rofi configuration"
echo "  Dunst configuration"
echo "  Picom configuration"
echo "  sxhkd configuration"
echo "  Themes"
echo "  Helper scripts"
echo "  Wallpaper"
echo
echo "Backup:"
echo "  $BACKUP_DIR"
echo
echo "Next steps:"
echo "  1. Log out of GNOME."
echo "  2. Select dwm from the login screen."
echo "  3. Log in."
echo
echo "============================================================"
```
