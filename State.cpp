#include "State.hpp"

State::State(Win &windoww, StateMachine &machinee) :	window { windoww }, 
																	machine{ machine }
{
	
}

void State::handleEvents()
{
	while(window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			window.close();
	}
}