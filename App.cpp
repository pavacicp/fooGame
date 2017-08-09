#include "App.hpp"
#include "StateMachine.hpp"
#include "Common.hpp"
#include "IntroState.hpp"
#include "PlayState.hpp"


void App::run()
{
	//later change to intro state
	machine.run(StateMachine::build<PlayState> (window, machine));
	while(window.isOpen())
	{
		machine.update();
		machine.draw();
		machine.handleEvents();
		machine.handleInput();
		
	}

		
}
