#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "ECS.h"
#include "Components.h"
#include "RenderingSystem.h"
#include "AnimationSystem.h"

class Engine
{
private:
	bool bIsQuit;

	Engine();
	//singleton: required to prevent the reference from being cp[ied, moved, or assigned

	Engine(Engine& copy);
	Engine(Engine&& other);
	Engine& operator= (Engine& copy);

	~Engine();

	void Update();


public:
	sf::RenderWindow* window;
	ECS::World* world;
	sf::Event _event; // TODO: this should be a local variable
	
	static Engine& GetInstance();
	void Start(sf::RenderWindow* win);
	void AddSystem(ECS::EntitySystem* newSys);


};

