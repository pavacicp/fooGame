#include "Valley.hpp"

Valley::Valley(Win &windoww) : Area { windoww }
{
	loadFiles();
	std::cout << "+ Valey generated" << std::endl;
}

void Valley::draw()
{
	window.draw(terrain);
}
void Valley::update()
{
	
}
void Valley::handleInput()
{

}

void Valley::loadFiles()
{
	terrainTex.loadFromFile("img/cracks.png");
	terrain.setTexture(terrainTex);
}