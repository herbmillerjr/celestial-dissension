#include "Context.hpp"

class WindowSDL;
class RendererSDL: public Renderer
{
public:
	RendererSDL(const WindowSDL &window);
	~RendererSDL() override;
	void Clear() override;
	void Present() override;
protected:
	SDL_Renderer *renderer;
};

class WindowSDL: public Window
{
public:
	WindowSDL(const std::string &title,const Dimensions &dimensions);
	~WindowSDL() override;
protected:
	friend RendererSDL::RendererSDL(const WindowSDL &window);
	SDL_Window* operator()() const { return window; }
	SDL_Window *window;
};

RendererSDL::RendererSDL(const WindowSDL &window)
{
	renderer=SDL_CreateRenderer(window(),-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	//if (!renderer) throw std::bad_alloc("Failed to create renderer");
};

RendererSDL::~RendererSDL()
{
	SDL_DestroyRenderer(renderer);
}

void RendererSDL::Clear()
{
	SDL_SetRenderDrawColor(renderer,0,0,0,0);
	SDL_RenderClear(renderer);
}

void RendererSDL::Present()
{
	SDL_RenderPresent(renderer);
}

WindowSDL::WindowSDL(const std::string &title,const Dimensions &dimensions): window(nullptr)
{
	window=SDL_CreateWindow(title.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,dimensions.Width(),dimensions.Height(),SDL_WINDOW_SHOWN);
	//if (!window) throw std::bad_alloc("Failed to create window");
};

WindowSDL::~WindowSDL()
{
	SDL_DestroyWindow(window);
}

Window* NewSDLWindow(const std::string &title,const Dimensions &dimensions)
{
	return new WindowSDL(title,dimensions);
}

Renderer* NewSDLRenderer(Window *window)
{
	return new RendererSDL(dynamic_cast<const WindowSDL&>(*window));
}

