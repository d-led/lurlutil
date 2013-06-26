#include <lua.hpp>
#include <iostream>

#include "lurlutil_lib.h"

#ifdef _MSC_VER
#define LURLUTIL __declspec(dllexport)
#else
#define LURLUTIL
#endif

extern "C" LURLUTIL int luaopen_lurlutil (lua_State* L) {
	register_lurlutil(L);
	return 1;
}
