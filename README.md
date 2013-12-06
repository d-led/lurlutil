lurlutil
========

a lua wrapper for the portable console manipulation library rlutil

usage
-----

| task | code |
|------|------|
| load the library into the `lurlutil` table | `assert(require 'lurlutil')` |
| wait for any key to be pressed | `lurlutil.anykey()` |
| set the console foreground color | `lurlutil.setColor( color )` |
| clear the screen and move the cursor home | `lurlutil.cls()` |
| hide the cursor | `lurlutil.hidecursor()` |
| show the cursor | `lurlutil.showcursor()` |
| set the cursor location (1-based position) | `lurlutil.locate( x , y )` <br /> or `lurlutil.gotoxy( x , y )` |
| get a single character from the console | `lurlutil.getch()` |
| get a single character, non-blocking, returns 0 if not hit | `lurlutil.nb_getch()` |
| check if a key has been hit | `lurlutil.kbhit()` |
| flush `stdout` | `lurlutil.flush()` |
| return the ANSI color escape sequence for the specified number 0-15 | `lurlutil.getANSIColor( color )` |
| wait a number of milliseconds | `lurlutil.msleep( ms )` |
| get the number of rows in the terminal (-1 on error) | `lurlutil.trows()` |




dependencies
------------

 - rlutil as the binding source
 - naturally, Lua as the binding target
 - LuaBridge for the C++ binding
 - Premake for generating makefiles and solutions

license
-------

Creative Commons License
