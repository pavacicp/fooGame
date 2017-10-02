#pragma once
#include "Window.hpp"
#include "Area.hpp"
#include "Common.hpp"

class Area
{
public:
	Area(Win &windoww);
	virtual ~Area() = default;

	Area(const Area&) = delete;
	Area &operator = (const Area&) = delete;

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void handleInput() = 0;
	virtual void loadFiles() = 0;
protected:
	Win &window;
	sf::Sprite terrain;
	sf::Texture terrainTex;
};