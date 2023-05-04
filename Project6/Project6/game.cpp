/*
#include "game.h"
#include <iostream>



void Game::initwindow()
{
	this->vidmod.height = 600;
	this->vidmod.width = 800;
	this->window = new RenderWindow(this->vidmod, "aia", Style::Titlebar | Style::Close );
	this->window->setFramerateLimit(75);
}

Game::Game() {


	this->initwindow();

};
Game::~Game() {
	delete this->window;
}


const bool Game::running() const
{

	return this->window->isOpen();

}

void Game::polev()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (ev.type)
		{
		case Event::Closed:this->window->close(); break;
		case Event::KeyPressed:if (this->ev.key.code == Keyboard::Escape)this->window->close();
		}
	}
}
void Game::render()
{
	this->window->clear();
	this->window->display();
	
};
*/