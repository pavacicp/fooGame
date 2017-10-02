#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>

namespace sf
{
	class RenderWindow;
}

class Object : public sf::Drawable
{
public:
	virtual void loadTexture(std::string texLoc);
	void setSize(sf::Vector2f scal);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Texture objTex;
	sf::Sprite objSpr;

};

class Creature : public sf::Drawable
{
public:
	void loadFiles(std::string filesPath);
	void update();

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void updateMovement();
	void updateAnimation();
	void rotateSprite();
	//info
	sf::Vector2i pos();
	float angle(bool degrees);
	float pixPerMsec = 0.07;

	sf::Vector2i targetPos;
	sf::Sprite placeSpr, charSpr;
	sf::Texture placeTex, charTex;

	sf::Time time;
	sf::Clock moveClock;

	std::string filesPath;

	float moveAngle = 0;
	short int animationCounter = 0;

};

class LocalPlayer : public Creature
{
public:
	void handleInput(sf::RenderWindow &window);
};