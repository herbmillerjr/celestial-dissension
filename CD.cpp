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

/*// define static members //*/
SDL_Window* CD::Game::window=NULL;
/*// end define static members //*/


/****\
|  Member Function Name: Game
|  Description: Constructor
\****/
Game::Game()
{
	log=new Logger(); log->Create("Opening new log for CD");
	SDL_Init(SDL_INIT_EVERYTHING);
	window=SDL_CreateWindow(gconst::Title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,gconst::ResX,gconst::ResY,SDL_WINDOW_SHOWN);
	game_over=false;
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



/*// main processing loop //*/

/****\
|  Member Function Name: Loop
|  Description: The game's message processing loop
\****/
void Game::Loop()
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		if (event.type==SDL_QUIT)
			game_over=true;
	}
}

/*// end main processing loop //*/



/*// accessors //*/

/****\
|  Member Function Name: getWindow
|  Description: Returns pointer to the main application window since
|    the renderer and other functions in other classes will need to
|    reference this.
\****/
SDL_Window* Game::getWindow()
{
	return window;
}

/****\
|  Member Function Name: GameOver()
|  Description: Returns value of game_over, true if we're exiting the application, else false
\****/
bool Game::GameOver() {return game_over;}

/*// end accessors //*/