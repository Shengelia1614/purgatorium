#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/window.hpp>
#include <SFML/audio.hpp>
#include <SFML/network.hpp>
#include <iostream>
#include <utility>

#include "player.h"
#include "enemy1.h"

using namespace std;

//#include "Source.cpp"
using namespace sf;
float gz;
//Vector2f dir, plpos, enpos;
class bull
{
	float movsp = 5, f;

	CircleShape shp2;


public:
	Vector2f dir, plpos, enpos;
	
	//bull(player &a,enemy1 &b);
	bull(player & a, enemy1 & b) {
		shp2.setPosition(b.getpos1());
		shp2.setRadius(5.f);
		shp2.setFillColor(Color::Green);
		plpos = a.getpos();
		enpos = b.getpos1();
	}
	virtual ~bull();
	void updatecol2(const RenderTarget* target);
	//void anemcol(const RenderTarget* target);
	void update2(const RenderTarget* target);
	void updateinp2();
	void getdir();
	void render2(RenderTarget* target);
	Vector2f getpos2() { return shp2.getPosition(); }

};












/*
bull::bull(player& a, enemy1& b) {
	shp2.setPosition(b.getpos1());
	shp2.setRadius(5.f);
	shp2.setFillColor(Color::Green);
	plpos = a.getpos();
	enpos = b.getpos1();
}
*/
