#pragma once
#include <memory>
#include "Window.hpp"
#include "State.hpp"
#include "StateMachine.hpp"
#include "Area.hpp"
#include "Valley.hpp"
#include "Common.hpp"

class PlayState : public State
{
public:
	PlayState(Win &windoww, StateMachine &machinee);
	void update();
	void draw();
	void loadFiles();
	void handleInput();

private:
	std::unique_ptr<Area> area;
	int partFrame = 0;

	LocalPlayer localPlayer;
	sf::Clock moveClock;
	sf::Time time;

	template <typename T>
	static std::unique_ptr<T> buildLevel(Win &window);
};

template <typename T>
std::unique_ptr<T> PlayState::buildLevel(Win &window)
{
	return std::unique_ptr<T> (new  T (window));
}

