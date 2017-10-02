#include "Common.hpp"
#include "Window.hpp"

#define wSprite 79
#define hSprite 135  // if size of sprite changes change these values
#define frameDensity 2

#define partWSprite 55
#define partHSprite 50
#define numOfAnimFrames 50

#define placeWSprite 50
#define placeHSprite 14

#include <iostream>
#include <cmath>
#include <SFML/System/Vector3.hpp>

void Object::loadTexture(std::string texLoc)
{
	objTex.loadFromFile(texLoc);
	objSpr.setTexture(objTex);
}

void Object::setSize(sf::Vector2f scal)
{
	//objSpr.setScale((defWinWidth*scal.x)/getLocalBounds().width, (defWinHeight*scal.y)/getLocalBounds().height);
}

void Object::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(objSpr, states);
}

//new
void Creature::update()
{
	updateMovement();
	updateAnimation();
}

void Creature::updateMovement()
{
	time = moveClock.getElapsedTime();
	sf::Vector2f moveDistance;

	if(targetPos.x < pos().x)
		moveDistance.x = -pixPerMsec * time.asMilliseconds();
	else if(targetPos.x > pos().x)
		moveDistance.x = pixPerMsec * time.asMilliseconds();

	if(targetPos.y < pos().y)
		moveDistance.y = -pixPerMsec * time.asMilliseconds();
	else if(targetPos.y > pos().y)
		moveDistance.y = pixPerMsec * time.asMilliseconds();

	//solves problem when character keeps jumping back and forth
	if(moveDistance.x > 0)
	{
		if(placeSpr.getPosition().x + moveDistance.x > targetPos.x)
			moveDistance.x = targetPos.x - placeSpr.getPosition().x;
	}
	else if(moveDistance.x < 0)
	{
		if(placeSpr.getPosition().x + moveDistance.x < targetPos.x)
			moveDistance.x = targetPos.x - placeSpr.getPosition().x;
	}


	if(moveDistance.y > 0)
	{
		if(placeSpr.getPosition().y + moveDistance.y > targetPos.y)
			moveDistance.y = targetPos.y - placeSpr.getPosition().y;
	}
	else if(moveDistance.y < 0)
	{
		if(placeSpr.getPosition().y + moveDistance.y < targetPos.y)
			moveDistance.y = targetPos.y - placeSpr.getPosition().y;
	}


	placeSpr.move(moveDistance.x , moveDistance.y);
	//partSpr.move(moveDistance.x , moveDistance.y);
	charSpr.move(moveDistance.x , moveDistance.y);

	moveClock.restart();
}

void LocalPlayer::handleInput(sf::RenderWindow &window)
{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		moveClock.restart();
		targetPos = sf::Mouse::getPosition(window);
		rotateSprite();
	}
}

void Creature::loadFiles(std::string texxFold)
{
	filesPath = texxFold;

	charSpr.setOrigin(wSprite / 2, hSprite / 2);

	//loadParticleTex
	//partTex.loadFromFile(filesPath + "particle.png");
	//partSpr.setTexture(partTex);
	//partSpr.setOrigin(partWSprite / 2, partHSprite / 2);

	placeTex.loadFromFile(filesPath + "place.png");
	placeSpr.setTexture(placeTex);
	placeSpr.setOrigin(placeWSprite / 2, placeHSprite / 2);

	charSpr.setPosition(placeSpr.getPosition().x, placeSpr.getPosition().y - placeHSprite/2 - partHSprite/4 - hSprite/2); // remove
	//partSpr.setPosition(placeSpr.getPosition().x, placeSpr.getPosition().y - placeHSprite/2 - partHSprite/4);

}

void Creature::rotateSprite()
{

	sf::Vector3f len;
	len.x = pos().x  - targetPos.x;
	len.y = pos().y  - targetPos.y;
	len.z = sqrt(len.x * len.x + len.y * len.y);
	moveAngle = asin(len.y / len.z) + M_PI/2;

	if(targetPos.x < pos().x)
		moveAngle = 2 * M_PI - moveAngle;

	sf::Vector2i spriteSelector;

	spriteSelector.x = angle(true) / frameDensity;
	spriteSelector.y = 0;

	if((int)moveAngle % frameDensity > 0.5)
		spriteSelector.x++;

	charTex.loadFromFile((filesPath + "char.png"), sf::IntRect(wSprite * spriteSelector.x, hSprite * spriteSelector.y, wSprite, hSprite));
	charSpr.setTexture(charTex);
}

void Creature::updateAnimation()
{
	//partSpr.setTextureRect(sf::IntRect(animationCounter * partWSprite, 0, partWSprite, partHSprite));
	placeSpr.setTextureRect(sf::IntRect(animationCounter * placeWSprite, 0, placeWSprite, placeHSprite));
	animationCounter++;

	if(animationCounter >= numOfAnimFrames)
		animationCounter = 0;

}

sf::Vector2i Creature::pos()
{
	return static_cast<sf::Vector2i> (placeSpr.getPosition());
}

float Creature::angle(bool degrees)
{
	return (degrees ? moveAngle * (180/M_PI) : moveAngle);
}

void Creature::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(placeSpr, states);
	//target.draw(partSpr, states);
	target.draw(charSpr, states);
}