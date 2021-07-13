#pragma once

/****\
|  File Name: Menu.hpp
|  Description: Declares the game's main menu class
\****/

#include "CD.hpp"

namespace CD
{
	class Menu : public State
	{
	public:
		Menu();
		~Menu();
		void Present(Renderer &renderer) override;
	};
}
