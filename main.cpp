#include "SDL2/SDL.h"

/****\
|
\****/
int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_Window *win = SDL_CreateWindow("Hellow World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	
	SDL_Delay(2000);
	
	SDL_Quit();
	
	return 0;
}
