/****\
|  File Name: CD.cpp (Celestial Dissension)
|  Description: Main souce file implementing game's main class
\****/

#include "CD.hpp"
#include "Menu.hpp"

using namespace CD;

class BlankState : public State
{
public:
	void Present(Renderer &renderer)
	{
		renderer.Clear();
	};
};

//std::string Game::title="Celestial Dissension";

/****\
|  Member Function Name: Game
|  Description: Constructor
\****/
Game::Game(Context &context): context(context),currentState(nullptr)
{
	currentState=std::make_unique<BlankState>();

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Push event");
	SDL_Event startEvent;
	SDL_zero(startEvent);
	startEvent.type=SDL_USEREVENT;
	startEvent.user={
		.code=EventType::RENDERING_CONNECTION,
		.data1=new Connection<SDL_Renderer*>(std::bind(&Game::Start,this,std::placeholders::_1)),
		.data2=nullptr
	};
	SDL_PushEvent(&startEvent);
	//log=new Logger(); log->Create("Opening new log for CD");
}

/****\
|  Member Function Name: ~Game
|  Description: Destructor
\****/
Game::~Game()
{
	//log->Destroy("Destroy SDL and Game.");
}

void Game::Start(SDL_Renderer *renderer)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Make a menu");
	//currentState=std::make_unique<Menu>();
}

void Game::operator()()
{
	currentState->Present(context.Renderer());
	context.Renderer().Present();
}
