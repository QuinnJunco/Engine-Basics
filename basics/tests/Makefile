
tests: main.exe

main.exe: buffer.o Events.o main.o Window.o glad.o
	g++ -g -o main.exe main.o buffer.o Events.o Window.o glad.o -lopengl32 -lgdi32

main.o: main.cpp
	g++ -g -c main.cpp

buffer.o: ../Buffer.cpp
	g++ -g -c ../Buffer.cpp

Events.o: ../Events.cpp
	g++ -g -c ../Events.cpp

Window.o: ../Window.cpp
	g++ -g -c ../Window.cpp -lopengl32 -lgdi32

glad.o: ../glad.c
	gcc -g -c ../glad.c

clean:
	del /Q *.o basics.exe
