#pragma once

#include"ECS.h"
#include "Engine.h"
#include"Components.h"
#include <iostream>

class RenderingSystem : public ECS::EntitySystem
{
private:
	std::unordered_map<std::string, sf::Texture*> textureMap;

	sf::Texture* LoadTexture(std::string texture);


public:
	RenderingSystem(void);
	~RenderingSystem(void);

	void tick(ECS::World* world, float deltaTime) override;

};

