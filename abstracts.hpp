//#ifndef ABSTRACTS_H
//#define ABSTRACTS_H

/****\
|  File Name: abstracts.hpp (abstract classes)
|  Description: Declaring base classes for game engine components
\****/

/*// includes //*/
#include <SDL.h>
//#include <SDL_image.h>
/*// end includes //*/


class State
{
public:
	
};


/****\
|  Class Name: Actor
|  Description: Base class that holds the main game object type.
|    Anything that is visible and interactive is an actor.
\****/
class Actor
{
public:
	virtual SDL_Texture* getTexture() =0;
private:
	SDL_Texture* texture;
};
/** end class Logger **/

//#endif