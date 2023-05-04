
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/window.hpp>
#include <SFML/audio.hpp>
#include <SFML/network.hpp>
#include <iostream>
#include <utility>

//#include "enemy1.h"
//#include "bull.h"

#include <vector>

using namespace sf;



class player
{
	float movsp=5;
	
	RectangleShape shp;
	
	
public:
	player(float x=0.f, float y=0.f);
	virtual ~player();
	void updatecol(const RenderTarget* target);
	//void anemcol(const RenderTarget* target);
	void update(const RenderTarget* target);
	void updateinp();
	void render(RenderTarget* target);
	Vector2f getpos() { return shp.getPosition(); }
	RectangleShape getshp() { return shp; }
	
};















