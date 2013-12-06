lurlutil
========

a lua wrapper for the portable console manipulation library rlutil

usage
-----

task | code | 
---- | ---- | 
load the library into the `lurlutil` table                          | `assert(require 'lurlutil')`
wait for any key to be pressed                                      | `lurlutil.anykey()`
set the console foreground color                                    | `lurlutil.setColor( color )`
clear the screen and move the cursor home                           | `lurlutil.cls()`
hide the cursor                                                     | `lurlutil.hidecursor()`
show the cursor                                                     | `lurlutil.showcursor()`
set the cursor location (1-based position)                          | `lurlutil.locate( x , y )` <br /> or `lurlutil.gotoxy( x , y )`
get a single character from the console                             | `lurlutil.getch()`
get a single character, non-blocking, returns 0 if not hit          | `lurlutil.nb_getch()`
check if a key has been hit                                         | `lurlutil.kbhit()`
flush `stdout`                                                      | `lurlutil.flush()`
return the ANSI color escape sequence for the specified number 0-15 | `lurlutil.getANSIColor( color )`
wait a number of milliseconds                                       | `lurlutil.msleep( ms )`
get the number of rows in the terminal (-1 on error)                | `lurlutil.trows()`
get the number of columns in the terminal (-1 on error)             | `lurlutil.tcols()`
wait until a key is pressed                                         | `lurlutil.anykey()`
read a key and return a key code                                    | `lurlutil.getkey()`


constants
---------

| constant | description | 
| ---- | ---- | 
| `lurlutil.ANSI_BLACK` | |
| `lurlutil.ANSI_BLUE` | |
| `lurlutil.ANSI_BROWN` | |
| `lurlutil.ANSI_CLS` | |
| `lurlutil.ANSI_CYAN` | |
| `lurlutil.ANSI_DARKGREY` | |
| `lurlutil.ANSI_GREEN` | |
| `lurlutil.ANSI_GREY` | |
| `lurlutil.ANSI_LIGHTBLUE` | |
| `lurlutil.ANSI_LIGHTCYAN` | |
| `lurlutil.ANSI_LIGHTGREEN` | |
| `lurlutil.ANSI_LIGHTMAGENTA` | |
| `lurlutil.ANSI_LIGHTRED` | |
| `lurlutil.ANSI_MAGENTA` | |
| `lurlutil.ANSI_RED` | |
| `lurlutil.ANSI_WHITE` | |
| `lurlutil.ANSI_YELLOW` | |
| `lurlutil.BLACK` | |
| `lurlutil.BLUE` | |
| `lurlutil.BROWN` | |
| `lurlutil.CYAN` | |
| `lurlutil.DARKGREY` | |
| `lurlutil.GREEN` | |
| `lurlutil.GREY` | |
| `lurlutil.KEY_DELETE` | |
| `lurlutil.KEY_DOWN` | |
| `lurlutil.KEY_END` | |
| `lurlutil.KEY_ENTER` | |
| `lurlutil.KEY_ESCAPE` | |
| `lurlutil.KEY_F1` | |
| `lurlutil.KEY_F10` | |
| `lurlutil.KEY_F11` | |
| `lurlutil.KEY_F12` | |
| `lurlutil.KEY_F2` | |
| `lurlutil.KEY_F3` | |
| `lurlutil.KEY_F4` | |
| `lurlutil.KEY_F5` | |
| `lurlutil.KEY_F6` | |
| `lurlutil.KEY_F7` | |
| `lurlutil.KEY_F8` | |
| `lurlutil.KEY_F9` | |
| `lurlutil.KEY_HOME` | |
| `lurlutil.KEY_INSERT` | |
| `lurlutil.KEY_LEFT` | |
| `lurlutil.KEY_NUMDEL` | |
| `lurlutil.KEY_NUMPAD0` | |
| `lurlutil.KEY_NUMPAD1` | |
| `lurlutil.KEY_NUMPAD2` | |
| `lurlutil.KEY_NUMPAD3` | |
| `lurlutil.KEY_NUMPAD4` | |
| `lurlutil.KEY_NUMPAD5` | |
| `lurlutil.KEY_NUMPAD6` | |
| `lurlutil.KEY_NUMPAD7` | |
| `lurlutil.KEY_NUMPAD8` | |
| `lurlutil.KEY_NUMPAD9` | |
| `lurlutil.KEY_PGDOWN` | |
| `lurlutil.KEY_PGUP` | |
| `lurlutil.KEY_RIGHT` | |
| `lurlutil.KEY_SPACE` | |
| `lurlutil.KEY_UP` | |
| `lurlutil.LIGHTBLUE` | |
| `lurlutil.LIGHTCYAN` | |
| `lurlutil.LIGHTGREEN` | |
| `lurlutil.LIGHTMAGENTA` | |
| `lurlutil.LIGHTRED` | |
| `lurlutil.MAGENTA` | |
| `lurlutil.RED` | |
| `lurlutil.WHITE` | |
| `lurlutil.YELLOW` | |

dependencies
------------

 - rlutil as the binding source
 - naturally, Lua as the binding target
 - LuaBridge for the C++ binding
 - Premake for generating makefiles and solutions

license
-------

[MIT License](http://opensource.org/licenses/MIT)
