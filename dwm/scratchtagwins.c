#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/XF86keysym.h>

# define SCRATCHTAGWIN(name, id)								\
	static const char * name [] = { # id,						\
		"tabbed",												\
			"-p", "s+1",										\
			"-n", # name,										\
			"-g", "1195x672",									\
			"-c", "st", "-w",									\
		NULL													\
	}															\

# define SCRATCHTAGWIN_RULE(name, id)																	\
	{ NULL,       # name, NULL,       0,            1,           1,           -1,      '0' + id }		\

# define SCRATCHTAGWIN_KEY(name, id)														\
	{ MODKEY|Mod1Mask,          XK_ ## id,      togglescratch,  {.v = name } },				\
	{ MODKEY|Mod1Mask|ShiftMask,XK_ ## id,      makescratchtagwin,{.i = '0' + id } },		\

static void makescratchtagwin (const Arg * arg)
{
	if (selmon -> sel)
	{
		if (arg -> i != 0)
		{
			_Bool exists = 0;

			/* scan every monitor: a slot holder on another monitor
			   must still block the promotion */
			for (Monitor * m = mons; m && ! exists; m = m -> next)
				for (Client * c = m -> clients; c; c = c -> next)
					if (c -> scratchkey == arg -> i)
					{
						exists = 1;
						break;
					}

			if (exists)
			{
				char msg [40];
				snprintf (msg, sizeof msg, "Scratchpad slot %c already taken", (char) arg -> i);
				const char * cmd [] = { "notify-send", "-u", "low", "dwm", msg, NULL };
				spawn (& (const Arg) { .v = cmd });
				return;
			}
		}

		selmon -> sel -> scratchkey = arg -> i;
		if (arg -> i != 0)
		{
			selmon -> sel -> tags = 0,
			selmon -> sel -> isfloating = 1;
		}
		else
			selmon -> sel -> tags = selmon -> tagset [selmon -> seltags];
		focus (selmon -> sel);
		arrange (selmon);
	}
}
