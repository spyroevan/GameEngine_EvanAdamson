#pragma once
#include "ECS.h"
#include "Components.h"


class AnimationSystem : public ECS::EntitySystem
{
public:
	AnimationSystem();
	~AnimationSystem();

	void tick(ECS::World* world, float deltaTime) override;

};

