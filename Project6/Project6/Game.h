/*
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/window.hpp>
#include <SFML/audio.hpp>
#include <SFML/network.hpp>

#include "player.h"
#include "enemy1.h"
#include <vector>

using namespace sf;
using namespace std;
class Game
{
	RenderWindow* window;
	Event ev;
	VideoMode vidmod;
	void initwindow();
	bool endgame;
public:
	
	Game();
	virtual ~Game();
	void polev();
	void render();
	const bool running() const;
	
};
*/
