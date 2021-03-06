#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <SFML/Graphics/RenderWindow.hpp>

#define winName "fooGame"
#define defWinWidth 1920
#define defWinHeight 1080


class Win: public sf::RenderWindow
{
public:
	Win();
	void generateWindow();
	void loadConf();
	void generateConf();
	sf::Vector2f scal;
private:
	int framerateLimit = 60;
};