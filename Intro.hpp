/****\
|  File Name: Intro.hpp
|  Description: Declares the class that is the game's introduction state
\****/

/*// includes //*/
#include "abstracts.hpp"
/*// end includes //*/


/****\
|  Class Name: Intro
|  Description: The intro scene. The nostalgic and emotional part that
|    give me willys. :-D
\****/
class Intro:public State
{
public:
	static Intro* getInstance();
private:
	Intro();
	static Intro *instance;
};
/*** end class Intro ***/