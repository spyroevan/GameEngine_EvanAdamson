#include "Include\AnimationSystem.h"



AnimationSystem::AnimationSystem()
{
}


AnimationSystem::~AnimationSystem()
{
}



void AnimationSystem::tick(ECS::World * world, float deltaTime)
{

	world->each<Animator, Sprite2d>(
		[&](ECS::Entity* entity,
			ECS::ComponentHandle<Animator> animator,
			ECS::ComponentHandle<Sprite2d> sprite) -> void
	{
		animator->currentTime += deltaTime;

		if (animator->currentTime >= animator->nextFrameTime)
		{
			animator->currentTime = 0;
			animator->currentColumn = (animator->currentColumn + 1) % 4; // hardcoded value
		}

		sprite->Image.setTextureRect(
			sf::IntRect(animator->currentColumn * animator->spriteWidth, // lr sides
				animator->currentRow * animator->spriteHeight, // tb sides
				animator->spriteWidth,		// width
				animator->spriteHeight));	// height
	});

}