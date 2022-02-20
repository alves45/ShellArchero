build:objMain
	gcc -o build/ShellArchero build/main.o -O3 -lncurses 

windows:objMain
	gcc -o build/ShellArchero.exe build/main.o -O3

dev:objMain
	gcc src/main.c -c -o build/ShellArchero -W -Wall -ansi -pedantic -lncurses 

devWindows:objMain
	gcc -o build/ShellArchero.exe build/main.o -W -Wall -ansi -pedantic

objMain:buildFolder
	gcc -c src/main.c  -o build/main.o -O3

windowsLinux: buildFolder
	i686-w64-mingw32-gcc -c src/main.c  -o build/main.o -O3
	i686-w64-mingw32-gcc -o build/ShellArchero.exe build/main.o -O3

buildFolder:
	@mkdir -p build

valgrind: build
	valgrind build/ShellArchero

clear:
	rm -rf build