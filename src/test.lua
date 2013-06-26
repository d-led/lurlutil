assert(require 'lurlutil')

local function waitkey() print "Press any key to continue..." lurlutil.anykey() end

---main---
print "Welcome to rlutil test program."
waitkey()

print "Test 1: Colors"
for i = 0 , 15 do
	lurlutil.setColor(i)
	io.write(i.." ")
end
print ''

print "You should see numbers 0-15 in different colors."
waitkey()

lurlutil.cls()
print "Test 2: Clear screen"
print "The colors should now be gone."
waitkey()

print "Test 3: Cursor hiding"
lurlutil.hidecursor()
print "The cursor should now be invisible."
waitkey()

print "Test 4: Cursor showing"
lurlutil.showcursor()
print "The cursor should now be visible again."
waitkey()

lurlutil.cls()
print "Test 5: Cursor positioning"
lurlutil.locate(16,6) io.write "(16,6)"
lurlutil.locate(4,3) io.write "(4,3)"
lurlutil.locate(8,8) io.write "(8,8)"
print "You should see three coordinates in their specified locations."
waitkey()

--Test 6
local x = 7
local y = 7
local cnt = 0
while true do
	lurlutil.cls()
	print "Test 6: Blocking keyboard input"
	print "You should be able to move the '@' character with WASD keys."
	print "Hit Space to continue to the next test."
	print ("Turn count: " .. cnt)
	lurlutil.locate(x,y) io.write "@" -- Output player
	local k = lurlutil.getch() -- Get character
	if k == 'a' then x=x-1
	elseif k == 'd' then x=x+1
	elseif k == 'w' then y=y-1
	elseif k == 's' then y=y+1
	elseif k == ' ' then break
	end
	cnt=cnt+1
end

--Test 7
local x = 7
local y = 7
local cnt = 0
lurlutil.hidecursor()
lurlutil.cls()
print "Test 7: Non-blocking keyboard input"
print "You should be able to move the '@' character with WASD keys."
print "Hit Space to continue to the next test."
print ("Turn count: " .. cnt)
lurlutil.locate(x,y) io.write "@" -- Output player
while true do
	lurlutil.locate(1,4) print ("Turn count: " .. cnt )
	if lurlutil.kbhit() then
		local k = lurlutil.getch() -- Get character
		lurlutil.locate(x,y) io.write " " -- Erase player
		if k == 'a' then x=x-1
		elseif k == 'd' then x=x+1
		elseif k == 'w' then y=y-1
		elseif k == 's' then y=y+1
		elseif k == ' ' then break
		end
		lurlutil.locate(x,y) io.write "@" -- Output player
		cnt=cnt+1
	end
	lurlutil.showcursor()
end

-- Test 8
local x = 7
local y = 7
lurlutil.cls()
lurlutil.hidecursor()
print "Test 8: Arrow keys"
print "You should be able to move the '@' character with arrow keys."
print "Hit Escape to continue to the next test."
	lurlutil.gotoxy(x,y) io.write "@" -- Output player
	while true do
	if lurlutil.kbhit() then
	local k = lurlutil.getkey() -- Get character
	lurlutil.gotoxy(x,y) io.write " " -- Erase player
--------if (k == lurlutil.KEY_LEFT) --x
--------elseif (k == lurlutil.KEY_RIGHT) ++x
--------elseif (k == lurlutil.KEY_UP) --y
--------elseif (k == lurlutil.KEY_DOWN) ++y
--------elseif (k == lurlutil.KEY_ESCAPE) break
--------gotoxy(x,y) print "@" // Output player
--------fflush(stdout)
------}
----}
--}

--lurlutil.cls()
--print "Test 9: Delay"
--print "Next numbers should appear rapidly after each other (but not instantly)."
--lurlutil.msleep(500)
--for (float t = 0 t <= 4 t += 0.33333333f) {
----std::cout << t << "s"
----lurlutil.msleep(333)
--}
waitkey()

--lurlutil.cls()
--print "Test 10: Terminal Dimensions"
--print "You should see the size in character rows and columns of your terminal window."
--std::cout << lurlutil.trows() << " Rows"
--std::cout << lurlutil.tcols() << " Columns"
waitkey()
--
--print "All tests done. Bye!"
--return 0
--}