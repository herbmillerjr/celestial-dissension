/****\
|  File Name: MenuItem.hpp
|  Description: Declares abstract base class for game characters and objects
\****/

/*// includes //*/
#include "abstracts.hpp"
/*// end includes //*/


/****\
|  Class Name: MenuItem
|  Description: Base class that holds the main game object type.
|    Anything that is visible and interactive is an actor.
\****/
class MenuItem:public Actor
{
public:
	SDL_Texture* getTexture();
private:
};
/*** end class MenuItem ***/