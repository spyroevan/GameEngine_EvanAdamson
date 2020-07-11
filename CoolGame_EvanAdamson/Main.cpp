//game main
#include <SFML\Graphics.hpp>
#include "..\GameEngine_EvanAdamson\Include\Engine.h"


int main(int argC, char* args[])
{
	Engine& gameEngine = Engine::GetInstance();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Game Engine");

	gameEngine.world = ECS::World::createWorld();
	ECS::Entity* background;
	ECS::Entity* guy;

	gameEngine.AddSystem(new RenderingSystem());
	gameEngine.AddSystem(new AnimationSystem());

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			
			background = gameEngine.world->create();
			guy = gameEngine.world->create();
			



			//assign components to entities after creation
			background->assign<Transform>(0, 0);
			background->assign<Sprite2d>("../Debug/Images/bg.jpg");

			guy->assign<Transform>(i * 25, j * 32);
			guy->assign<Sprite2d>("../Debug/Images/herosheet.png");
			guy->assign<Animator>(32, 32, 200.0f);

			std::cout << guy->getEntityId() << " is the entity ID" <<
				std::endl;
		}
	}

	gameEngine.Start(&window);

	return 0;
}