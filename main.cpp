/****\
|  File Name: main.cpp (Celestial Dissension)
|  Description: source containing application entry point
|  Goal: Keep as little in here as possible!
\****/

/*!
 * \class Logger
 * \brief Contains application entry point.
 * \note Keep as little in here as possible
 */

#include <SDL2/SDL.h>
#include "CD.hpp"
#include "Context.hpp"

const unsigned short windowWidth=1280;
const unsigned short windowHeight=1024;
const char *title="Celestial Dissension";

enum ExitCodes
{
	OK,
	INITIALIZATION_FAILED
};

/*!
 * fn main
 * \brief Good old classic application entry point
 * \param argument_count 
\****/
int main(int argument_count,char* arguments[])
{
	std::unique_ptr<Window> window;
	std::unique_ptr<Renderer> renderer;
	
	try
	{
		window.reset(NewSDLWindow(title,Dimensions(1280,1024)));
		renderer.reset(NewSDLRenderer(window.get()));
	}
	
	catch (const std::bad_alloc &exception())
	{
		return INITIALIZATION_FAILED;
	}

	Context context(*window,*renderer);

	bool running=true;
	SDL_Event event;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_USEREVENT:
					SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"User event received");
					switch (event.user.code)
					{
						case CD::EventType::CONNECTION:
							break;
						case CD::EventType::RENDERING_CONNECTION:
							//(*static_cast<Connection<SDL_Renderer*>*>(event.user.data1))(renderer.get());
							//delete event.user.data1;
							break;
					}
					break;
				case SDL_QUIT:
					SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Quit event received");
					running=false;
					break;
			}
		}
		
		/*SDL_SetRenderDrawColor(renderer.get(),0,0,0,0);
		SDL_RenderClear(renderer.get());
		game.CurrentState().Present(renderer.get());
		//SDL_RenderCopy(renderer, texture, NULL, NULL); ?
		SDL_RenderPresent(renderer.get());*/
	}

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Leaving application entry point.");
	return OK;
}

