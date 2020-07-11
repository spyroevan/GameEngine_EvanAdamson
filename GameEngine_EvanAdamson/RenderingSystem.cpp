#include "Include\RenderingSystem.h"



RenderingSystem::RenderingSystem()
{
}


RenderingSystem::~RenderingSystem()
{
}

void RenderingSystem::tick(ECS::World* world, float deltaTime)
{
	Engine::GetInstance().window->clear();


	world->each<Transform, Sprite2d>(
		[&](ECS::Entity* ent,
			ECS::ComponentHandle<Transform> transform,
			ECS::ComponentHandle<Sprite2d> sprite) -> void
	{
		//add texture to unordered texture map
		if (textureMap.count(sprite->Texture) < 1)
		{
			textureMap[sprite->Texture] = LoadTexture(sprite->Texture);

		}
		//aaaaaaaa

		if (sprite->Image.getTexture() == NULL)
		{
			sprite->Image.setTexture(*textureMap[sprite->Texture]);
			sprite->width = sprite->Image.getGlobalBounds().width;
			sprite->height = sprite->Image.getGlobalBounds().height;

		}

	});
	//Display updates
	Engine::GetInstance().window->display();
}

sf::Texture* RenderingSystem::LoadTexture(std::string texture) {

	sf::Texture* _tex = new sf::Texture();

	if (_tex->loadFromFile(texture) == NULL)
	{

		std::cerr << "good day, i was unable to load image" << texture << "./nIs this image the correct directory?" << std::endl;
		std::cerr << "Error" << std::endl;
		std::cerr << "this error was brought to you by Evan." << std::endl;
		system("pause");
		exit(EXIT_FAILURE);

	}

	return _tex;
}