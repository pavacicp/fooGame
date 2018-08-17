#include "IntroState.hpp"
#include "State.hpp"
#include "Window.hpp"
#include "StateMachine.hpp"

IntroState::IntroState(Win &windoww, StateMachine &machinee) : State { windoww, machinee } 
{
	std::cout << "Init" << std::endl;
	loadFiles();
}
IntroState::~IntroState()
{
	std::cout << "Intit state destroyed" << std::endl;
}

void IntroState::update()
{
	//timer that shows logos after which intro is destroyed
}

void IntroState::draw()
{
	window.clear();
	window.draw(intro);
	window.display();
}

void IntroState::loadFiles()
{
	
}

void IntroState::handleInput()
{
	//if user presses escape switch state
}