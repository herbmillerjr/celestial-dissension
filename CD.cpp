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
/*// end define constants //*/


/****\
|  Member Function Name: Game
|  Description: Constructor
\****/
Game::Game()
{
	log=new Logger(); log->Create("Opening new log for CD");
	SDL_Init(SDL_INIT_EVERYTHING);
	window=SDL_CreateWindow(gconst::Title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,gconst::ResX,gconst::ResY,SDL_WINDOW_SHOWN);

}
/** end member function Game **/

/****\
|  Member Function Name: ~Game
|  Description: Destructor
\****/
Game::~Game()
{
	SDL_Quit();
	log->Destroy("Destroy SDL and Game.");
	delete log;
}
/** end member function ~Game **/
