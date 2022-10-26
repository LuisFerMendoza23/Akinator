all: compile link run

compile:
	g++ -c Akinator.cpp -I"C:\SFML-2.5.1\include" -DSFML_STATIC

link:
	g++ Akinator.o -o Akinator -L"C:\SFML-2.5.1\lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows -lsfml-main

run:
	.\Akinator