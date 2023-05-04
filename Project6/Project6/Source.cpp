#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <iostream>

#include "Game.h"
#include "player.h"
#include "enemy1.h"
#include "bull.h"


#include <SFML/Graphics.hpp>
#include <SFML/system.hpp>
#include <SFML/window.hpp>
#include <SFML/audio.hpp>
#include <SFML/network.hpp>
//#include <texture.hpp>


#include <vector>



using namespace sf;
using namespace std;

bool gethit(player& c, enemy1& a, vector<bull>& b) {
	for (size_t i = 0; i < b.size(); i++)
	{
		return (b[i].getpos2().x+5 >= c.getshp().getGlobalBounds().left && b[i].getpos2().x+5 <= c.getshp().getGlobalBounds().left + c.getshp().getGlobalBounds().width
			&& b[i].getpos2().y+5>= c.getshp().getGlobalBounds().top && b[i].getpos2().y+5 <= c.getshp().getGlobalBounds().top + c.getshp().getGlobalBounds().height);
	}
	return
		(a.getpos1().x > c.getshp().getGlobalBounds().left && a.getpos1().x < c.getshp().getGlobalBounds().left + c.getshp().getGlobalBounds().width
			&& a.getpos1().y> c.getshp().getGlobalBounds().top && a.getpos1().y < c.getshp().getGlobalBounds().top + c.getshp().getGlobalBounds().height);


}



int main() {
	Texture texture;
	texture.loadFromFile("C:/Users/Shenge/source/repos/Project6/Project6/Game-Over.png");
	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setScale(Vector2f(4.f, 4.f));
	sprite.setPosition(400-127*2,300-35*2);

	
	//window = new RenderWindow(600,800, "aia", Style::Titlebar | Style::Close);
	RenderWindow window(VideoMode(800, 600), "spaceBullet", Style::Titlebar | Style::Close);
	window.setFramerateLimit(75);
	//RenderTarget::clear()

	Clock clock;
	
	Event ev;
	player pl(290.f,190.f);
	enemy1 en;
	//bull bl(pl,en);
	//bl.getdir();
	vector<bull> bulet;

	int GameOver{0};





	while (window.isOpen()) {
		Time elaps = clock.getElapsedTime();


		window.clear(Color::Black);
		while (window.pollEvent(ev))
		{
			//up
			switch (ev.type)
			{
			case Event::Closed:window.close(); break;
			case Event::KeyPressed:if (ev.key.code == Keyboard::Escape)window.close();
			}

		}
		pl.update(&window);
		en.update1(&window);
		cout << elaps.asSeconds()<<endl;
		if (elaps.asSeconds() >= 2) {
			bull bl(pl, en);
			bl.getdir();
			bulet.push_back(bl);


			clock.restart();
		}
		if ((en.getpos1().x > pl.getshp().getGlobalBounds().left && en.getpos1().x < pl.getshp().getGlobalBounds().left + pl.getshp().getGlobalBounds().width
			&& en.getpos1().y> pl.getshp().getGlobalBounds().top && en.getpos1().y < pl.getshp().getGlobalBounds().top + pl.getshp().getGlobalBounds().height)) {
				//window.close();
				GameOver = +1;
			}
		for (size_t i = 0; i < bulet.size(); i++)
		{
			if ((bulet[i].getpos2().x + 5 >= pl.getshp().getGlobalBounds().left && bulet[i].getpos2().x + 5 <= pl.getshp().getGlobalBounds().left + pl.getshp().getGlobalBounds().width
				&& bulet[i].getpos2().y + 5 >= pl.getshp().getGlobalBounds().top && bulet[i].getpos2().y + 5 <= pl.getshp().getGlobalBounds().top + pl.getshp().getGlobalBounds().height)) {
				//window.close();
				GameOver = +1;
			}
	
				
			
			bulet[i].update2(&window);
		}
		

		

















		//ren
		pl.render(&window);
		en.render1(&window);
		for (size_t i = 0; i < bulet.size(); i++)
		{
			bulet[i].render2(&window);
		}
		


















		if (GameOver >= 1) {
			window.clear(Color::Black);
			window.draw(sprite);
		}



		window.display();

	}

}