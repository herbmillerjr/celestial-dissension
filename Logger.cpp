/****\
|  File Name: Logger.cpp
|  Description: source for simplified log output class
|  Goal: Eventually make this a separate, cross-platform project
\****/

/*// includes //*/
#include "Logger.hpp"
#include "SDL.h"
/*// end includes //*/


/****\
|  Member Function Name: Info
|  Description: Output simple status message to console
\****/
Logger::Info(const char* msg)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,msg);
}

/****\
|  Member Function Name: Warn
|  Description: Output message when something unexpected happens
\****/
Logger::Warn(char* msg)
{
}

/****\
|  Member Function Name: Error
|  Description: Output message when something fatal happens
\****/
Logger::Error(char* msg)
{
}