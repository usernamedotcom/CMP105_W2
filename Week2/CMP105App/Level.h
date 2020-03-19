#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	bool showwall = false;

	// Add your object here

	sf::Font font;
	sf::Text text;
	sf::Text hiddenText;
	sf::Text mousePosX;
	sf::Text mousePosY;
	sf::CircleShape cursour;
	sf::RectangleShape coverup;

};