#pragma once
#include <memory>
#include "Window.hpp"
#include "State.hpp"
#include "StateMachine.hpp"

class PlayState : public State
{
public:
	PlayState(Win &windoww, StateMachine &machinee);
	void update();
	void draw();
	void loadFiles();
	void handleInput();
private:
	std::unique_ptr<Level> level;
};