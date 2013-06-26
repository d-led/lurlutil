assert(require 'lurlutil')

local function waitkey() print "Press any key to continue..."; lurlutil.anykey() end

---main---
print "Welcome to rlutil test program."
waitkey()

print "Test 1: Colors"
for i = 0 , 15 do
	lurlutil.setColor(i)
	io.write(i.." ")
end
print ''

--print "You should see numbers 0-15 in different colors."
--waitkey;

--rlutil::cls();
--print "Test 2: Clear screen"
--print "The colors should now be gone."
--waitkey;

--print "Test 3: Cursor hiding"
--rlutil::hidecursor();
--print "The cursor should now be invisible."
--waitkey;

--print "Test 4: Cursor showing"
--rlutil::showcursor();
--print "The cursor should now be visible again."
--waitkey;

--rlutil::cls();
--print "Test 5: Cursor positioning"
--rlutil::locate(16,6); print "(16,6)";
--rlutil::locate(4,3); print "(4,3)";
--rlutil::locate(8,8); print "(8,8)";
--print "You should see three coordinates in their specified locations."
--waitkey;

--// Test 6
--{--int x = 7; int y = 7; unsigned int cnt = 0;
----while (true) {
------rlutil::cls();
------print "Test 6: Blocking keyboard input"
------print "You should be able to move the '@' character with WASD keys."
------print "Hit Space to continue to the next test."
------print "Turn count: " << cnt << std::endl;
------rlutil::locate(x,y); print "@"; // Output player
------char k = getch(); // Get character
------if (k == 'a') --x;
------else if (k == 'd') ++x;
------else if (k == 'w') --y;
------else if (k == 's') ++y;
------else if (k == ' ') break;
------cnt++;
----}
--}

--// Test 7
--{--int x = 7; int y = 7; unsigned int cnt = 0;
----rlutil::hidecursor();
----rlutil::cls();
----print "Test 7: Non-blocking keyboard input"
----print "You should be able to move the '@' character with WASD keys."
----print "Hit Space to continue to the next test."
----print "Turn count: " << cnt << std::endl;
----rlutil::locate(x,y); print "@" // Output player
----while (true) {
------rlutil::locate(1,4); print "Turn count: " << cnt;
------if (kbhit()) {
--------char k = getch(); // Get character
--------rlutil::locate(x,y); print " "; // Erase player
--------if (k == 'a') --x;
--------else if (k == 'd') ++x;
--------else if (k == 'w') --y;
--------else if (k == 's') ++y;
--------else if (k == ' ') break;
--------rlutil::locate(x,y); print "@"; // Output player
------}
------cnt++;
------fflush(stdout);
----}
----rlutil::showcursor();
--}

--// Test 8
--{--int x = 7; int y = 7;
----rlutil::cls();
----rlutil::CursorHider curs;
----print "Test 8: Arrow keys"
----print "You should be able to move the '@' character with arrow keys."
----print "Hit Escape to continue to the next test."
----gotoxy(x,y); print "@" // Output player
----while (true) {
------if (kbhit()) {
--------int k = rlutil::getkey(); // Get character
--------gotoxy(x,y); print " "; // Erase player
--------if (k == rlutil::KEY_LEFT) --x;
--------else if (k == rlutil::KEY_RIGHT) ++x;
--------else if (k == rlutil::KEY_UP) --y;
--------else if (k == rlutil::KEY_DOWN) ++y;
--------else if (k == rlutil::KEY_ESCAPE) break;
--------gotoxy(x,y); print "@"; // Output player
--------fflush(stdout);
------}
----}
--}

--rlutil::cls();
--print "Test 9: Delay"
--print "Next numbers should appear rapidly after each other (but not instantly)."
--rlutil::msleep(500);
--for (float t = 0; t <= 4; t += 0.33333333f) {
----std::cout << t << "s"
----rlutil::msleep(333);
--}
--waitkey;

--rlutil::cls();
--print "Test 10: Terminal Dimensions"
--print "You should see the size in character rows and columns of your terminal window."
--std::cout << rlutil::trows() << " Rows"
--std::cout << rlutil::tcols() << " Columns"
--waitkey;
--
--print "All tests done. Bye!"
--return 0;
--}