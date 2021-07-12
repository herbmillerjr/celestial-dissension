/****\
|  File Name: CD.hpp (Celestial Dissension)
|  Description: Main header declaring game's namespace and central class
|  Usage: This most likely will need to be included in all source files
\****/


#include "SDL2/SDL.h"
#include "Logger.hpp"
#include "Abstracts.hpp"
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
	
	/****\
	|  Class Name: Game
	|  Description: This is the main "game" class.
	|  Usage: Create an instance of this before anything else.
	|  To Do: Limit number of instances of this class?
	\****/
	class Game : Generic::Game
	{
	public:
		Game(const Dimensions &dimensions);
		~Game();
		void Start(SDL_Renderer *renderer);
		const Dimensions& Viewport() const override { return dimensions; }
		const std::string& Title() const override { return title; }
		const State& CurrentState() const { return *currentState.get(); }
	protected:
		Dimensions dimensions;
		static std::string title;
		Logger log;
		std::unique_ptr<State> currentState;
	};
}
