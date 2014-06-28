#include "SDL2/SDL.h"

/****\
|
\****/
int main(int argc, char* args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	
	SDL_Window *win = SDL_CreateWindow("Hellow World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	
	SDL_Event state;
	bool quit=false;
	while(!quit)
	{
		while(SDL_PollEvent(&state))
		{
			if (state.type==SDL_QUIT)
				quit=true;
			
		}
	}
	
	SDL_Quit();
	
	return 0;
}