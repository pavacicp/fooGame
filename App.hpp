#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "Common.hpp"
#include "Window.hpp"
#include "StateMachine.hpp"
#include "State.hpp"

class App
{
public:
	void run();

private:
	Win window;
	StateMachine machine;
	sf::Event event;
};