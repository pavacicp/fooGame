#pragma once
#include "Area.hpp"

class Valley : public Area
{
public:
	Valley(Win &windoww);
	void draw();
	void update();
	void handleInput();
	void loadFiles();
};