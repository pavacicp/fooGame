#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "State.hpp"
#include "Common.hpp"

class IntroState : public State
{
public:
	IntroState(Win &windoww, StateMachine &machinee);
	~IntroState();
	void loadFiles();
	void update();
	void draw();
	void handleInput();
private:
	sf::Sprite intro;
	sf::Texture introTex;
};