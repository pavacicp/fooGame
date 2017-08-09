#pragma once
#include <SFML/Window/Event.hpp>
#include "State.hpp"
#include "Window.hpp"
#include "StateMachine.hpp"

class State
{
public:
	State(Win &windoww, StateMachine &machinee);
	virtual ~State() = default;

	State(const State&) = delete;
	State& operator = (const State&) = delete;

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void loadFiles() = 0;
	virtual void handleEvents();
	virtual void handleInput() = 0;

protected:
	Win &window;
	StateMachine &machine;
	sf::Event event;

};