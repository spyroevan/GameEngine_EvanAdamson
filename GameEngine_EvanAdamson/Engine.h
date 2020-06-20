#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>


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
	
	static Engine& GetInstance();
	void Start(sf::RenderWindow* win);
};

