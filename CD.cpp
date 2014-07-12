/****\
|  File Name: CD.cpp (Celestial Dissension)
|  Description: Main souce file implementing game's main class
\****/

/*// includes //*/
#include "CD.hpp"
#include "Renderer.hpp"
#include "Intro.hpp"
/*// end includes //*/

using namespace CD; // this is the only namespace this file should access

/*// define constants that could not be defined directly in header //*/
const char* gconst::Title="Celestial Dissension";
/*// end define constants //*/

/*// define static members //*/
Game* Game::instance=NULL;
SDL_Window* Game::window=NULL;
bool Game::game_over=false;
/*// end define static members //*/



/****\
|  Member Function Name: getInstance
|  Description: Calls constructor if there is no game object,
|    returns its own pointer if there is.
\****/
Game* Game::getInstance()
{
	if(!instance&&!game_over) {instance=new Game;}
	return instance;
}
/*** end member function getInstance ***/


/****\
|  Member Function Name: Game
|  Description: Constructor
\****/
Game::Game()
{
	log=new Logger(); log->Create("Opening new log for CD");
	SDL_Init(SDL_INIT_EVERYTHING);
	window=SDL_CreateWindow(gconst::Title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,gconst::ResX,gconst::ResY,SDL_WINDOW_SHOWN);
	state=Intro::getInstance();		// load the first scene
}
/*** end member function Game ***/


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
	// parse messages
	while(SDL_PollEvent(&event))
	{
		if (event.type==SDL_QUIT)
			GameOver();
	}
	// draw scene if were not in an end-game state
	// otherwise there is not renderer and no scene to draw
	if(!game_over){SDL_RenderPresent(Renderer::getContext());}
}

/****\
|  Member Function Name: GameOver()
|  Description: Deletes main game object, deallocating everything.
|    Sets game_over to true, which blocks recreation of game object.
|    Program has no choice but to exit (or crash if you wish to
|    insist on processing a NULL pointer).
\****/
void Game::GameOver()
{
	game_over=true;
	delete instance; instance=NULL;
}

/*// end main processing loop //*/



/*// accessors //*/

/****\
|  Member Function Name: getWindow
|  Description: Returns pointer to the main application window since
|    the renderer and other functions in other classes will need to
|    reference this.
\****/
SDL_Window* Game::getWindow() {return window;}
/*** end getWindow ***/

/****\
|  Member Function Name: getRenderer
|  Description: Returns pointer to rendering context
|    obtained from singleton Renderer. If one doesn't
|    exist, one is created.
\****/
SDL_Renderer* Game::getRenderer() {return Renderer::getContext();}
/*** end getRenderer ***/

/*// end accessors //*/