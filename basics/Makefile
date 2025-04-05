
SDLINCLUDEPATH = ../libraries/SDL3-3.2.8/x86_64-w64-mingw32/include
SDL_IMAGEINCLUDEPATH = ../libraries/SDL3_image-3.2.4/x86_64-w64-mingw32/include
SDLPATH = ../libraries/SDL3-3.2.8/x86_64-w64-mingw32/lib
SDL_IMAGEPATH = ../libraries/SDL3_image-3.2.4/x86_64-w64-mingw32/lib

INCLUDEPATH = -I./include -L$(SDLPATH) -L$(SDL_IMAGEPATH) -lSDL3 -lSDL3_image

# DEPRECATED
LIBS = -I$(SDLINCLUDEPATH) -I$(SDL_IMAGEINCLUDEPATH) -L$(SDLPATH) -L$(SDL_IMAGEPATH) -lSDL3 -lSDL3_image

all: basics.exe

basics.exe: Engine.o Texture.o HashTable.o main.o
	g++ -g -o basics.exe Engine.o Texture.o HashTable.o main.o $(INCLUDEPATH)

main.o: main.cpp
	g++ -g -c main.cpp $(INCLUDEPATH)

Texture.o: Texture.cpp
	g++ -g -c Texture.cpp $(INCLUDEPATH)

Engine.o: Engine.cpp
	g++ -g -c Engine.cpp $(INCLUDEPATH)

HashTable.o: HashTable.cpp
	g++ -g -c HashTable.cpp $(INCLUDEPATH)

clean:
	del /Q *.o basics.exe