#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string.h>

class Object : public sf::Sprite, public sf::Texture
{
public:
	void loadTexture(std::string textureLoc);
	void setSize(sf::Vector2f scal, int width, int height);
};