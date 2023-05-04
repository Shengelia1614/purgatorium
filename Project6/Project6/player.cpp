#include "player.h"


player::player(float x, float y) {
	shp.setFillColor(Color::Blue);
	shp.setPosition(x, y);
	shp.setSize(Vector2f(20.f, 20.f));
}
player::~player() {}
void player::updateinp() {

	if (Keyboard::isKeyPressed(Keyboard::A))  shp.move(-movsp, 0.f);
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		shp.move(movsp, 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::W))  shp.move(0.f, -movsp);
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		shp.move(0.f, movsp);
	}
}
void player::updatecol(const RenderTarget* target) {
	//left


	if (shp.getGlobalBounds().left <= 0.f)  shp.setPosition(0.f, shp.getGlobalBounds().top);

	if (shp.getGlobalBounds().left + shp.getGlobalBounds().width >= target->getSize().x) { shp.setPosition(target->getSize().x - shp.getGlobalBounds().width, shp.getGlobalBounds().top); }

	if (shp.getGlobalBounds().top <= 0.f)  shp.setPosition(shp.getGlobalBounds().left, 0.f);

	if (shp.getGlobalBounds().top + shp.getGlobalBounds().height >= target->getSize().y) { shp.setPosition(shp.getGlobalBounds().left, target->getSize().y - shp.getGlobalBounds().height); }

};
void player::update(const RenderTarget* target)
{
	//pl mov
	//win  bnd col
	updatecol(target);
	updateinp();

	//kb

}
void player::render(RenderTarget* target)
{
	target->draw(shp);
}
/*
bool gethit(player &c,enemy1& a, vector<bull>& b) {
	for (size_t i = 0; i < b.size(); i++)
	{
		return (b[i].getpos2().x > shp.getGlobalBounds().left && b[i].getpos2().x < shp.getGlobalBounds().left + shp.getGlobalBounds().width
			&& b[i].getpos2().y> shp.getGlobalBounds().top && b[i].getpos2().y < shp.getGlobalBounds().top + shp.getGlobalBounds().height);
	}
	return
		(a.getpos1().x > shp.getGlobalBounds().left && a.getpos1().x < shp.getGlobalBounds().left + shp.getGlobalBounds().width
			&& a.getpos1().y> shp.getGlobalBounds().top && a.getpos1().y < shp.getGlobalBounds().top + shp.getGlobalBounds().height);


}
*/