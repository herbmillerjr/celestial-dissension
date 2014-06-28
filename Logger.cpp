/****\
|  File Name: Logger.cpp
|  Description: source for simplified log output class
|  Goal: Eventually make this a separate, cross-platform project
\****/

/*// includes //*/
#include "Logger.hpp"
#include "SDL.h"
/*// end includes //*/

/*// static definitions //*/
unsigned int Logger::refcount=0;
/*// end static definitions //*/


/****\
|  Member Function Name: Info
|  Description: Output simple status message to console
\****/
void Logger::Info(const char* msg)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,msg);
}

/****\
|  Member Function Name: Warn
|  Description: Output message when something unexpected happens
\****/
void Logger::Warn(char* msg)
{
}

/****\
|  Member Function Name: Error
|  Description: Output message when something fatal happens
\****/
void Logger::Error(char* msg)
{
}



/*// debug message section //*/

/****\
|  Member Function Name: Create
|  Description: Should be called every time an object is created.
|    Maintains a general, global reference count of allocated objects.
\****/
void Logger::Create(std::string msg)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,(((std::string)"(Memory) Create: ")+msg+" (Ref: "+std::to_string(++refcount)+")").c_str());
}

/****\
|  Member Function Name: Create
|  Description: Should be called every time an object is created.
|    Maintains a general, global reference count of allocated objects.
\****/
void Logger::Destroy(std::string msg)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,(((std::string)"(Memory) Destroy: ")+msg+" (Ref: "+std::to_string(--refcount)+")").c_str());
}
/*// end debug message section //*/