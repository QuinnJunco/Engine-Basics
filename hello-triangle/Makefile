
SDLINCLUDEPATH = ../libraries/SDL3-3.2.8/x86_64-w64-mingw32/include
SDL_IMAGEINCLUDEPATH = ../libraries/SDL3_image-3.2.4/x86_64-w64-mingw32/include
SDLPATH = ../libraries/SDL3-3.2.8/x86_64-w64-mingw32/lib
SDL_IMAGEPATH = ../libraries/SDL3_image-3.2.4/x86_64-w64-mingw32/lib

INCLUDEPATH = -I./include -L$(SDLPATH) -lSDL3

# DEPRECATED
LIBS = -I$(SDLINCLUDEPATH) -I$(SDL_IMAGEINCLUDEPATH) -L$(SDLPATH) -L$(SDL_IMAGEPATH) -lSDL3 -lSDL3_image

all: hello.exe

hello.exe: main.o
	g++ -g -o hello.exe main.o $(INCLUDEPATH)

main.o: main.cpp
	g++ -g -c main.cpp $(INCLUDEPATH)

clean:
	del /Q *.o hello.exe