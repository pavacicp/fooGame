#include "Window.hpp"
#define defWinWidth 1920
#define defWinHeight 1080

Win::Win()
{
	scal.x = 0.41;
	scal.y = 0.55;
	loadConf();
	generateWindow();
}

void Win::loadConf()
{
	std::ifstream file("mainconfig.conf");
	int lineNum = 0;

	std::cout << "O mainconfig: loading settings" << std::endl;

	if(!file)
	{
		std::cout << "X mainconfig: Error, mainconfig not found, running at default settings" << std::endl;
		return;
	}

	std::string line;
	while(std::getline(file, line))
	{
		lineNum++;
		std::istringstream iss(line);
		std::string valueS, key;

		std::getline(iss, key, '=');
		std::getline(iss, valueS, '\n');


		if(!key.compare("height_scaling"))
		{
			scal.x = std::stof(valueS);
			std::cout << "1 mainconfig: h scaling loaded" << std::endl;
		}
		else if(!key.compare("width_scaling"))
		{
			scal.y = std::stof(valueS);
			std::cout << "1 mainconfig: w scaling loaded" << std::endl;
		}
		else if(!key.compare("framerate_limit"))
		{
			framerateLimit = std::stof(valueS);
			std::cout << "1 mainconfig: frame limit loaded" << std::endl;
		}
		else
			std::cout << "X mainconfig: ERROR, undefined key at line: " << lineNum << std::endl;

	}
}

void Win::generateConf()
{
	std::ifstream file("mainconfig.conf");

	std::cout << "Configuration file not found, creating new one!" << std::endl;
	std::ofstream defConf("mainconfig.conf");
	if(defConf)
	{
		defConf << "width_scaling=" << scal.x << std::endl;
		defConf << "height_scaling=" << scal.y << std::endl;
		defConf << "framerate_limit=" << framerateLimit << std::endl;
	}
	else
	{
		std::cout << "! mainconfig: ERROR, newly created config could not be opened" << std::endl;
		if(isOpen())
			close();
		return;
	}
	file.close();
}

void Win::generateWindow()
{
	create(sf::VideoMode(1920 * scal.x, defWinHeight * scal.y), winName);
	setFramerateLimit(framerateLimit);
}
