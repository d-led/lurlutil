_G.package.path=_G.package.path..[[;./?.lua;./?/?.lua]]
assert ( require 'premake.quickstart' )

make_solution 'lurlutil'

includedirs { 
	'./rlutil',
	'./LuaBridge-1.0.2'
}

make_shared_lib( 'lurlutil',
	{
		'./src/*.h',
		'./src/*.cpp'
	}
)
language "C++"
targetprefix ''
targetdir '.'

-- links
configuration 'macosx'
	links { 'lua' }
	targetextension '.so'
configuration 'linux'
	links { 'lua5.1-c++' }
	includedirs { '/usr/include/lua5.1' }
configuration 'windows'
	links { "lua5.1" }
configuration { '*' }

-- 	newaction {
-- 		trigger     = "test",
-- 		description = "Start the test script",
-- 		--execute     = os.execute [[ src/test.lua ]]
-- 	}