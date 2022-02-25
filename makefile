flagsDev = -g -W -Wall -ansi -pedantic
libs = # -lpthread
libsLinux = $(libs) -lncurses
libsWindows = $(libs)
appFolder = build
aplication = build/ShellArchero
aplicationWindows = $(aplication).exe
mainObj = build/main.o
mainPrg = src/main.c

build:objMain
	gcc -o $(aplication) $(mainObj) -O3 $(libsLinux) 

windows:objMain
	gcc -o $(aplicationWindows) $(mainObj) -O3 $(libsWindows) 

dev:objMain
	gcc $(mainPrg) -c -o $(aplication) $(flagsDev) $(libsLinux)  

devWindows:objMain
	gcc -o $(aplicationWindows) $(mainObj) $(flagsDev) $(libsWindows) 

objMain:buildFolder
	gcc -c $(mainPrg)  -o $(mainObj) -O3

windowsLinux: buildFolder
	i686-w64-mingw32-gcc -c $(mainPrg)  -o $(mainObj) -O3
	i686-w64-mingw32-gcc -o $(aplicationWindows) $(mainObj) -O3 $(libsWindows)

buildFolder:
	@mkdir -p $(appFolder)

run:
	./$(aplication)
	

runWindows:
	@false
	@./$(aplicationWindows)

valgrind: build
	valgrind $(aplication)

clear: 
	rm -rf $(appFolder)
	rm -rf *.o

sprites2c: buildFolder
	gcc dev/sprites/sprites2c.c $(flagsDev) -o $(appFolder)/sprites2c 
	rm -f src/sprites.h
	./build/sprites2c > src/sprites.h
	

