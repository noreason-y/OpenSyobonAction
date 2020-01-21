.PHONY: all
all: SyobonAction

SyobonAction:libgame.a
	gcc -g main.cpp libgame.a  -o SyobonAction `sdl-config --libs` -lm -lSDL_gfx -lSDL_image -lSDL_mixer -lSDL_ttf -lstdc++ -DDEBUG

libgame.a: loadg.o DxLib.o
	gcc -g -c game_play.cpp game_graphic.cpp loadg.o DxLib.o `sdl-config --libs` -lm -lSDL_gfx -lSDL_image -lSDL_mixer -lSDL_ttf -lstdc++ -DDEBUG
	ar rcs -o libgame.a game_play.o game_graphic.o loadg.o DxLib.o 

loadg.o: loadg.cpp
	gcc -g -c loadg.cpp -DDEBUG

DxLib.o: DxLib.cpp
	gcc -g -c DxLib.cpp -DDEBUG

.PHONY: clean
clean:
	find ./ -type f -name "*.o" -delete
