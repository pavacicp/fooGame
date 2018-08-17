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
	std::cout << img_folder<< '\n';
	terrainTex.loadFromFile(img_folder + "/cracks.png");
	terrain.setTexture(terrainTex);
}
