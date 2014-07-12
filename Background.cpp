/****\
|  File Name: Background.cpp
|  Description: Defines StarScrollBackground & TiledBackground derivatives of Background class
|    Background class itself does not have a definition because it is
|    purely virtual derivative of the Actor class
\****/

/*// includes //*/
#include "Background.hpp"
/*// end includes //*/



/*// begin class StarScrollBackground //*/

/****\
|  Member Function Name: StarScrollBackground
|  Description: Generates random star locations and
|    initial star layer textures
\****/
StarScrollBackground::StarScrollBackground()
{
}

/****\
|  Member Function Name: GetTexture
|  Description: 
\****/
SDL_Texture* StarScrollBackground::getTexture()
{
	return 0;
}

/*// end class StarScrollBackground //*/


/*// begin class TiledBackground //*/
/*// end class TiledBackground //*/
