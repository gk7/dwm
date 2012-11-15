/* 
Configuration file for DWM. 
Maintainer: illusionist
https://www.github.com/nixmeal
*/
/*Appearance*/
#define NUMCOLORS 5
static const char colors[NUMCOLORS][ColLast][20] = {
    // border     fg         bg
    { "#ababab", "#cacaca", "#020202" },  // 01 - normal
    { "#AF7130", "#20b2e7", "#020202" },  // 02 - selected
    { "#B3354C", "#B3354C", "#020202" },  // 03 - urgent
    { "#118900", "#FFB950", "#020202" },  // 04 - orange (Occupied Color)
    { "#20b2e7", "#20b2e7", "#020202" },  // 05 - Light Blue
//    { "#608040", "#608040", "#020202" },  // 06 - green
//    { "#877C43", "#877C43", "#020202" },  // 07 - yellow
//    { "#1C678C", "#1C678C", "#020202" },  // 08 - blue
//    { "#E300FF", "#E300FF", "#020202" },  // 09 - magenta
//    { "#000000", "#000000", "#000000" },  // unusable
//    { "#337373", "#337373", "#020202" },  // 0B - cyan
//    { "#808080", "#808080", "#020202" },  // 0C - light gray
//    { "#4C4C4C", "#4C4C4C", "#020202" },  // 0D - gray
//    { "#FFEE00", "#FFEE00", "#020202" },  // 0E - yellow2
//    { "#B1D354", "#B1D354", "#020202" },  // 0F - light green 
//    { "#BF9F5F", "#BF9F5F", "#020202" },  // 10 - light yellow
//    { "#3995BF", "#3995BF", "#020202" },  // 11 - light blue
//    { "#A64286", "#A64286", "#020202" },  // 12 - light magenta
//    { "#6C98A6", "#6C98A6", "#020202" },  // 13 - light cyan
//    { "#FFA500", "#FFA500", "#020202" },  // 14 - orange
//
//    { "#0300ff", "#0300ff", "#802635" },  // 15 - warning
};

static const char font[]			= "ohsnap.icons 9";
static const unsigned int borderpx  		= 0;        	// border pixel of windows 
static const unsigned int snap         		= 2;     	// snap pixel
static const unsigned int gappx			= 4;
static const Bool showbar               	= True;  	// False means no bar
static const Bool topbar                	= True;  	// False means bottom bar
static const unsigned int systrayspacing 	= 2;   		// systray spacing 
static const Bool showsystray       		= True;     	// False means no systray 

/* Layout(s) */
static const float mfact      			= 0.63;  	// factor of master area size [0.05..0.95]
static const int nmaster      			= 1;     	// number of clients in master area
static const Bool resizehints 			= False; 	// True means respect size hints in tiled resizals
static const Layout layouts[] = {
	/* symbol	gaps		function */
	{ "[ÿ]",	False,		monocle },    		/* first entry is default */
	{ "[ý]",	False,		NULL },    		/* no layout function means floating behavior */
	{ "[þ]",	True,		tile },
	{ "[ü]",	True,		bstack },
	{ "[ú]",	True,		chat },
};

/* Tagging */
//static const char *tags[] = { "A", "B", "C", "D", "E" };
static const Tag tags[] = {
    /* name    	layout       	mfact  	nmaster*/
    { "A",   	&layouts[0], 	-1,    	-1 },
    { "B",	&layouts[0], 	-1,  	-1 },
    { "C",  	&layouts[0], 	-1,    	-1 },
    { "D", 	&layouts[0], 	-1,    	-1 },
    { "E",  	&layouts[0], 	-1,    	-1 },
};

static const Rule rules[] = {
	/* class      		instance	title		tags mask	isfloating 	monitor */
	{ "Gimp",     		NULL,       	NULL,       	1 << 4,         True,        	-1 },
	{ "Firefox",		NULL,		NULL,	    	1 << 0,	  	False,		-1 },
	{ "VirtualBox",		NULL,		NULL,		1 << 4,		False,		-1 },
	{ "Google-chrome",	NULL,		NULL,		1 << 0,		False,		-1 },
	{ "Qpaeq",		NULL,		NULL,		0,		True,		-1 },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenurun[] 		= 	{ "/home/garry/.scripts/system", "dmenurun", NULL };
static const char *vollow[] 		=	{ "/home/garry/.scripts/system", "volume", "down", NULL };
static const char *volhigh[] 		=	{ "/home/garry/.scripts/system", "volume", "up",  NULL };
static const char *voltoggle[]		=	{ "/home/garry/.scripts/system", "volume", "toggle", NULL };
static const char *shutdown[]		=	{ "/home/garry/.scripts/system", "shutdown", NULL };
static const char *hibernate[]		=	{ "/home/garry/.scripts/system", "hibernate", NULL };
static const char *restart[]		=	{ "/home/garry/.scripts/system", "restart", NULL };
static const char *suspend[]		=	{ "/home/garry/.scripts/system", "suspend", NULL };
static const char *brightup[]		=	{ "/home/garry/.scripts/system", "brightness", "up", NULL };
static const char *brightdown[]		=	{ "/home/garry/.scripts/system", "brightness", "down", NULL };
static const char *mouse[]		=	{ "/home/garry/.scripts/system", "mouse", "toggle", NULL };
static const char *on[]			=	{ "/home/garry/.scripts/system", "net", "on", NULL };
static const char *off[]		=	{ "/home/garry/.scripts/system", "net", "off", NULL };
static const char *killnotify[]		=	{ "/home/garry/.scripts/system", "killnotify", NULL };
static const char *screenshot[]		=	{ "/home/garry/.scripts/system", "screenshot", NULL };
static const char *translate[]		=	{ "/home/garry/.scripts/dmenu-translate", NULL };
static const char *wallch[]		=	{ "/home/garry/.scripts/wallpaper", "next", NULL };
static const char *wallrev[]		=	{ "/home/garry/.scripts/wallpaper", "prev", NULL };
static const char *type[]		=	{ "/home/garry/.scripts/type.sh", NULL };
static const char *cursorspeed[]	=	{ "xset", "r", "rate", "350", "50", NULL };
static const char *mpd[]		=	{ "urxvtc", "-e", "ncmpcpp", NULL };
static const char *killdwm[]		=	{ "killall", "dwm", NULL };
static const char *scrlock[]		=	{ "/usr/bin/slock", NULL };
static const char *mpdtoggle[] 		=	{ "mpc", "toggle", NULL };
static const char *mpdnext[]		=	{ "mpc", "next", NULL };
static const char *mpdprev[]		=	{ "mpc", "prev", NULL };
static const char *fileman[] 		= 	{ "pcmanfm", NULL };
static const char *gmrun[] 		= 	{ "gmrun", NULL  };
static const char *terminal[]  		= 	{ "urxvtc", NULL };
//static const char *thunarterm[]		=	{ "/home/garry/.scripts/thunarterm", NULL };
//static const char *composite[]		=	{ "/home/garry/.scripts/composite", NULL };

static Key keys[] = {
	/* modifier                     	key        		function        	argument */
	{ ControlMask,                       	XK_Down,  		moveresize,     	{.v = (int []){ 0, 25, 0, 0 }}},
	{ ControlMask,                       	XK_Up,    		moveresize,     	{.v = (int []){ 0, -25, 0, 0 }}},
	{ ControlMask,                       	XK_Right, 		moveresize,     	{.v = (int []){ 25, 0, 0, 0 }}},
	{ ControlMask,                       	XK_Left,  		moveresize,     	{.v = (int []){ -25, 0, 0, 0 }}},
	{ ControlMask|ShiftMask,             	XK_Down,  		moveresize,     	{.v = (int []){ 0, 0, 0, 25 }}},
	{ ControlMask|ShiftMask,             	XK_Up,    		moveresize,     	{.v = (int []){ 0, 0, 0, -25 }}},
	{ ControlMask|ShiftMask,             	XK_Right, 		moveresize,     	{.v = (int []){ 0, 0, 25, 0 }}},
	{ ControlMask|ShiftMask,             	XK_Left,  		moveresize,     	{.v = (int []){ 0, 0, -25, 0 }}},
	{ MODKEY,                 		XK_Left,   		cycleprev,  		{0} },
	{ MODKEY,                 		XK_Right,  		cyclenext,  		{0} },
	{ MODKEY|ShiftMask,			XK_Left,		cyclemoveprev,		{0} },
	{ MODKEY|ShiftMask,			XK_Right,		cyclemovenext,		{0} },
	{ MODKEY,				XK_Escape,		spawn,			{.v = killnotify } },
	{ MODKEY,				XK_F1,			spawn,			{.v = terminal } },
	{ Mod1Mask,				XK_F2,      		spawn,	   		{.v = gmrun } },
//	{ 0,					XK_F4,			spawn,			{.v = thunarterm}},
	{ Mod1Mask|ControlMask,			XK_Delete,		spawn,			{.v = killdwm } },
	{ 0,					XK_Pause,		spawn,			{.v = cursorspeed}},
	{ 0,					XK_Print,		spawn,			{.v = screenshot}},
	{ 0,					XK_Scroll_Lock,		spawn,			{.v = scrlock}},
	{ MODKEY,                       	XK_p,      		spawn,          	{.v = dmenurun } },
	{ MODKEY,	 			XK_e,	   		spawn,	   		{.v = fileman} },
	{ Mod1Mask|ControlMask,			XK_h, 			spawn,	   		{.v = hibernate } },
	{ Mod1Mask|ControlMask,			XK_r,   		spawn,	   		{.v = restart } },
	{ Mod1Mask|ControlMask,			XK_s,			spawn,			{.v = suspend } },
	{ 0,					0x1008ff11,  		spawn,	   		{.v = vollow } },
	{ 0,					0x1008ff13, 		spawn,	   		{.v = volhigh } },
	{ 0,					0x1008ff12,		spawn,			{.v = voltoggle } },
	{ MODKEY,			 	0x1008ff2f, 		spawn,	   		{.v = shutdown } }, 
	{ ControlMask|Mod1Mask,			XK_Right,		spawn,			{.v = wallch} },
	{ ControlMask|Mod1Mask,			XK_Left,		spawn,			{.v = wallrev} },
	{ 0,					0x1008ff1d,		spawn,			{.v = mpd} },
	{ 0,					0x1008ff18,		spawn,			{.v = mpdprev} },
	{ 0,					0x1008ff19,		spawn,			{.v = mpdnext} },
	{ 0,					0x1008ff14,		spawn,			{.v = mpdtoggle} },
	{ MODKEY,				0x1008ff11,		spawn, 			{.v = brightdown} },
	{ MODKEY, 				0x1008ff13,		spawn,			{.v = brightup} } ,
	{ 0,					0x1008ff2f,		spawn,			{.v = mouse} },
	{ MODKEY,				XK_s,			spawn,			{.v = type} },
	{ MODKEY,				XK_F11,			spawn,			{.v = on} },
	{ MODKEY,				XK_F12,			spawn,			{.v = off} },
	{ MODKEY,				XK_F7,			spawn,			{.v = translate} },
	{ MODKEY,                       	XK_b,      		togglebar,     	        {0} },
	{ MODKEY,                       	XK_j,      		focusstack,     	{.i = +1 } },
	{ MODKEY,                       	XK_k,      		focusstack,     	{.i = -1 } },
	{ MODKEY,                       	XK_i,      		incnmaster,     	{.i = +1 } },
	{ MODKEY,                       	XK_d,      		incnmaster,     	{.i = -1 } },
	{ MODKEY,                       	XK_h,      		setmfact,       	{.f = -0.05} },
	{ MODKEY,                       	XK_l,      		setmfact,       	{.f = +0.05} },
	{ MODKEY,                       	XK_Return, 		zoom,           	{0} },
	{ MODKEY,                       	XK_Tab,    		view,           	{0} },
	{ MODKEY,             			XK_w,      		killclient,    		{0} },
	{ MODKEY,                       	XK_m,      		setlayout,      	{.v = &layouts[0]} },
	{ MODKEY,                       	XK_f,      		setlayout,      	{.v = &layouts[1]} },
	{ MODKEY,                       	XK_t,      		setlayout,      	{.v = &layouts[2]} },
	{ MODKEY,				XK_a,			setlayout,		{.v = &layouts[3]} },
	{ MODKEY,				XK_g,			setlayout,		{.v = &layouts[4]} },
	{ MODKEY,                       	XK_space,  		setlayout,      	{0} },
	{ MODKEY|ShiftMask,             	XK_space,  		togglefloating, 	{0} },
	{ MODKEY,                       	XK_0,      		view,           	{.ui = ~0 } },
	{ MODKEY|ShiftMask,             	XK_0,      		tag,            	{.ui = ~0 } },
	{ MODKEY,                       	XK_comma,  		focusmon,       	{.i = -1 } },
	{ MODKEY,                       	XK_period, 		focusmon,       	{.i = +1 } },
	{ MODKEY|ShiftMask,             	XK_comma,  		tagmon,         	{.i = -1 } },
	{ MODKEY|ShiftMask,             	XK_period, 		tagmon,         	{.i = +1 } },
	TAGKEYS(                        	XK_1,                      0)
	TAGKEYS(                        	XK_2,                      1)
	TAGKEYS(                        	XK_3,                      2)
	TAGKEYS(                        	XK_4,                      3)
	TAGKEYS(                        	XK_5,                      4)
//	{ MODKEY|ShiftMask,  		        XK_q,      		spawn,         		 {.v = composite}},
//	{ MODKEY,             			XK_q,      		quit,          		 {0} },
	{ MODKEY|ShiftMask,			XK_q,			quit,			{0} },
	{ MODKEY|ShiftMask,			XK_r,			reload,			{0} },

};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
/*	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } }, */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
