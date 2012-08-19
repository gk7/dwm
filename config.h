/* 
Configuration file for DWM. 
Maintainer: illusionist
https://www.github.com/nixmeal
*/
#include <bstack.c>
/*Appearance*/
#define NUMCOLORS 21
static const char colors[NUMCOLORS][ColLast][21] = {
    // border     fg         bg
	{ "#1A1A1A", "#d6d6d6", "#020202" },  // 01 - normal
    { "#4C4C4C", "#00FF00", "#020202" },  // 02 - selected
    { "#B3354C", "#B3354C", "#020202" },  // 03 - urgent

    { "#1A1A1A", "#1A1A1A", "#020202" },  // 04 - black
    { "#802635", "#802635", "#020202" },  // 05 - red
    { "#608040", "#608040", "#020202" },  // 06 - green
    { "#877C43", "#877C43", "#020202" },  // 07 - yellow
    { "#1C678C", "#1C678C", "#020202" },  // 08 - blue
    { "#684D80", "#684D80", "#020202" },  // 09 - magenta
    { "#000000", "#000000", "#000000" },  // unusable
    { "#337373", "#337373", "#020202" },  // 0B - cyan
    { "#808080", "#808080", "#020202" },  // 0C - light gray
    { "#4C4C4C", "#4C4C4C", "#020202" },  // 0D - gray
    { "#B3354C", "#B3354C", "#020202" },  // 0E - light red
    { "#4BA65A", "#4BA65A", "#020202" },  // 0F - light green
    { "#BF9F5F", "#BF9F5F", "#020202" },  // 10 - light yellow
    { "#3995BF", "#3995BF", "#020202" },  // 11 - light blue
    { "#A64286", "#A64286", "#020202" },  // 12 - light magenta
    { "#6C98A6", "#6C98A6", "#020202" },  // 13 - light cyan
    { "#FFA500", "#FFA500", "#020202" },  // 14 - white

    { "#0300ff", "#0300ff", "#802635" },  // 15 - warning
};

/*static const char font[]		= "terminus2 9";*/
static const char font[]		= "-misc-ohsnap.icons-medium-r-normal--0-0-75-75-c-0-iso8859-1";
static const unsigned int borderpx  	= 1;        	/* border pixel of windows */
static const unsigned int snap          = 2;     	// snap pixel
static const Bool showbar               = True;  	// False means no bar
static const Bool topbar                = True;  	// False means bottom bar
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const Bool showsystray       = True;     /* False means no systray */



/* Layout(s) */
static const float mfact      = 0.63;  // factor of master area size [0.05..0.95]
static const int nmaster      = 1;     // number of clients in master area
static const Bool resizehints = False; // True means respect size hints in tiled resizals
static const Layout layouts[] = {
	/* symbol	arrange function */
	{ "[M]",	monocle },    /* first entry is default */
	{ "[F]",	NULL },    /* no layout function means floating behavior */
	{ "[T]",	tile },
	{ "[F]",	bstack },
};



/* Tagging */
static const char *tags[] = { "A", "B", "C", "D", "E" };

static const Rule rules[] = {
	/* class      		instance	title		tags mask	isfloating 	monitor */
	{ "Gimp",     		NULL,       	NULL,       	0,            	True,        	-1 },
	{ "Firefox",		NULL,		NULL,	    	1 << 0,	  	False,		-1 },
	{ "URxvt",		NULL,		NULL,		0,		False,		-1 },
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
static const char *dmenurun[] 		= 	{ "/home/garry/.scripts/dmenurun", NULL };
static const char *terminal[]  		= 	{ "urxvtc", NULL };
static const char *gmrun[] 		= 	{ "gmrun", NULL  };
static const char *thunar[] 		= 	{ "thunar", NULL };
static const char *vollow[] 		=	{ "/home/garry/.scripts/volume", "down", NULL };
static const char *volhigh[] 		=	{ "/home/garry/.scripts/volume", "up",  NULL };
static const char *voltoggle[]		=	{ "/home/garry/.scripts/volume", "toggle", NULL };
static const char *shutdown[]		=	{ "/home/garry/.scripts/system", "shutdown", NULL };
static const char *hibernate[]		=	{ "/home/garry/.scripts/system", "hibernate", NULL };
static const char *restart[]		=	{ "/home/garry/.scripts/system", "restart", NULL };
static const char *suspend[]		=	{ "/home/garry/.scripts/system", "suspend", NULL };
static const char *killdwm[]		=	{ "killall", "dwm", NULL };
static const char *firefox[]		=	{ "/bin/bash", "-c", "/home/garry/.firefox/firefox 2>&1> /dev/null", NULL };
static const char *wallch[]		=	{ "/home/garry/.scripts/rotatewallpaper", NULL };
static const char *wallrev[]		=	{ "/home/garry/.scripts/rotatewallreverse", NULL };
static const char *mpd[]		=	{ "urxvtc", "-e", "ncmpcpp", NULL };
static const char *mpdnext[]		=	{ "mpc", "next", NULL };
static const char *mpdprev[]		=	{ "mpc", "prev", NULL };
static const char *mpdtoggle[] 		=	{ "mpc", "toggle", NULL };
static const char *pavucontrol[]	=	{ "pavucontrol", NULL };
static const char *cursorspeed[]	=	{ "xset", "r", "rate", "350", "50", NULL };
static const char *screenshot[]		=	{ "/home/garry/.scripts/screenshot.sh", NULL };
static const char *googleimages[]	=	{ "/home/garry/.firefox/firefox", "-new-tab", "http://www.google.com/imghp?hl=en&tab=wi", NULL };
static const char *thunarterm[]		=	{ "/home/garry/.scripts/thunarterm", NULL };
static const char *scrlock[]		=	{ "/usr/bin/slock", NULL };
static const char *killnotify[]		=	{ "/bin/bash", "-c", "/home/garry/.scripts/kilnoti 2>&1> /dev/null", NULL };

static Key keys[] = {
	/* modifier                     	key        		function        	argument */
	{ MODKEY,                       	XK_p,      		spawn,          	{.v = dmenurun } },
	{ Mod1Mask,				XK_F2,      		spawn,	   		{.v = gmrun } },
	{ MODKEY,	 			XK_e,	   		spawn,	   		{.v = thunar } },
	{ MODKEY,				XK_minus,  		spawn,	   		{.v = vollow } },
	{ MODKEY,				XK_equal,  		spawn,	   		{.v = volhigh } },
	{ MODKEY,				XK_backslash,		spawn,			{.v = voltoggle } },
	{ Mod1Mask|ControlMask, 		XK_s, 			spawn,	   		{.v = shutdown } }, 
	{ Mod1Mask|ControlMask,			XK_h, 			spawn,	   		{.v = hibernate } },
	{ Mod1Mask|ControlMask,			XK_r,   		spawn,	   		{.v = restart } },
	{ Mod1Mask|ControlMask,			XK_l,			spawn,			{.v = suspend } },
	{ Mod1Mask|ControlMask,			XK_Delete,		spawn,			{.v = killdwm } },
	{ MODKEY,				XK_F1,			spawn,			{.v = terminal } },
	{ MODKEY,				XK_F2,			spawn,			{.v = firefox } } ,
	{ MODKEY,				XK_F10,			spawn,			{.v = wallch} },
	{ MODKEY|ShiftMask,			XK_F10,			spawn,			{.v = wallrev} },
	{ MODKEY,				XK_F3,			spawn,			{.v = mpd} },
	{ MODKEY,				XK_bracketleft,		spawn,			{.v = mpdprev} },
	{ MODKEY,				XK_bracketright,	spawn,			{.v = mpdnext} },
	{ MODKEY,				XK_slash,		spawn,			{.v = mpdtoggle} },
	{ MODKEY,				XK_F4,			spawn,			{.v = pavucontrol}},
	{ 0,					XK_Pause,		spawn,			{.v = cursorspeed}},
	{ 0,					XK_Print,		spawn,			{.v = screenshot}},
	{ ControlMask,				XK_Home,		spawn,			{.v = googleimages}},
	{ 0,					XK_F4,			spawn,			{.v = thunarterm}},
	{ 0,					XK_Scroll_Lock,		spawn,			{.v = scrlock}},
	{ MODKEY,				XK_Escape,		spawn,			{.v = killnotify}},
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
	TAGKEYS(                        	XK_6,                      5)
	TAGKEYS(                        	XK_7,                      6)
	TAGKEYS(                        	XK_8,                      7)
	TAGKEYS(                        	XK_9,                      8)
	{ MODKEY|ShiftMask,             	XK_q,      		quit,           {0} },
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
