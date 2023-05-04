
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/window.hpp>
#include <SFML/audio.hpp>
#include <SFML/network.hpp>
#include <random>

using namespace sf;
float xs = 20, yz=1.f;
class enemy1
{	
	RectangleShape shp1;

public:
	enemy1(float x = 400.f, float y = 4.f);
	virtual ~enemy1();
	void updatecol1(const RenderTarget* target);
	void update1(const RenderTarget* target);
	void AI(const RenderTarget* target);
	void render1(RenderTarget* target);
	Vector2f getpos1() { return shp1.getPosition(); }
	RectangleShape getshp() { return shp1; }
};












