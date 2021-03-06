#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Include\ECS.h"
#include "Include\Components.h"
#include "Include\RenderingSystem.h"
#include "Include\AnimationSystem.h"

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

