/****\
|  File Name: CD.hpp (Celestial Dissension)
|  Description: Main header declaring game's namespace and central class
|  Usage: This most likely will need to be included in all source files
\****/


/*// includes //*/
#include "SDL.h"
#include "Logger.hpp"
/*// end includes //*/


/****\
|  Namespace Name: CD (Celestial Dissension)
|  Description: The game's "global" namespace
\****/
namespace CD
{
	namespace gconst
	{
		/*// define screen resolution //*/
		const unsigned short ResX=800;
		const unsigned short ResY=600;
		/*// end define screen resolution //*/

		/*// define game title //*/
		extern const char* Title;
		// Quote: "Also, don't use std::string for string constant expressions - use const char[] instead."
		//   Ref: http://programmers.stackexchange.com/questions/149350/how-to-nicely-use-constant-stdstring-in-c
		// Ref: http://stackoverflow.com/questions/2879548/is-it-appropriate-to-set-a-value-to-a-const-char-in-the-header-file
		// Ref: http://www.cplusplus.com/forum/general/21368/
		/*// end define name //*/
	}


	/****\
	|  Class Name: Game
	|  Description: This is the main "game" class.
	|  Usage: Create an instance of this before anything else.
	|  To Do: Limit number of instances of this class?
	\****/
	class Game
	{
	public:
		Game();
		~Game();
		SDL_Window *window;
	private:
		Logger *log;
	};
	/** end class Game **/
}
/** end namespace CD **/