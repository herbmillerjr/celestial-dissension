/****\
|  File Name: Renderer.hpp
|  Description: Declares singleton renderer class
\****/

/*// includes //*/
#include <SDL.h>
/*// end includes //*/


/****\
|  Class Name: Renderer
|  Description: Singleton class that holds the game's rendering context.
\****/
class Renderer
{
public:
	static SDL_Renderer* getContext();
private:
	Renderer();
	~Renderer();
	static Renderer *instance;
	SDL_Renderer *renderer;
};
/*** end class Renderer ***/