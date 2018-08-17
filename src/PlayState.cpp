#include "PlayState.hpp"
#include <cmath>


PlayState::PlayState(Win &windoww, StateMachine &machinee) : State { windoww, machinee }
{
	//delete later, just to get one level working
	area = PlayState::buildLevel<Valley>(window);
	loadFiles();
}

void PlayState::update()
{
	area->update();
	localPlayer.update();

	handleInput();
	draw();
}

void PlayState::draw()
{
	window.clear();

	area->draw();

	window.draw(localPlayer);
	window.display();
}

void PlayState::loadFiles()
{
	area->loadFiles();
	localPlayer.loadFiles(img_folder + "/char/mage/");
}

void PlayState::handleInput()
{
	area->handleInput();
	localPlayer.handleInput(window);
}
