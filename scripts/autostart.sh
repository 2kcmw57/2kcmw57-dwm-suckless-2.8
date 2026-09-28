```sh
#!/bin/sh

# ============================================================
# KCMW dwm autostart
# ============================================================

# ------------------------------------------------------------
# Environment
# ------------------------------------------------------------

export TERMINAL="alacritty"
export BROWSER="firefox"

# ------------------------------------------------------------
# Start background applications
# ------------------------------------------------------------

# Picom
if ! pgrep -x picom >/dev/null 2>&1; then
    picom --config "$HOME/.config/picom/picom.conf" >/dev/null 2>&1 &
fi

# Dunst
if ! pgrep -x dunst >/dev/null 2>&1; then
    dunst >/dev/null 2>&1 &
fi

# Slstatus
if ! pgrep -x slstatus >/dev/null 2>&1; then
    slstatus >/dev/null 2>&1 &
fi

# sxhkd
if ! pgrep -x sxhkd >/dev/null 2>&1; then
    sxhkd >/dev/null 2>&1 &
fi

# ------------------------------------------------------------
# Wallpaper
# ------------------------------------------------------------

WALLPAPER="$HOME/.local/share/wallpapers/trafalgar-law-3840x2160-18362.jpg"

if [ -f "$WALLPAPER" ] && command -v feh >/dev/null 2>&1; then
    feh --no-fehbg --bg-fill "$WALLPAPER" >/dev/null 2>&1 &
fi

# ------------------------------------------------------------
# Optional startup applications
# ------------------------------------------------------------

# Example:
# alacritty >/dev/null 2>&1 &

# ------------------------------------------------------------
# Finished
# ------------------------------------------------------------

exit 0
```
