#include "lurlutil_lib.h"

#include <LuaBridge.h>
#include <rlutil.h>
#include <RefCountedPtr.h>

namespace lurlutil {
	namespace lua {

	}
}

void register_lurlutil (lua_State* L) {
	luabridge::getGlobalNamespace(L)
		.beginNamespace("lurlutil")
		.endNamespace()
		;
}
