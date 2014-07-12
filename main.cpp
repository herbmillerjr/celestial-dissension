/****\
|  File Name: main.cpp (Celestial Dissension)
|  Description: source containing application entry point
|  Goal: Keep as little in here as possible!
\****/

/*// includes //*/
#include "CD.hpp"
/*// end includes //*/


/****\
|  Function Name: main
|  Description: good old classic application entry point
|  Goal: Keep as little in here as possible!
\****/
int main(int argc, char* args[])
{
	while(CD::Game::getInstance())	{CD::Game::getInstance()->Loop();}
	
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Leaving application entry point.");
	return 0;
}
/*** end function main ***/

