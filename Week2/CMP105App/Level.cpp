#include "Level.h"
//MINE
Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error Loading font\n";
	}
	text.setFont(font);
	text.setString("current position");
	text.setPosition(250, 0);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	input = in;

	hiddenText.setFont(font);
	text.setString("this text is hidden");
	text.setPosition(500, 500);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Green);

	mousePosX.setFont(font);
	mousePosX.setCharacterSize(24);
	mousePosX.setFillColor(sf::Color::Yellow);

	mousePosY.setFont(font);
	mousePosY.setCharacterSize(24);
	mousePosY.setFillColor(sf::Color::Yellow);
	mousePosY.setPosition(80, 0);

	coverup.setPosition(0, 0);
	coverup.setFillColor(sf::Color::Red);


	// initialise game objects

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	//if (input->setMouseLDown(true))
	{
		input->setMouseLDown(false);
		std::cout << "yes it works\n";
	}
	float endx = input->getMouseX();
	float endy = input->getMouseY();
	//std::cout << endx << " " << endy << "yes it stopped" << "\n";

	//if (input->isKeyDown(sf::Keyboard::W))
	//{
	//	input->setKeyUp(sf::Keyboard::W);
	//	std::cout << "W  pressed\n";

//	}

		//current work
	input->setKeyUp(sf::Mouse::Left);
	float initalx = input->getMouseX();
	float initaly = input->getMouseY();
	//std::cout << initalx << " " << initaly << "\n";


}



// Update game objects
void Level::update()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W  pressed\n";
		showwall = true;
	}


	if (input->isKeyDown(sf::Keyboard::J) &&
		input->isKeyDown(sf::Keyboard::K) &&
		input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "you pressed all keys\n";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}

	std::string output("X: ");
	output += std::to_string(input->getMouseX());

	mousePosX.setString(output);

	std::string outputY("Y: ");
	outputY += std::to_string(input->getMouseY());

	mousePosY.setString(outputY);


	/*if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		cursour.setPosition(input->getMouseX(), input->getMouseY());
	}*/

	cursour.setPosition(input->getMouseX() - 12, input->getMouseY() - 12);
	cursour.setRadius(20);
	cursour.setFillColor(sf::Color::Blue);
	cursour.setOutlineColor(sf::Color::Green);


	sf::Vector2u pos = window->getSize();
	coverup.setSize(sf::Vector2f(pos));
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);

	window->draw(hiddenText);
	window->draw(mousePosX);
	window->draw(mousePosY);
	if (showwall == true)
	{
		window->draw(coverup);
		window->draw(cursour);
	}
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}