SyobonAction:main.o loadg.o DxLib.o 
	gcc -g game_play.cpp main.o loadg.o DxLib.o  -o SyobonAction `sdl-config --libs` -lm -lSDL_gfx -lSDL_image -lSDL_mixer -lSDL_ttf -lstdc++ -DDEBUG

main.o:main.cpp game_play.cpp
	gcc -c -g main.cpp game_play.cpp 
	# gcc -g -c main.cpp game_play.cpp -DDEBUG
loadg.o:loadg.cpp
	gcc -g -c loadg.cpp -DDEBUG
DxLib.o:DxLib.cpp
	gcc -g -c DxLib.cpp -DDEBUG

.PHONY: clean
clean:
	find ./ -type f -name "*.o" -delete
