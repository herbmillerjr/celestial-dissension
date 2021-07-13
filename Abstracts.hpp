#pragma once

/****\
|  File Name: abstracts.hpp (abstract classes)
|  Description: Declaring base classes for game engine components
\****/

#include <SDL2/SDL.h>
#include <functional>
#include <string>

template <typename T>
class Connection
{
public:
	Connection(std::function<void(T)> target) : target(target) { }
	void operator()(T payload) { target(payload); }
protected:
	std::function<void(T)> target;
};

/****\
|  Class Name: Actor
|  Description: Base class that holds the main game object type.
|    Anything that is visible and interactive is an actor.
\****/
/*class Actor
{
public:
	virtual SDL_Texture* getTexture() =0;
private:
	SDL_Texture* texture;
};*/
/** end class Logger **/

//#endif

class Dimensions
{
public:
	Dimensions(const unsigned int width,const unsigned int height) : width(width), height(height) { }
	unsigned int Width() const { return width; };
	unsigned int Height() const { return height; };
protected:
	unsigned int width;
	unsigned int height;
};
