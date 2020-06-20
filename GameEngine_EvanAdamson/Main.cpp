#include <SFML\Graphics.hpp>
#include "Engine.h"

int main(int argC, char* args[])
{
	Engine& gameEngine = Engine::GetInstance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");

	

	gameEngine.Start(&window);

	return 0;
}