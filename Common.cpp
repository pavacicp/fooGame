#include "Common.hpp"
#define defWinWidth 1920
#define defWinHeight 1080

void Object::loadTexture(std::string textureLoc)
{
	loadFromFile(textureLoc);
	setTexture(*this);
}

void Object::setSize(sf::Vector2f scal, int width, int height)
{
	setScale((defWinWidth*scal.x)/getLocalBounds().width, (defWinHeight*scal.y)/getLocalBounds().height);
}