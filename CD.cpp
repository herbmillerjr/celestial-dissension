/****\
|  File Name: CD.cpp (Celestial Dissension)
|  Description: Main souce file implementing game's main class
\****/

/*// includes //*/
#include "CD.hpp"
/*// end includes //*/

using namespace CD; // this is the only namespace this file should access

/*// define constants that could not be defined directly in header //*/
const char* gconst::Title="Celestial Dissension";
/*// end define constans //*/


/****\
|  Member Function Name: Game
|  Description: Constructor
\****/
Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window=SDL_CreateWindow(gconst::Title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,gconst::ResX,gconst::ResY,SDL_WINDOW_SHOWN);
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"This should show on command line.");

}
/** end member function Game **/

/****\
|  Member Function Name: ~Game
|  Description: Destructor
\****/
Game::~Game()
{
	SDL_Quit();
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Destroy SDL and Game.");
}
/** end member function ~Game **/
