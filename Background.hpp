/****\
|  File Name: Background.hpp
|  Description: Declares Background actor and StarScroll & TiledBackground derivatives
\****/

/*// includes //*/
#include "abstracts.hpp"
/*// end includes //*/


/****\
|  Class Name: Background
|  Description: Abstract class that other background image classes
|    are derived from
\****/
class Background:public Actor
{
public:
private:
};
/*** end class Background ***/


/****\
|  Class Name: StarScrollBackground
|  Description: Abstract class that other background image classes
|    are derived from
\****/
class StarScrollBackground:public Background
{
public:
	StarScrollBackground();
	~StarScrollBackground();
	SDL_Texture* getTexture();
private:
	SDL_Texture *texLowerStars, *texUpperStars, *texNebulae;
	unsigned short locationLowerStarsA, locationLowerStarsB,
		locationUpperStarsA, locationUpperStarsB,
		locationNebulaeA, locationNebulaeB;
};
/*** end class StarScrollBackground ***/

