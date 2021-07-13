#include <SDL2/SDL.h>
#include "Context.hpp"

Renderer::~Renderer() { }
Window::~Window() { }

bool Context::initialized=false;

Context::Context(Window &window,class Renderer &renderer): window(window),renderer(renderer)
{
	if (!initialized)
	{
		int initialized=SDL_Init(SDL_INIT_EVERYTHING) >= 0;
		//if (!initialized) throw std::bad_alloc("Failed to initialize graphics API");
	}
}
