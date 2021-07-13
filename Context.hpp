#pragma once

#include "Abstracts.hpp"
#include <memory>

class Window;
class Renderer
{
public:
	Renderer() { }
	virtual ~Renderer()=0;
	virtual void Clear()=0;
	virtual void Present()=0;
};

Renderer* NewSDLRenderer(Window *window);

class Window
{
public:
	Window() { }
	virtual ~Window()=0;
};

Window* NewSDLWindow(const std::string &title,const Dimensions &dimensions);

class Context
{
public:
	Context(Window &window,class Renderer &renderer);
	class Renderer& Renderer() const { return renderer; }
protected:
	Window &window;
	class Renderer &renderer;
	static bool initialized;
};
