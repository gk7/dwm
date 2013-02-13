###A simple mouse friendly setup for dwm (Dynamic Window Manager) with additional patches to further extend the functionality.

##Patch Description :

###buildflags.diff
Archlinux specific compiler flags.

###Xft
This patch implements Xft. This allows users to utilize the UTF8 character set.

###pertag
Remembers window layout, bar position for each tag separately.

###systray
System tray implementation of the statusbar.

###statuscolors
This patch enables colored text in the status bar. It changes the way colors are defined in config.h, allowing the user to define multiple color combinations for use in their status script.

###occupiedcol
Removes little squares on tag names and colorize used tags.

###gaplessgrid
Gaplessgrid layout.(Allign all the windows in a grid)

###XkeycodeToKeysym-fix
Compile warning fix.

###enternotify
Lets you toggle focus follow mouse behaviour with a keybinding.(With fixed GrabMode)

###reload
Reloads dwm without killing the X server.

###cycle
Cycle through tags with mod+arrow keys and shift windows to another tag with mod+shift+arrow keys.

###pangofix
Lets you use pango library with xft.

###moveresize
Move and resize windows with arrow keys.

###push
Provides a way to move clients inside the clients list.

###bstack
Bottom stack layouts for dwm.

###centered floating
Make new floating windows appear to the center of the screen.

###save floats
This patch saves size and position of every floating window before it is forced into tiled mode. If the window is made floating again, the old dimensions will be restored.

###uselessgaps
This patch adds useless gap between windows. The size of the gap is configured in config.h

###bartrans
Makes status bar transparent. 

###bgtag
Adds a background tag so you may send application windows(e.g. downloading) to background tag and view with a keybinding. Sort of like scratchpad patch.
