#pragma once

#include "Engine.h"
#include <SFML/Graphics.hpp>
#include "ECS.h"

struct Transform
{
public:
	ECS_DECLARE_TYPE;

	float X;
	float Y;
	float Rotation;



	Transform(float x, float y)
	{
		X = x;
		Y = y;
		Rotation = 0.0f;


	}
	
	

};
ECS_DEFINE_TYPE(Transform);


struct Sprite2d {

public:
	ECS_DECLARE_TYPE;

	sf::Sprite Image;
	std::string Texture;

	int width;
	int height;

	Sprite2d(std::string name)
	{
		Texture = name;

	}

};
ECS_DEFINE_TYPE(Sprite2d);


struct Animator
{
public:
	ECS_DECLARE_TYPE;
	
	int spriteWidth, spriteHeight;
	int currentColumn, currentRow;
	float currentTime, nextFrameTime;

	Animator(int width, int height, float timeBetweenFrames)
	{

		this->spriteWidth = width;
		this->spriteHeight = height;
		currentColumn = 0;
		currentRow = 0;
		this->nextFrameTime = timeBetweenFrames;
		currentTime = 0;



	}

};
ECS_DEFINE_TYPE(Animator);