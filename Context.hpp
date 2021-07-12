#pragma once

#include "Abstracts.hpp"
#include <memory>

class Window;
class Renderer
{
public:
	Renderer() { }
	virtual ~Renderer()=0;
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
	Context(Window &window,Renderer &renderer);
protected:
	Window &window;
	Renderer &renderer;
	static bool initialized;
};
