/****\
|  File Name: Renderer.cpp
|  Description: Defines singleton that encapsulates the
|    rendering context struct.
\****/

/*// includes //*/
#include "Renderer.hpp"
#include "CD.hpp"
/*// end includes //*/

/*// define static members //*/
Renderer *Renderer::instance=NULL;
/*// end define static members //*/



/****\
|  Member Function Name: getContext
|  Description: Returns the current rendering context,
|    creating one if needed.
\****/
SDL_Renderer* Renderer::getContext()
{
	if(!instance)
	{
		SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Creating renderer.");
		instance=new Renderer();
	}
	return instance->renderer;
}
/*** end member function getContext ***/

/****\
|  Member Function Name: Renderer
|  Description: Constructor that creates the rendering context.
\****/
Renderer::Renderer()
{
	renderer=SDL_CreateRenderer(CD::Game::getInstance()->getWindow(),-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
}
/*** end member function Renderer ***/

/****\
|  Member Function Name: ~Renderer
|  Description: Destructor that deletes the rendering context.
\****/
Renderer::~Renderer()
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Destroying renderer.");
	SDL_DestroyRenderer(renderer);
	//TODO: does SDL_DestroyRenderer NULL the pointer passed to it?
	//renderer=NULL;
}
/*** end member function ~Renderer ***/