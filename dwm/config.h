/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

/* ==================================================
   BAR SETTINGS
   ================================================== */

static const int bar_height   = 28;  /* Bar height */
static const int horizpadbar  = 12;  /* Left/right padding */
static const int vertpadbar   = 6;  /* Top/bottom padding */

static const int vertpadtab   = 35;
static const int horizpadtabi = 15;
static const int horizpadtabo = 15;

/*======================
 * Appearance
 *======================*/

/* Bar */
static const int showbar    = 1;
static const int topbar     = 1;
static const int vertpad    = 8;
static const int sidepad    = 8;

/* Borders */
static const unsigned int borderpx = 4;
static const unsigned int snap     = 32;

/* Systray */
static const int showsystray             = 1;
static const int statusallmons           = 1;
static const unsigned int systraypinning = 0;
static const unsigned int systrayonleft  = 0;
static const unsigned int systrayspacing = 6;
static const int systraypinningfailfirst = 1;

/* Gaps */
static const unsigned int gappih = 8,
                          gappiv = 8,
                          gappoh = 8,
                          gappov = 8;
static int smartgaps = 0;


/* Fonts */
static const char *fonts[] = {
    "Iosevka:style=Medium:size=12",
    "Iosevka:style=Bold:size=12",
    "JetBrainsMono Nerd Font Mono:style=Medium:size=20",
    "JetBrainsMono Nerd Font Mono:style=Bold:size=14"
};


static const char *const autostart[] = {
    "sh", "-c", "exec \"$HOME/.local/bin/autostart.sh\"", NULL,
    NULL
};

/* ==================================================
   THEME / COLORS
   ================================================== */
#include "themes/tundra.h"

static const char *colors[][3] = {
    /*            FG         BG         Border       Comment */
    

    [SchemeNorm]  = { "#D4F7F1", "#0A1012", "#223338" },
    [SchemeSel]   = { "#081416", "#00CFA4", "#00E6B8" },
    [SchemeTitle] = { "#FFFFFF", "#0A1012", "#0A1012" },

    [TabSel]      = { "#081416", "#00CFA4", "#00E6B8" },
    [TabNorm]     = { "#D4F7F1", "#0A1012", "#0A1012" },

   /* Tags */
[SchemeTag]  = { "#FFFFFF", "#1E1E2E", "#1E1E2E" }, // Default
[SchemeTag1] = { "#3B82F6", "#1E1E2E", "#1E1E2E" }, // Blue
[SchemeTag2] = { "#8B5CF6", "#1E1E2E", "#1E1E2E" }, // Violet
[SchemeTag3] = { "#F59E0B", "#1E1E2E", "#1E1E2E" }, // Amber
[SchemeTag4] = { "#10B981", "#1E1E2E", "#1E1E2E" }, // Emerald
[SchemeTag5] = { "#EF4444", "#1E1E2E", "#1E1E2E" }, // Red

    /* Layout & Buttons */
    [SchemeLayout]   = { "#15ff00", "#1E1E2E", "#1E1E2E" }, // spring green for layout indicator
    [SchemeBtnPrev]  = { "#d200fc", "#1E1E2E", "#1E1E2E" }, // lawn green - previous button
    [SchemeBtnNext]  = { "#FFD700", "#1E1E2E", "#1E1E2E" }, // gold - next button
    [SchemeBtnClose] = { "#FF4500", "#1E1E2E", "#1E1E2E" }, // bright red - close button
    
};

/* ==================================================
   TAGGING / LAUNCHERS / AUTOSTART
   ================================================== */
static char *tags[] = {
    "󰣇",   /* Terminal */
    "󰈹",   /* Browser */
    "",   /* Music */
    "󰇮",   /* Files */
    ""    /* Settings */
};

/* Tag color schemes mapping */
static const int tagschemes[] = {
    SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4, SchemeTag5
};


#include "scratchtagwins.c"

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   iscentered   monitor    scratch key */
	{ "Gimp",     NULL,       NULL,       0,            1,           1,           -1,        0  },
	{ "mpv",      NULL,       NULL,       0,            1,           1,           -1,        0  },
	{ "qimgv",    NULL,       NULL,       0,            1,           1,           -1,        0  },
	{ "Nwg-look", NULL,       NULL,       0,            1,           1,           -1,        0  },
	{ NULL,   "scratchpad",   NULL,       0,            1,           1,           -1,       's' },
	{ NULL,   "pulsemixer",   NULL,       0,            1,           1,           -1,       'a' },
	SCRATCHTAGWIN_RULE (scratchtagwin1, 1),
	SCRATCHTAGWIN_RULE (scratchtagwin2, 2),
	SCRATCHTAGWIN_RULE (scratchtagwin3, 3),
	SCRATCHTAGWIN_RULE (scratchtagwin4, 4),
	SCRATCHTAGWIN_RULE (scratchtagwin5, 5),
	SCRATCHTAGWIN_RULE (scratchtagwin6, 6),
	SCRATCHTAGWIN_RULE (scratchtagwin7, 7),
	SCRATCHTAGWIN_RULE (scratchtagwin8, 8),
	SCRATCHTAGWIN_RULE (scratchtagwin9, 9),
};


/* window following */
#define WFACTIVE '󰁔'
#define WFINACTIVE '󰁅'
#define WFDEFAULT WFACTIVE



/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */
static const int refreshrate = 120;  /* refresh rate (per second) for client move/resize */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol     arrange function */
   
    { "󰙀",      tile },
    { "󱇚",      horizgrid },              /* no keybinding */
    { "󰕫",      centeredmaster },
    { "󰕴",      dwindle },                 /* first entry is default */ 
    { "󱒈",      bstack },
    { "󰕭",      nrowgrid },
    { "󰪷",      spiral },
      
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


/* Programs */
static const char *rofi[] = {
    "rofi", "-show", "drun", "-show-icons",
     NULL
};

/* ==========================
 * Change Volume
 * ========================== */
 
static const char *volumeup[]   = { "/home/kcmw/.local/bin/changevolume", "up", NULL };
static const char *volumedown[] = { "/home/kcmw/.local/bin/changevolume", "down", NULL };
static const char *volumemute[] = { "/home/kcmw/.local/bin/changevolume", "mute", NULL };	

/* ==================================================
   PROGRAMS / COMMANDS
   ================================================== */
static const char *termcmd[]  = { "rio", NULL };
static const char *thunar[]   = { "thunar", NULL }; 
static const char *firefox[]  = { "firefox", NULL };
static const char *geany[]    = { "geany", NULL }; 
static const char *libreoffice[]    = { "libreoffice", NULL }; 
static const char *audacious[] = { "audacious", NULL };
static const char *codium[]    = { "codium", NULL };

SCRATCHTAGWIN (scratchtagwin1, 1);
SCRATCHTAGWIN (scratchtagwin2, 2);
SCRATCHTAGWIN (scratchtagwin3, 3);
SCRATCHTAGWIN (scratchtagwin4, 4);
SCRATCHTAGWIN (scratchtagwin5, 5);
SCRATCHTAGWIN (scratchtagwin6, 6);
SCRATCHTAGWIN (scratchtagwin7, 7);
SCRATCHTAGWIN (scratchtagwin8, 8);
SCRATCHTAGWIN (scratchtagwin9, 9);

/*First arg only serves to match against key in rules*/
/* --name sets the WM_CLASS instance the rules match on; kitty rewrites
   titles at runtime, so title matching would lose the scratchkey. */
static const char *scratchpadcmd[] = {"s", "kitty", "--name", "scratchpad", NULL};
static const char *pulsemixercmd[] = {"a", "kitty", "--name", "pulsemixer", "-e", "pulsemixer", NULL};
 
  	/* ==========================
 * ScreenShot
 * ========================== */ 
#define screenshot_full SHCMD("mkdir -p \"$HOME/Pictures/Screenshots\" && maim \"$HOME/Pictures/Screenshots/screenshot-$(date +%Y%m%d-%H%M%S).png\"")
#define screenshot_sel  SHCMD("mkdir -p \"$HOME/Pictures/Screenshots\" && maim -s \"$HOME/Pictures/Screenshots/screenshot-$(date +%Y%m%d-%H%M%S).png\"")


#include "movestack.c"
/* keys[] is annotated for scripts/gen-keybinds, which regenerates
 * keybindings.txt (the Super+/ help) on every build:
 *   /o === NAME === o/          section header
 *   trailing /o description o/  help text for that binding ("!" pins to top)
 *   /o @help key :: desc o/     hand-written row for macro-generated bindings
 * (o = *). Bindings without a trailing comment don't appear in the help. */
static const Key keys[] = {
	/* modifiier                     key        function        argument */
	


   /* --------------------
       LAUNCH PROGRAMS
       -------------------- */
    { MODKEY,                       XK_l,      spawn,                {.v = libreoffice } },     /* Launch Libreoffice */       
    { MODKEY,                       XK_e,      spawn,                {.v = thunar } },     /* Launch Thunar */
    { MODKEY,                       XK_f,      spawn,                {.v = firefox } },    /* Launch Firefox */
    { MODKEY,                       XK_t,      spawn,                {.v = geany } },      /* Launch Geany */
    { MODKEY|ShiftMask,             XK_d,      spawn,                {.v = codium } },     /* Launch codium*/
    { MODKEY,                       XK_d,      spawn,                {.v = rofi } },       /* Launch Rofi menu */
    { MODKEY,                       XK_a,      spawn,                {.v = audacious} },   /* Launch audacious */
    { MODKEY,                       XK_Return, spawn,                {.v = termcmd } },    /* Launch terminal */

 /* --------------------
       LAYOUT KEYBINDINGS (direct access to layouts array)
       -------------------- */
    { Mod1Mask,                            XK_F1,      setlayout,            {.v = &layouts[0] } },
    { Mod1Mask,                            XK_F2,      setlayout,            {.v = &layouts[1] } },
    { Mod1Mask,                            XK_F3,      setlayout,            {.v = &layouts[2] } },
    { Mod1Mask,                            XK_F4,      setlayout,            {.v = &layouts[3] } },
    { Mod1Mask,                            XK_F5,      setlayout,            {.v = &layouts[4] } },
    { Mod1Mask,                            XK_F6,      setlayout,            {.v = &layouts[5] } },
    { Mod1Mask,                            XK_F7,      setlayout,            {.v = &layouts[6] } },
    

 	/* ==========================
 * WINDOW MANAGEMENT
 * ========================== */

  /* Close */
 { MODKEY,             XK_q,       killclient,      {0} },

 /* Focus */
  { MODKEY,             XK_Down,    focusstack,      {.i = +1 } },
 { MODKEY,             XK_Up,      focusstack,      {.i = -1 } },
 { MODKEY,             XK_Right,   focusstack,      {.i = +1 } },
 { MODKEY,             XK_Left,    focusstack,      {.i = -1 } },

/* Move */
{ MODKEY|ShiftMask,   XK_Up,      movestack,       {.i = +1 } },
{ MODKEY|ShiftMask,   XK_Down,    movestack,       {.i = -1 } },
{ MODKEY|ShiftMask,   XK_Right,   movestack,       {.i = +1 } },
{ MODKEY|ShiftMask,   XK_Left,    movestack,       {.i = -1 } },

/* Window State */
{ 0,                  XK_F11,     togglefullscr,      {0} },
{ MODKEY|ShiftMask,   XK_space,   togglefloating,  {0} }, 
{ MODKEY,             XK_y,       togglesticky,    {0} },
{ MODKEY,             XK_n,       togglefollow,    {0} },


/* Interface */
{ MODKEY,             XK_Tab,     view,            {0} },
{ MODKEY|ControlMask, XK_b,       togglebar,       {0} },



/* ==========================
 * LAYOUT
 * ========================== */

/* Resize */
{ Mod1Mask|ShiftMask,          XK_Left,    resizefocused,   {.f = -0.05} },
{ Mod1Mask|ShiftMask,         XK_Right,   resizefocused,   {.f = +0.05} },

/* Master Area */
{ MODKEY,                     XK_semicolon, resetfacts, {0} },
{ MODKEY|ALTKEY,              XK_Tab,       incnmaster, {.i = +1 } },
{ MODKEY|ALTKEY|ShiftMask,    XK_Tab,       incnmaster, {.i = -1 } },

/* Layout Selection */
{ ControlMask|ShiftMask, XK_1,      setlayout, {.v = &layouts[0]  } }, /* Dwindle */
{ ControlMask|ShiftMask, XK_2,      setlayout, {.v = &layouts[1]  } }, /* Tile */
{ ControlMask|ShiftMask, XK_3,      setlayout, {.v = &layouts[2]  } }, /* Columns */
{ ControlMask|ShiftMask, XK_4,      setlayout, {.v = &layouts[3]  } }, /* Centered Master */
{ ControlMask|ShiftMask, XK_5,      setlayout, {.v = &layouts[4]  } }, /* Floating */
{ ControlMask|ShiftMask, XK_6,      setlayout, {.v = &layouts[5]  } }, /* Bottom Stack */
{ ControlMask|ShiftMask, XK_7,      setlayout, {.v = &layouts[6]  } }, /* N-Row Grid */
{ ControlMask|ShiftMask, XK_8,      setlayout, {.v = &layouts[7]  } }, /* Deck */
{ ControlMask|ShiftMask, XK_9,      setlayout, {.v = &layouts[8]  } }, /* Gapless Grid */
{ ControlMask|ShiftMask, XK_0,      setlayout, {.v = &layouts[9]  } }, /* Spiral */
{ ControlMask|ShiftMask, XK_minus,  setlayout, {.v = &layouts[10] } }, /* Monocle */
{ ControlMask|ShiftMask, XK_equal,  setlayout, {.v = &layouts[11] } }, /* Grid */
	
	/* === TAGS === */
	/* @help Super + 1..9, 0, -, = :: !View tag 1..12 */
	/* @help Super + Shift + 1..= :: Send focused window to tag */
	/* @help Super + Ctrl + 1..= :: Toggle tag visibility */
	/* @help Super + Ctrl + Shift + 1..= :: Toggle window on tag */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_minus,                  10)
	TAGKEYS(                        XK_equal,                  11)
	{ ControlMask|ShiftMask,        XK_Left,   viewtoleft,     {0} },              /* View previous tag */
	{ ControlMask|ShiftMask,        XK_Right,  viewtoright,    {0} },              /* View next tag */
	{ ALTKEY|ControlMask,         XK_Left,   tagtoleft,      {0} },              /* Send window to previous tag */
	{ ALTKEY|ControlMask,         XK_Right,  tagtoright,     {0} },              /* Send window to next tag */

	/* === MONITOR === */
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },       /* Focus previous monitor */
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },       /* Focus next monitor */
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },       /* Send window to previous monitor */
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },       /* Send window to next monitor */

	/* === SCRATCHPAD === */
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } }, /* !Toggle scratchpad (kitty) */
	{ MODKEY,                       XK_v,      togglescratch,  {.v = pulsemixercmd } }, /* Toggle pulsemixer */
	/* @help Super + Alt + 1..9 :: Toggle named scratch slot 1..9 */
	/* @help Super + Alt + Shift + 1..9 :: Promote focused window into slot */
	SCRATCHTAGWIN_KEY (scratchtagwin1, 1)
	SCRATCHTAGWIN_KEY (scratchtagwin2, 2)
	SCRATCHTAGWIN_KEY (scratchtagwin3, 3)
	SCRATCHTAGWIN_KEY (scratchtagwin4, 4)
	SCRATCHTAGWIN_KEY (scratchtagwin5, 5)
	SCRATCHTAGWIN_KEY (scratchtagwin6, 6)
	SCRATCHTAGWIN_KEY (scratchtagwin7, 7)
	SCRATCHTAGWIN_KEY (scratchtagwin8, 8)
	SCRATCHTAGWIN_KEY (scratchtagwin9, 9)
	{ MODKEY|ALTKEY|ShiftMask,     XK_s,      makescratchtagwin,  {.i = 's'} },   /* Promote focused window to scratchpad */
	{ MODKEY|ALTKEY|ShiftMask,     XK_grave,  makescratchtagwin,  {.i = 0} },     /* Clear scratch state on focused window */

	/* === GAPS === */
	{ MODKEY|ALTKEY,              XK_0,      togglegaps,     {0} },              /* !Toggle gaps on/off */
	{ MODKEY|ALTKEY|ShiftMask,    XK_0,      defaultgaps,    {0} },              /* Reset gaps to defaults */
	{ MODKEY|ALTKEY,              XK_u,      incrgaps,       {.i = 1 } },        /* Increase all gaps */
	{ MODKEY|ALTKEY|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },       /* Decrease all gaps */
	{ MODKEY|ALTKEY,              XK_i,      incrigaps,      {.i = 1 } },        /* Increase inner gaps */
	{ MODKEY|ALTKEY|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },       /* Decrease inner gaps */
	{ MODKEY|ALTKEY,              XK_o,      incrogaps,      {.i = 1 } },        /* Increase outer gaps */
	{ MODKEY|ALTKEY|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },       /* Decrease outer gaps */
	{ MODKEY|ALTKEY,              XK_6,      incrihgaps,     {.i = 1 } },        /* Inner horizontal gap +1 */
	{ MODKEY|ALTKEY|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },       /* Inner horizontal gap -1 */
	{ MODKEY|ALTKEY,              XK_7,      incrivgaps,     {.i = 1 } },        /* Inner vertical gap +1 */
	{ MODKEY|ALTKEY|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },       /* Inner vertical gap -1 */
	{ MODKEY|ALTKEY,              XK_8,      incrohgaps,     {.i = 1 } },        /* Outer horizontal gap +1 */
	{ MODKEY|ALTKEY|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },       /* Outer horizontal gap -1 */
	{ MODKEY|ALTKEY,              XK_9,      incrovgaps,     {.i = 1 } },        /* Outer vertical gap +1 */
	{ MODKEY|ALTKEY|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },       /* Outer vertical gap -1 */

    /* === ScreenShot === */
    { 0,                            XK_Print,  spawn,                screenshot_full },
    { ShiftMask,                    XK_Print,  spawn,                screenshot_sel  },


    /* === VOLUME === */
    
    { 0, XF86XK_AudioRaiseVolume, spawn, {.v = volumeup} },
    { 0, XF86XK_AudioLowerVolume, spawn, {.v = volumedown} },
    { 0, XF86XK_AudioMute,        spawn, {.v = volumemute} },
    
	/* === SYSTEM === */
	{ MODKEY|ShiftMask,             XK_r,      quit,           {1} },              /* !Restart dwm (preserves tags/windows) */
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },              /* Quit dwm */
};

/* button definitions
 * click can be ClkTagBar, ClkLtSymbol, ClkFollowSymbol, ClkStatusText,
 * ClkWinTitle, ClkClientWin, or ClkRootWin
 */

static const Button buttons[] = {
	/* Layout symbol */
	{ ClkLtSymbol,     0,       Button1, setlayout,      {0} },
	{ ClkLtSymbol,     0,       Button3, setlayout,      {.v = &layouts[2]} },

	/* Follow symbol */
	{ ClkFollowSymbol, 0,       Button1, togglefollow,   {0} },

	/* Window title */
	{ ClkWinTitle,     0,       Button2, zoom,           {0} },

	/* Status bar */
	{ ClkStatusText,   0,       Button2, spawn,           {.v = termcmd} },

	/* Client window */
	{ ClkClientWin,    ALTKEY,  Button1, movemouse,       {0} },
	{ ClkClientWin,    ALTKEY,  Button2, togglefloating,  {0} },
	{ ClkClientWin,    ALTKEY,  Button3, resizemouse,     {0} },
	
	/* Tag bar */
	{ ClkTagBar,       0,       Button1, view,            {0} },
	{ ClkTagBar,       0,       Button3, toggleview,       {0} },
	{ ClkTagBar,       MODKEY,  Button1, tag,              {0} },
	{ ClkTagBar,       MODKEY,  Button3, toggletag,        {0} },
};
