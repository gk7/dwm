/* 
Configuration file for DWM. 
Maintainer: illusionist
https://www.github.com/nixmeal
*/
/*Appearance*/
#include "moveresize.c"
#include "bstack.c"
#include "gaplessgrid.c"
#include "togglefullscreen.c"
#define NUMCOLORS 8
static const char colors[NUMCOLORS][ColLast][20] = {
    // border     fg         bg
    { "#000000", "#bbbbbb", "#020202" },  // 01 - normal "3c3dbe"
    { "#b525c7", "#bbbbbb", "#020202" },  // 02 - selected  "#AF7130" "b525c7" "ae8550"
    { "#B3354C", "#B3354C", "#020202" },  // 03 - urgent
    { "#118900", "#777777", "#020202" },  // 04 - Occupied Color
    { "#845d78", "#dddddd", "#020202" },  // 05 - Title Text Color
    { "#00dd00", "#c1c1c1", "#020202" },  // 06 - Layout Symbol Color
    { "#000000", "#dddddd", "#020202" },  // 07 - Status Text Color1
    { "#118900", "#777777", "#020202" },  // 08 - Status Text Color2(symbols)
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

static const char font[]                    = "-misc-ohsnap.icons-medium-r-normal--11-79-100-100-c-60-iso8859-1";
static const unsigned int borderpx  		= 1;        	// border pixel of windows 
static const unsigned int snap         		= 16;    	    // snap pixel
static const Bool showbar               	= True;  	    // False means no bar
static const Bool topbar                	= True;  	    // False means bottom bar
//static const char clsymbol[]                = "x";

/* Layout(s) */
static const float mfact      			= 0.65;  	        // factor of master area size [0.05..0.95]
static const int nmaster      			= 1;     	        // number of clients in master area
static const Bool resizehints 			= False; 	        // True means respect size hints in tiled resizals
enum { LayoutMonocle = 0, LayoutGrid, LayoutBstack, LayoutTile, LayoutFloat };
enum { LayoutDefault = LayoutMonocle};
static const Layout layouts[] = {
	/* symbol	function */
	{ "[ÿ]",	monocle },    		                        /* first entry is default */
	{ "[ú]",	gaplessgrid },
	{ "[ü]",	bstack },
	{ "[þ]",	tile },
	{ "[ý]",	NULL },    		                            /* no layout function means floating behavior */
    { NULL,     NULL },
};

/* Tagging */
static const char *tags[] = { "1", "2", "3", "4", "5"};
#define TagNone     0
#define TagMain     1 << 0
#define TagWeb      1 << 1
#define TagDoc      1 << 2
#define TagDev      1 << 3
#define TagMis      1 << 4

static const Rule rules[] = {
	/* class      		instance	title		tags mask	isfloating 	iscenterd	monitor */
	{ "Gimp",     		NULL,       NULL,       TagMis,     True,       False,		-1 },
	{ "Firefox",		NULL,		NULL,	    TagWeb,	  	False,		False, 		-1 },
	{ "VirtualBox",		NULL,		NULL,		TagMis,		False,		False,		-1 },
	{ "Google-chrome",	NULL,		NULL,		TagWeb,		False,		False,		-1 },
	{ "Dwb",			NULL,		NULL,		TagWeb,		False,		False,		-1 },
    { "Vlc",            NULL,       NULL,       TagMis,     False,      False,      -1 },
    { "Pcmanfm",        NULL,       NULL,       TagDoc,     False,      False,      -1 },
	{ "Qpaeq",			NULL,		NULL,		TagNone,	True,		True,		-1 },
	{ "Pavucontrol",	NULL,		NULL,		TagNone,	True,		True,		-1 },
	{ "Wxcam",			NULL,		NULL,		TagNone,	True,		True,		-1 },
	{ "Galculator",		NULL,		NULL,		TagNone,	True,		True,		-1 },
	{ "Sonata",			NULL,		NULL,		TagNone,	True,		True,		-1 },
	{ "Keepassx",		NULL,		NULL,		TagNone,	True,		True,		-1 },
    { "Gcolor2",        NULL,       NULL,       TagNone,    True,       True,       -1 },
    { "Gvim",           NULL,       NULL,       TagDev,     False,      False,      -1 },
    { "Epdfview",       NULL,       NULL,       TagDev,     False,      False,      -1 },
	{ "Pcmanfm",		NULL,	"Execute File", TagNone,	True,		True,		-1 },
    { NULL,             NULL,   "Event Tester", TagNone,    True,       True,       -1 },
};

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define SCRIPTS "/home/garry/.scripts/"

/* commands */
static const char *dmenurun[] 		= 	{ SCRIPTS "system", "dmenurun", NULL };
static const char *vollow[] 		=	{ SCRIPTS "system", "volume", "down", NULL };
static const char *volhigh[] 		=	{ SCRIPTS "system", "volume", "up",  NULL };
static const char *voltoggle[]		=	{ SCRIPTS "system", "volume", "toggle", NULL };
static const char *brightup[]		=	{ SCRIPTS "system", "brightness", "up", NULL };
static const char *brightdown[]		=	{ SCRIPTS "system", "brightness", "down", NULL };
static const char *mouse[]			=	{ SCRIPTS "system", "mouse", "toggle", NULL };
static const char *on[]				=	{ SCRIPTS "system", "net", "on", NULL };
static const char *off[]			=	{ SCRIPTS "system", "net", "off", NULL };
static const char *killnotify[]		=	{ SCRIPTS "system", "killnotify", NULL };
static const char *screenshot[]		=	{ SCRIPTS "system", "screenshot", NULL };
static const char *totalnet[]		=	{ SCRIPTS "totalnet.sh", NULL };
static const char *wallch[]			=	{ SCRIPTS "wallpaper", "next", NULL };
static const char *wallrev[]		=	{ SCRIPTS "wallpaper", "prev", NULL };
static const char *type[]			=	{ SCRIPTS "type.sh", "kee", NULL };
static const char *cursorspeed[]	=	{ "xset", "r", "rate", "350", "50", NULL };
static const char *mpd[]            =   { "urxvtc", "-fn", "-misc-envy code r-medium-r-normal--13-0-0-0-m-0-iso8859-10", "-e", "ncmpcpp", NULL };
static const char *killdwm[]		=	{ "killall", "dwm", NULL };
static const char *scrlock[]		=	{ SCRIPTS "system", "lock", NULL };
static const char *mpdtoggle[] 		=	{ "mpc", "toggle", NULL };
static const char *mpdnext[]		=	{ "mpc", "next", NULL };
static const char *mpdprev[]		=	{ "mpc", "prev", NULL };
static const char *fileman[] 		= 	{ "pcmanfm", NULL };
static const char *gmrun[] 			= 	{ "gmrun", NULL  };
static const char *terminal[]  		= 	{ "urxvtc", NULL };
static const char *powermenu[]      =   { SCRIPTS "power-menu", NULL };
//static const char *menu[]			=	{ "mygtkmenu", SCRIPTS "menu.txt", NULL };

#define Modkey Mod4Mask
#define Altkey Mod1Mask
#define Ctrlkey ControlMask
#define Shiftkey ShiftMask
#define TAGKEYS(KEY,TAG) \
	{ Modkey,                       KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ Modkey|Ctrlkey,           	KEY,      view,           {.ui = 1 << TAG} }, \
	{ Modkey|Shiftkey,             	KEY,      tag,            {.ui = 1 << TAG} }, \
	{ Modkey|Ctrlkey|Shiftkey, 		KEY,      toggletag,      {.ui = 1 << TAG} },

static Key keys[] = {
	/* modifier                     	key        				function        	argument */
	{ Modkey,							XK_Escape,				spawn,				{.v = killnotify } },
	{ Shiftkey,							XK_space,				spawn,				{.v = terminal } },
	{ Altkey,               			XK_space,      		    spawn,      	    {.v = dmenurun } },
	{ Modkey,	 						XK_e,	   				spawn,	   			{.v = fileman} },
	{ Modkey,							0x1008ff11,				spawn, 				{.v = brightdown} },
	{ Modkey, 							0x1008ff13,				spawn,				{.v = brightup} } ,
	{ Altkey,							XK_F2,      			spawn,	   			{.v = gmrun } },
	{ Altkey|Ctrlkey,					XK_Delete,				spawn,				{.v = killdwm } },
	{ 0,								XK_Pause,				spawn,				{.v = cursorspeed}},
	{ 0,								XK_Print,				spawn,				{.v = screenshot}},
	{ 0,								XK_Scroll_Lock,			spawn,				{.v = scrlock}},
	{ 0,								0x1008ff11, 		 	spawn,	   			{.v = vollow } },
    { Altkey,                           XK_h,                   spawn,              {.v = vollow } },
	{ 0,								0x1008ff13, 			spawn,	   			{.v = volhigh } },
    { Altkey,                           XK_l,                   spawn,              {.v = volhigh } },
	{ 0,								0x1008ff12,				spawn,				{.v = voltoggle } },
	{ Ctrlkey|Altkey,					XK_Right,				spawn,				{.v = wallch} },
	{ Ctrlkey|Altkey,					XK_Left,				spawn,				{.v = wallrev} },
	{ 0,								0x1008ff1d,				spawn,				{.v = mpd} },
	{ Ctrlkey,						    XK_semicolon,			spawn,				{.v = mpd} },
	{ 0,								0x1008ff18,				spawn,				{.v = mpdprev} },
    { Altkey,                           XK_j,                   spawn,              {.v = mpdprev} },
	{ 0,								0x1008ff19,				spawn,				{.v = mpdnext} },
    { Altkey,                           XK_k,                   spawn,              {.v = mpdnext} },
	{ 0,								0x1008ff14,				spawn,				{.v = mpdtoggle} },
    { Altkey,                           XK_semicolon,           spawn,              {.v = mpdtoggle} },
	{ 0,								0x1008ff2f,				spawn,				{.v = mouse} },
	{ Modkey,							XK_s,					spawn,				{.v = type} },
	{ Modkey,							XK_F11,					spawn,				{.v = on} },
	{ Modkey,							XK_F12,					spawn,				{.v = off} },
	{ Modkey,							XK_F7,					spawn,				{.v = totalnet} },
	{ Modkey,           			    XK_b,      				togglebar,  	   	{0} },
	{ Modkey,           			    XK_k,      				focusstack, 	    {.i = +1 } },
	{ Modkey,           			    XK_j,      				focusstack, 	    {0} },
	{ Modkey,           			    XK_i,      				incnmaster, 	    {.i = +1 } },
	{ Modkey,           			    XK_d,      				incnmaster, 	    {.i = -1 } },
	{ Modkey,           			    XK_Left,    		  	setmfact,   	    {.f = -0.05} },
	{ Modkey,           			    XK_Right,   		   	setmfact,   	    {.f = +0.05} },
	{ Modkey,           			    XK_Up,    		  		setmfact,   	    {.f = -0.05} },
	{ Modkey,           			    XK_Down,   		   		setmfact,   	    {.f = +0.05} },
	{ Modkey,           			    XK_Return, 				zoom,       	    {0} },
	{ Modkey,           			    XK_Tab,    				view,       	    {0} },
	{ Modkey,           			  	XK_z,      				killclient, 	   	{0} },
	{ Modkey,           			    XK_m,      				setlayout,  	    {.v = &layouts[LayoutMonocle]} },
	{ Modkey,           			    XK_f,      				setlayout,  	    {.v = &layouts[LayoutFloat]} },
	{ Modkey,           			    XK_t,      				setlayout,  	    {.v = &layouts[LayoutTile]} },
	{ Modkey,							XK_a,					setlayout,			{.v = &layouts[LayoutBstack]} },
	{ Modkey,							XK_g,					setlayout,			{.v = &layouts[LayoutGrid]} },
    { Modkey,                           XK_space,               nextlayout,         {0} },
    { Modkey|Shiftkey,                  XK_space,               prevlayout,         {0} },
	{ Ctrlkey,  			            XK_space,  				togglefloating, 	{0} },
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
	{ Altkey|Shiftkey,  			    XK_Down,   				spawn,      	    SHCMD("xdotool mousemove_relative 0 10")},
	{ Altkey|Shiftkey,  			    XK_Up,     				spawn,      	    SHCMD("xdotool mousemove_relative -- 0 -10")},
	{ Altkey|Shiftkey,  			    XK_Right,  				spawn,      	    SHCMD("xdotool mousemove_relative 10 0")},
	{ Altkey|Shiftkey,  			    XK_Left,   				spawn,      	    SHCMD("xdotool mousemove_relative -- -10 0")},
	{ Altkey,           			  	XK_1, 					spawn,      	    SHCMD("iocane b 1")},
	{ Altkey,							XK_2,					spawn,				SHCMD("iocane b 2")},
	{ Altkey,							XK_3,					spawn,				SHCMD("iocane b 3")},
	{ Modkey|Shiftkey,  			    XK_m,      				toggle_ffm, 	    {0} },
	{ Modkey,  			                XK_c,      			togglefullscreen, 	    {0} },
    { Altkey,                           XK_F4,                  spawn,              {.v = powermenu} },

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
//	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
//	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	/* --------------------------------------menu-----------------------------------------*/
	{ ClkWinTitle,          0,  		   	Button1,	    focusstack,     {.i = +1 } },
	{ ClkWinTitle,          0,  		    Button2,	    focusstack,     {.i = -1 } },
	{ ClkWinTitle,			0,				Button3,		killclient,		{0} },
    { ClkWinTitle,          0,              Button4,        cycle,  		{.i = -1} },
    { ClkWinTitle,          0,              Button5,        cycle,  		{.i = +1} },
	{ ClkStatusText,		0,				Button1,		spawn,			{.v = mpdnext} },
	{ ClkStatusText,		0,				Button2,		spawn,			{.v = mpdprev} },
//	{ ClkStatusText,		0,				Button3,		spawn,			{.v = menu } },
	{ ClkStatusText,		0,				Button4,		spawn,			{.v = volhigh} },
	{ ClkStatusText,		0,				Button5,		spawn,			{.v = vollow} },
//    { ClkRootWin,           0,              Button4,        spawn,          {.v = wallch} },
//    { ClkRootWin,           0,              Button5,        spawn,          {.v = wallrev} },
//	{ ClkRootWin,			0,				Button3,		spawn,			{.v = menu } },
    { ClkLtSymbol,          0,              Button1,        spawn,          {.v = mpdtoggle} },
	/*====================================================================================*/
	{ ClkClientWin,         Modkey,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         Modkey,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         Modkey,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            Modkey,         Button1,        tag,            {0} },
	{ ClkTagBar,            Modkey,         Button3,        toggletag,      {0} },
 //   { ClkClSymbol,          0,              Button1,        killclient,     {0} },
};
/* vim: set ts=4 sw=4 tw=0: */
