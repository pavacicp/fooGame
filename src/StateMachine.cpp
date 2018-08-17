#include <memory>
#include "StateMachine.hpp"
#include "State.hpp"
#include "IntroState.hpp"
#include "PlayState.hpp"

void StateMachine::run(std::unique_ptr<State> state)
{
	states.push(std::move (state));
}

void StateMachine::draw()
{
	states.top()->draw();
}

void StateMachine::handleEvents()
{
	states.top()->handleEvents();
}

void StateMachine::update()
{
	states.top()->update();
}

void StateMachine::handleInput()
{
	states.top()->handleInput();
}