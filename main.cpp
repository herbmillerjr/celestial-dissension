/****\
|  File Name: main.cpp (Celestial Dissension)
|  Description: source containing application entry point
|  Goal: Keep as little in here as possible!
\****/

/*// includes //*/
#include "CD.hpp"
#include "SDL_image.h"
/*// end includes //*/


/****\
|  Function Name: main
|  Description: good old classic application entry point
|  Goal: Keep as little in here as possible!
\****/
int main(int argc, char* args[])
{
	CD::Game game;

		// Testing PNG rendering
		SDL_Renderer *ren=SDL_CreateRenderer(game.window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
		
		SDL_Texture* background=IMG_LoadTexture(ren, "background.png");
		SDL_Texture* texture=IMG_LoadTexture(ren, "skymeg.png");
		SDL_Texture* fire=IMG_LoadTexture(ren,"fire.png");
		
		
		// Testing PNG rendering

	SDL_Event state; bool quit=false;
	while(!quit)
	{
		while(SDL_PollEvent(&state))
		{
			if (state.type==SDL_QUIT)
				quit=true;
			SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_NONE);
			SDL_RenderCopy(ren,background,NULL,NULL);
			SDL_Rect dst;
			dst.x=50;
			dst.y=50;
			dst.w=256;
			dst.h=256;
			SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_BLEND);
			SDL_RenderCopy(ren,texture,NULL,&dst);
			SDL_SetTextureBlendMode(fire,SDL_BLENDMODE_ADD);
			dst.x=128;
			dst.y=128;
			dst.w=256;
			dst.h=256;
			SDL_RenderCopy(ren,fire,NULL,&dst);
			dst.x=112;
			dst.y=140;
			dst.w=256;
			dst.h=256;
			SDL_RenderCopy(ren,fire,NULL,&dst);
			dst.x=140;
			dst.y=112;
			dst.w=256;
			dst.h=256;
			SDL_RenderCopy(ren,fire,NULL,&dst);
			dst.x=200;
			dst.y=200;
			dst.w=256;
			dst.h=256;
			SDL_RenderCopy(ren,fire,NULL,&dst);
			SDL_RenderPresent(ren);
		}
	}
	
	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(fire);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(game.window);
	IMG_Quit();
	
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Leaving application entry point.");
	return 0;
}
/** end function main **/

