#include "Engine.h"



Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::Update()
{
	
	sf::Event _event;
	
	//run the program as long as the window is open
	while (window->isOpen() == true)
	{
		

		//"close requested" event: we close the window
		if (_event.type == sf::Event::Closed)
		{

			std::cout << "Closing Now..." << std::endl;
			window->close();

		}
	}
}

Engine & Engine::GetInstance()
{
	static Engine _instance;

	return _instance;
}

void Engine::Start(sf::RenderWindow * win)
{

	bIsQuit = false;
	window = win;


	while (window->isOpen()) 
	{
		Update();
	}

}
