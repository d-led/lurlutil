include 'premake'

lua = assert(dofile 'premake/recipes/lua.lua')
OS = os.get()

make_solution 'lurlutil'

defines {
	'_SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS',
}

includedirs {
	'./rlutil',
	'./LuaBridge-1.0.2'
}

includedirs {
	lua.includedirs[OS],
}

libdirs {
	lua.libdirs[OS]
}

make_shared_lib( 'lurlutil',
	{
		'./src/*.h',
		'./src/*.cpp'
	}
)

language "C++"
targetprefix ''

links {
	lua.links[OS]
}

targetdir '.'


newaction {
	trigger     = "test",
	description = "Start the test script",
	execute     = function() os.execute [[ lua src/test.lua ]] end
}
