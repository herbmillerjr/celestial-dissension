#pragma once

/****\
|  File Name: CD.hpp (Celestial Dissension)
|  Description: Main header declaring game's namespace and central class
|  Usage: This most likely will need to be included in all source files
\****/

#include "Logger.hpp"
#include "Abstracts.hpp"
#include "Context.hpp"
#include <memory>


/****\
|  Namespace Name: CD (Celestial Dissension)
|  Description: The game's "global" namespace
\****/
namespace CD
{
	enum EventType
	{
		CONNECTION,
		RENDERING_CONNECTION
	};
	
	class State
	{
	public:
		virtual void Present(Renderer &renderer)=0;
	};

	/****\
	|  Class Name: Game
	|  Description: This is the main "game" class.
	|  Usage: Create an instance of this before anything else.
	|  To Do: Limit number of instances of this class?
	\****/
	class Game
	{
	public:
		Game(Context &context);
		~Game();
		void Start(SDL_Renderer *renderer);
		const State& CurrentState() const { return *currentState.get(); }
		void operator()();
	protected:
		Logger log;
		Context &context;
		std::unique_ptr<State> currentState;
	};
}
