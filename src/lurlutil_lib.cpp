/**
 * Copyright (c) 2013 Dmitry Ledentsov
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "lurlutil_lib.h"

#include <LuaBridge.h>
#include <rlutil.h>
#include <RefCountedPtr.h>
#include <string>
#include <cstdio>

namespace lurlutil {
	static std::string lua_getch() {
		char ch=getch();
		return std::string(1,ch);
	}
	
	static void flush() {
		fflush(stdout);
	}
	
	static int 	BLACK	 = 	(int)rlutil::BLACK;
	static int 	BLUE	 = 	(int)rlutil::BLUE;
	static int 	GREEN	 = 	(int)rlutil::GREEN;
	static int 	CYAN	 = 	(int)rlutil::CYAN;
	static int 	RED	 = 	(int)rlutil::RED;
	static int 	MAGENTA	 = 	(int)rlutil::MAGENTA;
	static int 	BROWN	 = 	(int)rlutil::BROWN;
	static int 	GREY	 = 	(int)rlutil::GREY;
	static int 	DARKGREY	 = 	(int)rlutil::DARKGREY;
	static int 	LIGHTBLUE	 = 	(int)rlutil::LIGHTBLUE;
	static int 	LIGHTGREEN	 = 	(int)rlutil::LIGHTGREEN;
	static int 	LIGHTCYAN	 = 	(int)rlutil::LIGHTCYAN;
	static int 	LIGHTRED	 = 	(int)rlutil::LIGHTRED;
	static int 	LIGHTMAGENTA	 = 	(int)rlutil::LIGHTMAGENTA;
	static int 	YELLOW	 = 	(int)rlutil::YELLOW;
	static int 	WHITE	 = 	(int)rlutil::WHITE;
	static std::string ANSI_CLS	 = 	rlutil:: ANSI_CLS;
	static std::string ANSI_BLACK	 = 	rlutil:: ANSI_BLACK;
	static std::string ANSI_RED	 = 	rlutil:: ANSI_RED;
	static std::string ANSI_GREEN	 = 	rlutil:: ANSI_GREEN;
	static std::string ANSI_BROWN	 = 	rlutil:: ANSI_BROWN;
	static std::string ANSI_BLUE	 = 	rlutil:: ANSI_BLUE;
	static std::string ANSI_MAGENTA	 = 	rlutil:: ANSI_MAGENTA;
	static std::string ANSI_CYAN	 = 	rlutil:: ANSI_CYAN;
	static std::string ANSI_GREY	 = 	rlutil:: ANSI_GREY;
	static std::string ANSI_DARKGREY	 = 	rlutil:: ANSI_DARKGREY;
	static std::string ANSI_LIGHTRED	 = 	rlutil:: ANSI_LIGHTRED;
	static std::string ANSI_LIGHTGREEN	 = 	rlutil:: ANSI_LIGHTGREEN;
	static std::string ANSI_YELLOW	 = 	rlutil:: ANSI_YELLOW;
	static std::string ANSI_LIGHTBLUE	 = 	rlutil:: ANSI_LIGHTBLUE;
	static std::string ANSI_LIGHTMAGENTA	 = 	rlutil:: ANSI_LIGHTMAGENTA;
	static std::string ANSI_LIGHTCYAN	 = 	rlutil:: ANSI_LIGHTCYAN;
	static std::string ANSI_WHITE	 = 	rlutil:: ANSI_WHITE;
	static int 	KEY_ESCAPE	 = 	(int)rlutil::KEY_ESCAPE;
	static int 	KEY_ENTER	 = 	(int)rlutil::KEY_ENTER;
	static int 	KEY_SPACE	 = 	(int)rlutil::KEY_SPACE;
	static int 	KEY_INSERT	 = 	(int)rlutil::KEY_INSERT;
	static int 	KEY_HOME	 = 	(int)rlutil::KEY_HOME;
	static int 	KEY_PGUP	 = 	(int)rlutil::KEY_PGUP;
	static int 	KEY_DELETE	 = 	(int)rlutil::KEY_DELETE;
	static int 	KEY_END	 = 	(int)rlutil::KEY_END;
	static int 	KEY_PGDOWN	 = 	(int)rlutil::KEY_PGDOWN;
	static int 	KEY_UP	 = 	(int)rlutil::KEY_UP;
	static int 	KEY_DOWN	 = 	(int)rlutil::KEY_DOWN;
	static int 	KEY_LEFT	 = 	(int)rlutil::KEY_LEFT;
	static int 	KEY_RIGHT	 = 	(int)rlutil::KEY_RIGHT;
	static int 	KEY_F1	 = 	(int)rlutil::KEY_F1;
	static int 	KEY_F2	 = 	(int)rlutil::KEY_F2;
	static int 	KEY_F3	 = 	(int)rlutil::KEY_F3;
	static int 	KEY_F4	 = 	(int)rlutil::KEY_F4;
	static int 	KEY_F5	 = 	(int)rlutil::KEY_F5;
	static int 	KEY_F6	 = 	(int)rlutil::KEY_F6;
	static int 	KEY_F7	 = 	(int)rlutil::KEY_F7;
	static int 	KEY_F8	 = 	(int)rlutil::KEY_F8;
	static int 	KEY_F9	 = 	(int)rlutil::KEY_F9;
	static int 	KEY_F10	 = 	(int)rlutil::KEY_F10;
	static int 	KEY_F11	 = 	(int)rlutil::KEY_F11;
	static int 	KEY_F12	 = 	(int)rlutil::KEY_F12;
	static int 	KEY_NUMDEL	 = 	(int)rlutil::KEY_NUMDEL;
	static int 	KEY_NUMPAD0	 = 	(int)rlutil::KEY_NUMPAD0;
	static int 	KEY_NUMPAD1	 = 	(int)rlutil::KEY_NUMPAD1;
	static int 	KEY_NUMPAD2	 = 	(int)rlutil::KEY_NUMPAD2;
	static int 	KEY_NUMPAD3	 = 	(int)rlutil::KEY_NUMPAD3;
	static int 	KEY_NUMPAD4	 = 	(int)rlutil::KEY_NUMPAD4;
	static int 	KEY_NUMPAD5	 = 	(int)rlutil::KEY_NUMPAD5;
	static int 	KEY_NUMPAD6	 = 	(int)rlutil::KEY_NUMPAD6;
	static int 	KEY_NUMPAD7	 = 	(int)rlutil::KEY_NUMPAD7;
	static int 	KEY_NUMPAD8	 = 	(int)rlutil::KEY_NUMPAD8;
	static int 	KEY_NUMPAD9	 = 	(int)rlutil::KEY_NUMPAD9;		
}

void register_lurlutil (lua_State* L) {
	luabridge::getGlobalNamespace(L)
		.beginNamespace("lurlutil")
			.addFunction("anykey",rlutil::anykey)
			.addFunction("setColor",rlutil::setColor)
			.addFunction("getkey",rlutil::getkey)
			.addFunction("cls",rlutil::cls)
			.addFunction("hidecursor",rlutil::hidecursor)
			.addFunction("showcursor",rlutil::showcursor)
			.addFunction("locate",rlutil::locate)
			.addFunction("getch",lurlutil::lua_getch)
			.addFunction("nb_getch",rlutil::nb_getch)
			.addFunction("kbhit",kbhit)
			.addFunction("gotoxy",gotoxy)
			.addFunction("msleep",rlutil::msleep)
			.addFunction("flush",lurlutil::flush)
			.addFunction("trows",rlutil::trows)
			.addFunction("tcols",rlutil::tcols)
			.addFunction("getANSIColor",rlutil::getANSIColor)
					
			.addVariable("BLACK",&lurlutil::BLACK,false)
			.addVariable("BLUE",&lurlutil::BLUE,false)
			.addVariable("GREEN",&lurlutil::GREEN,false)
			.addVariable("CYAN",&lurlutil::CYAN,false)
			.addVariable("RED",&lurlutil::RED,false)
			.addVariable("MAGENTA",&lurlutil::MAGENTA,false)
			.addVariable("BROWN",&lurlutil::BROWN,false)
			.addVariable("GREY",&lurlutil::GREY,false)
			.addVariable("DARKGREY",&lurlutil::DARKGREY,false)
			.addVariable("LIGHTBLUE",&lurlutil::LIGHTBLUE,false)
			.addVariable("LIGHTGREEN",&lurlutil::LIGHTGREEN,false)
			.addVariable("LIGHTCYAN",&lurlutil::LIGHTCYAN,false)
			.addVariable("LIGHTRED",&lurlutil::LIGHTRED,false)
			.addVariable("LIGHTMAGENTA",&lurlutil::LIGHTMAGENTA,false)
			.addVariable("YELLOW",&lurlutil::YELLOW,false)
			.addVariable("WHITE",&lurlutil::WHITE,false)
			.addVariable("ANSI_CLS",&lurlutil::ANSI_CLS,false)
			.addVariable("ANSI_BLACK",&lurlutil::ANSI_BLACK,false)
			.addVariable("ANSI_RED",&lurlutil::ANSI_RED,false)
			.addVariable("ANSI_GREEN",&lurlutil::ANSI_GREEN,false)
			.addVariable("ANSI_BROWN",&lurlutil::ANSI_BROWN,false)
			.addVariable("ANSI_BLUE",&lurlutil::ANSI_BLUE,false)
			.addVariable("ANSI_MAGENTA",&lurlutil::ANSI_MAGENTA,false)
			.addVariable("ANSI_CYAN",&lurlutil::ANSI_CYAN,false)
			.addVariable("ANSI_GREY",&lurlutil::ANSI_GREY,false)
			.addVariable("ANSI_DARKGREY",&lurlutil::ANSI_DARKGREY,false)
			.addVariable("ANSI_LIGHTRED",&lurlutil::ANSI_LIGHTRED,false)
			.addVariable("ANSI_LIGHTGREEN",&lurlutil::ANSI_LIGHTGREEN,false)
			.addVariable("ANSI_YELLOW",&lurlutil::ANSI_YELLOW,false)
			.addVariable("ANSI_LIGHTBLUE",&lurlutil::ANSI_LIGHTBLUE,false)
			.addVariable("ANSI_LIGHTMAGENTA",&lurlutil::ANSI_LIGHTMAGENTA,false)
			.addVariable("ANSI_LIGHTCYAN",&lurlutil::ANSI_LIGHTCYAN,false)
			.addVariable("ANSI_WHITE",&lurlutil::ANSI_WHITE,false)
			.addVariable("KEY_ESCAPE",&lurlutil::KEY_ESCAPE,false)
			.addVariable("KEY_ENTER",&lurlutil::KEY_ENTER,false)
			.addVariable("KEY_SPACE",&lurlutil::KEY_SPACE,false)
			.addVariable("KEY_INSERT",&lurlutil::KEY_INSERT,false)
			.addVariable("KEY_HOME",&lurlutil::KEY_HOME,false)
			.addVariable("KEY_PGUP",&lurlutil::KEY_PGUP,false)
			.addVariable("KEY_DELETE",&lurlutil::KEY_DELETE,false)
			.addVariable("KEY_END",&lurlutil::KEY_END,false)
			.addVariable("KEY_PGDOWN",&lurlutil::KEY_PGDOWN,false)
			.addVariable("KEY_UP",&lurlutil::KEY_UP,false)
			.addVariable("KEY_DOWN",&lurlutil::KEY_DOWN,false)
			.addVariable("KEY_LEFT",&lurlutil::KEY_LEFT,false)
			.addVariable("KEY_RIGHT",&lurlutil::KEY_RIGHT,false)
			.addVariable("KEY_F1",&lurlutil::KEY_F1,false)
			.addVariable("KEY_F2",&lurlutil::KEY_F2,false)
			.addVariable("KEY_F3",&lurlutil::KEY_F3,false)
			.addVariable("KEY_F4",&lurlutil::KEY_F4,false)
			.addVariable("KEY_F5",&lurlutil::KEY_F5,false)
			.addVariable("KEY_F6",&lurlutil::KEY_F6,false)
			.addVariable("KEY_F7",&lurlutil::KEY_F7,false)
			.addVariable("KEY_F8",&lurlutil::KEY_F8,false)
			.addVariable("KEY_F9",&lurlutil::KEY_F9,false)
			.addVariable("KEY_F10",&lurlutil::KEY_F10,false)
			.addVariable("KEY_F11",&lurlutil::KEY_F11,false)
			.addVariable("KEY_F12",&lurlutil::KEY_F12,false)
			.addVariable("KEY_NUMDEL",&lurlutil::KEY_NUMDEL,false)
			.addVariable("KEY_NUMPAD0",&lurlutil::KEY_NUMPAD0,false)
			.addVariable("KEY_NUMPAD1",&lurlutil::KEY_NUMPAD1,false)
			.addVariable("KEY_NUMPAD2",&lurlutil::KEY_NUMPAD2,false)
			.addVariable("KEY_NUMPAD3",&lurlutil::KEY_NUMPAD3,false)
			.addVariable("KEY_NUMPAD4",&lurlutil::KEY_NUMPAD4,false)
			.addVariable("KEY_NUMPAD5",&lurlutil::KEY_NUMPAD5,false)
			.addVariable("KEY_NUMPAD6",&lurlutil::KEY_NUMPAD6,false)
			.addVariable("KEY_NUMPAD7",&lurlutil::KEY_NUMPAD7,false)
			.addVariable("KEY_NUMPAD8",&lurlutil::KEY_NUMPAD8,false)
			.addVariable("KEY_NUMPAD9",&lurlutil::KEY_NUMPAD9,false)

		.endNamespace()
		;
}
