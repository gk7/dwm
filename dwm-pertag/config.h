/* 
Configuration file for DWM. 
Maintainer: illusionist
https://www.github.com/nixmeal
*/
/*Appearance*/
#include "push.c"
#include "moveresize.c"
#include "bstack.c"
#define NUMCOLORS 6
static const char colors[NUMCOLORS][ColLast][20] = {
    // border     fg         bg
    { "#ababab", "#a2a2a2", "#020202" },  // 01 - normal
    { "#AF7130", "#20b2e7", "#020202" },  // 02 - selected
    { "#B3354C", "#B3354C", "#020202" },  // 03 - urgent
    { "#118900", "#FFFFFF", "#020202" },  // 04 - orange (Occupied Color)
    { "#20b2e7", "#20b2e7", "#020202" },  // 05 - Light Blue
    { "#00dd00", "#00dd00", "#020202" },  // 06 - green
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
//    { "#0300ff", "#0300ff", "#802635" },  // 15 - warning
};

static const char font[]					= "ohsnap.icons 9";
static const unsigned int borderpx  		= 2;        	// border pixel of windows 
static const unsigned int snap         		= 2;     	// snap pixel
static const unsigned int gappx				= 3;		// gap pixel between windows (uselessgaps patch)
static const Bool showbar               	= True;  	// False means no bar
static const Bool topbar                	= True;  	// False means bottom bar
static const unsigned int systrayspacing 	= 2;   		// systray spacing 
static const Bool showsystray       		= True;     	// False means no systray 
static const Bool transbar					= False;		// True means transparent status bar

/* Layout(s) */
static const float mfact      				= 0.63;  	// factor of master area size [0.05..0.95]
static const int nmaster      				= 1;     	// number of clients in master area
static const Bool resizehints 				= False; 	// True means respect size hints in tiled resizals
static const Layout layouts[] = {
	/* symbol	function */
	{ "[ÿ]",	monocle },    		/* first entry is default */
	{ "[ý]",	NULL },    		/* no layout function means floating behavior */
	{ "[þ]",	tile },
	{ "[ü]",	bstack },
	{ "[ú]",	gaplessgrid },
};

/* Tagging */
static const char *tags[] = { "ä", "ä", "ä", "ä", "ä", "BG"};

static const Rule rules[] = {
	/* class      		instance	title		tags mask	isfloating 	iscenterd	monitor */
	{ "Gimp",     		NULL,       NULL,       1 << 4,     False,      False,		-1 },
	{ "Firefox",		NULL,		NULL,	    1 << 0,	  	False,		False, 		-1 },
	{ "VirtualBox",		NULL,		NULL,		1 << 4,		False,		False,		-1 },
	{ "Google-chrome",	NULL,		NULL,		1 << 0,		False,		False,		-1 },
	{ "Qpaeq",			NULL,		NULL,		0,			True,		True,		-1 },
	{ "Pavucontrol",	NULL,		NULL,		0,			True,		True,		-1 },
	{ "Wxcam",			NULL,		NULL,		0,			True,		True,		-1 },
	{ "Galculator",		NULL,		NULL,		0,			True,		True,		-1 },
	{ "Sonata",			NULL,		NULL,		0,			True,		True,		-1 },
	{ "Keepassx",		NULL,		NULL,		0,			True,		True,		-1 },
	{ "Dwb",			NULL,		NULL,		1 << 0,		False,		False,		-1 },
	{ NULL,				NULL,		"dload",	1 << 5,		True,		True,  		-1 },
	{ NULL,				NULL,		"tail",		1 << 5,		True,		True,  		-1 },
};

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
static const char *mouse[]			=	{ "/home/garry/.scripts/system", "mouse", "toggle", NULL };
static const char *on[]				=	{ "/home/garry/.scripts/system", "net", "on", NULL };
static const char *off[]			=	{ "/home/garry/.scripts/system", "net", "off", NULL };
static const char *killnotify[]		=	{ "/home/garry/.scripts/system", "killnotify", NULL };
static const char *screenshot[]		=	{ "/home/garry/.scripts/system", "screenshot", NULL };
static const char *translate[]		=	{ "/home/garry/.scripts/dmenu-translate", NULL };
static const char *wallch[]			=	{ "/home/garry/.scripts/wallpaper", "next", NULL };
static const char *wallrev[]		=	{ "/home/garry/.scripts/wallpaper", "prev", NULL };
static const char *type[]			=	{ "/home/garry/.scripts/type.sh", "kee", NULL };
static const char *cursorspeed[]	=	{ "xset", "r", "rate", "350", "50", NULL };
static const char *mpd[]			=	{ "urxvtc", "-e", "ncmpcpp", NULL };
static const char *killdwm[]		=	{ "killall", "dwm", NULL };
static const char *scrlock[]		=	{ "/usr/bin/slock", NULL };
static const char *mpdtoggle[] 		=	{ "mpc", "toggle", NULL };
static const char *mpdnext[]		=	{ "mpc", "next", NULL };
static const char *mpdprev[]		=	{ "mpc", "prev", NULL };
static const char *fileman[] 		= 	{ "pcmanfm", NULL };
static const char *gmrun[] 			= 	{ "gmrun", NULL  };
static const char *terminal[]  		= 	{ "urxvtc", NULL };
static const char *menu[]			=	{ "mygtkmenu", "/home/garry/.scripts/menu.txt", NULL };
//static const char *thunarterm[]		=	{ "/home/garry/.scripts/thunarterm", NULL };
//static const char *composite[]		=	{ "/home/garry/.scripts/composite", NULL };

#define Modkey Mod4Mask
#define Altkey Mod1Mask
#define Ctrlkey ControlMask
#define Shiftkey ShiftMask
#define TAGKEYS(KEY,TAG) \
	{ Modkey,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ Modkey|Ctrlkey,           	KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ Modkey|Shiftkey,             	KEY,      tag,            {.ui = 1 << TAG} }, \
	{ Modkey|Ctrlkey|Shiftkey, 		KEY,      toggletag,      {.ui = 1 << TAG} },

static Key keys[] = {
	/* modifier                     	key        				function        	argument */
	{ Modkey,							XK_Escape,				spawn,				{.v = killnotify } },
	{ Shiftkey,							XK_Return,				spawn,				{.v = terminal } },
	{ 0,               					XK_F1,      			spawn,      	    {.v = dmenurun } },
	{ Modkey,	 						XK_e,	   				spawn,	   			{.v = fileman} },
	{ Modkey,						 	XK_Pause, 				spawn,	   			{.v = shutdown } }, 
	{ Modkey,							0x1008ff11,				spawn, 				{.v = brightdown} },
	{ Modkey, 							0x1008ff13,				spawn,				{.v = brightup} } ,
	{ Altkey,							XK_F2,      			spawn,	   			{.v = gmrun } },
	{ Altkey|Ctrlkey,					XK_Delete,				spawn,				{.v = killdwm } },
	{ 0,								XK_Pause,				spawn,				{.v = cursorspeed}},
	{ 0,								XK_Print,				spawn,				{.v = screenshot}},
	{ 0,								XK_Scroll_Lock,			spawn,				{.v = scrlock}},
	{ Altkey|Ctrlkey,					XK_h, 					spawn,	   			{.v = hibernate } },
	{ Altkey|Ctrlkey,					XK_r,   				spawn,	   			{.v = restart } },
	{ Altkey|Ctrlkey,					XK_s,					spawn,				{.v = suspend } },
	{ 0,								0x1008ff11, 		 	spawn,	   			{.v = vollow } },
	{ 0,								0x1008ff13, 			spawn,	   			{.v = volhigh } },
	{ 0,								0x1008ff12,				spawn,				{.v = voltoggle } },
	{ Ctrlkey|Altkey,					XK_Right,				spawn,				{.v = wallch} },
	{ Ctrlkey|Altkey,					XK_Left,				spawn,				{.v = wallrev} },
	{ 0,								0x1008ff1d,				spawn,				{.v = mpd} },
	{ 0,								0x1008ff18,				spawn,				{.v = mpdprev} },
	{ 0,								0x1008ff19,				spawn,				{.v = mpdnext} },
	{ 0,								0x1008ff14,				spawn,				{.v = mpdtoggle} },
	{ 0,								0x1008ff2f,				spawn,				{.v = mouse} },
	{ Modkey,							XK_s,					spawn,				{.v = type} },
	{ Modkey,							XK_F11,					spawn,				{.v = on} },
	{ Modkey,							XK_F12,					spawn,				{.v = off} },
	{ Modkey,							XK_F7,					spawn,				{.v = translate} },
	{ Modkey,           			    XK_b,      				togglebar,  	   	{0} },
	{ Modkey,           			    XK_j,      				focusstack, 	    {.i = +1 } },
	{ Modkey,           			    XK_k,      				focusstack, 	    {.i = -1 } },
	{ Modkey,           			    XK_i,      				incnmaster, 	    {.i = +1 } },
	{ Modkey,           			    XK_d,      				incnmaster, 	    {.i = -1 } },
	{ Modkey,           			    XK_Left,    		  	setmfact,   	    {.f = -0.05} },
	{ Modkey,           			    XK_Right,   		   	setmfact,   	    {.f = +0.05} },
	{ Modkey,           			    XK_Return, 				zoom,       	    {0} },
	{ Modkey,           			    XK_Tab,    				view,       	    {0} },
	{ Modkey,           			  	XK_z,      				killclient, 	   	{0} },
	{ Modkey,           			    XK_m,      				setlayout,  	    {.v = &layouts[0]} },
	{ Modkey,           			    XK_f,      				setlayout,  	    {.v = &layouts[1]} },
	{ Modkey,           			    XK_t,      				setlayout,  	    {.v = &layouts[2]} },
	{ Modkey,							XK_a,					setlayout,			{.v = &layouts[3]} },
	{ Modkey,							XK_g,					setlayout,			{.v = &layouts[4]} },
	//{ Modkey,         			   	XK_space,  				setlayout,  	    {0} },
	{ Modkey|Shiftkey,  			    XK_f,  					togglefloating, 	{0} },
	{ Modkey,           			    XK_0,      				view,       	    {.ui = ~0 } },
	{ Modkey|Shiftkey,  			    XK_0,      				tag,        	    {.ui = ~0 } },
	{ Modkey,           			    XK_comma,  				focusmon,   	    {.i = -1 } },
	{ Modkey,           			    XK_period, 				focusmon,   	    {.i = +1 } },
	{ Modkey|Shiftkey,  			    XK_comma,  				tagmon,     	    {.i = -1 } },
	{ Modkey|Shiftkey,  			    XK_period, 				tagmon,     	    {.i = +1 } },
	{ Modkey|Shiftkey,					XK_q,					quit,				{0} },
	{ Modkey|Shiftkey,					XK_r,					reload,				{0} },
	{ Modkey,           			    XK_h,   				cycle,  			{.i = -1} },
	{ Modkey,           			    XK_l,  					cycle,  			{.i = +1} },
	{ Modkey|Shiftkey,					XK_h,					tagcycle,			{.i = -1} },
	{ Modkey|Shiftkey,					XK_l,					tagcycle,			{.i = +1} },
	{ Ctrlkey,          			    XK_Down,  				moveresize, 	   	{.v = (int []){ 0, 25, 0, 0 }}},
	{ Ctrlkey,          			    XK_Up,    				moveresize, 	    {.v = (int []){ 0, -25, 0, 0 }}},
	{ Ctrlkey,          			    XK_Right, 				moveresize, 	    {.v = (int []){ 25, 0, 0, 0 }}},
	{ Ctrlkey,          			    XK_Left,  				moveresize, 	    {.v = (int []){ -25, 0, 0, 0 }}},
	{ Ctrlkey|Shiftkey, 			    XK_Down,  				moveresize, 	    {.v = (int []){ 0, 0, 0, 25 }}},
	{ Ctrlkey|Shiftkey, 			    XK_Up,    				moveresize, 	    {.v = (int []){ 0, 0, 0, -25 }}},
	{ Ctrlkey|Shiftkey, 			    XK_Right, 				moveresize, 	    {.v = (int []){ 0, 0, 25, 0 }}},
	{ Ctrlkey|Shiftkey, 			    XK_Left,  				moveresize, 	    {.v = (int []){ 0, 0, -25, 0 }}},
	{ Modkey|Shiftkey,  			    XK_j,      				pushup,     	 	{.i = +1 } },
   	{ Modkey|Shiftkey,  			    XK_k,     				pushdown,   	   	{.i = -1 } },
	{ Altkey|Shiftkey,  			    XK_Down,   				spawn,      	    SHCMD("xdotool mousemove_relative 0 10")},
	{ Altkey|Shiftkey,  			    XK_Up,     				spawn,      	    SHCMD("xdotool mousemove_relative -- 0 -10")},
	{ Altkey|Shiftkey,  			    XK_Right,  				spawn,      	    SHCMD("xdotool mousemove_relative 10 0")},
	{ Altkey|Shiftkey,  			    XK_Left,   				spawn,      	    SHCMD("xdotool mousemove_relative -- -10 0")},
	{ Altkey,           			  	XK_1, 					spawn,      	    SHCMD("iocane b 1")},
	{ Altkey,							XK_2,					spawn,				SHCMD("iocane b 2")},
	{ Altkey,							XK_3,					spawn,				SHCMD("iocane b 3")},
	{ Altkey|Ctrlkey,   			   	XK_1, 					spawn,      	    SHCMD("iocane b 1")},
	{ Modkey|Shiftkey,  			    XK_m,      				toggle_ffm, 	    {0} },
	{ Modkey,           			    XK_space,   		   	toggleview, 	    {.ui = 1 << 5} },	
	{ Modkey|Shiftkey,					XK_space,				tag,				{.ui = 1 << 5} },
	TAGKEYS(            			    XK_1,                      0)
	TAGKEYS(            			    XK_2,                      1)
	TAGKEYS(            			    XK_3,                      2)
	TAGKEYS(            			    XK_4,                      3)
	TAGKEYS(            			    XK_5,                      4)

};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	/* --------------------------------------menu-----------------------------------------*/
	{ ClkRootWin,			0,				Button3,		spawn,			{.v = menu } },
	{ ClkWinTitle,			0,				Button2,		killclient,		{0} },
	{ ClkWinTitle,          0,  		   	Button1,	    focusstack,     {.i = +1 } },
	{ ClkWinTitle,          0,  		    Button3,	    focusstack,     {.i = -1 } },
	{ ClkStatusText,		0,				Button3,		spawn,			{.v = menu } },
	/*====================================================================================*/
	{ ClkClientWin,         Modkey,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         Modkey,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         Modkey,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            Modkey,         Button1,        tag,            {0} },
	{ ClkTagBar,            Modkey,         Button3,        toggletag,      {0} },
};
/* vim: set ts=4 sw=4 tw=0: */
