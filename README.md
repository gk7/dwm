This is my personal setup of dwm. You may want to use pkgbuild if you use Archlinux.

##Patch Description:

###buildflags.diff
Archlinux specific compiler flags.

###XkeycodeToKeysym-fix
Compile error fix.

###statuscolors
This patch enables colored text in the status bar. It changes the way colors are defined in config.h, allowing the user to define multiple color combinations for use in their status script.

###pertag
Remembers window layout for each tag seperately.

###monocle-no-border
No borders in monocle mode .

###centered-floating
Floating clients appear on the center of the screen.

###save floats
This patch saves size and position of every floating window before it is forced
into tiled mode. If the window is made floating again, the old dimensions will
be restored.

###enternotify
Disables focus follow mouse behaviour.

###bstack (Bottom Stack)
All the clients are arranged at the bottom of the screen vertically.

###systray
System tray implimentation of the statusbar.

###gaplessgrid
Arrange all the windows in a grid layout.

###fibonacci
Arranges all windows in Fibonacci tiles: The first window uses half the screen, the second the half of the remainder, etc.

###attachaside
Makes the new client get attached and focused in the stacking area instead of always becoming the new master.
