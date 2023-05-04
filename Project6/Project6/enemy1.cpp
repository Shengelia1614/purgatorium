#include "enemy1.h"
enemy1::~enemy1() {};

enemy1::enemy1(float x, float y) {
	shp1.setPosition(x, y);
	shp1.setSize(Vector2f(15.f, 15.f));
	shp1.setFillColor(Color::Red);
}

void enemy1::updatecol1(const RenderTarget* target) {
	//left

	//FloatRect plbd = shp1.getGlobalBounds();

	//if (plbd.top >= target->getSize().y)
	//{
	//	shp1.setPosition(plbd.left, target->getSize().y);
	//}

}
void enemy1::AI(const RenderTarget* target) {


	FloatRect plbd = this->shp1.getGlobalBounds();
	bool a = this->shp1.getGlobalBounds().left < 0.f || plbd.left + plbd.width > target->getSize().x;
	if (a)
	{
		xs = xs * -1;

	}
	bool b = this->shp1.getGlobalBounds().top < 0.f || plbd.top + plbd.height > target->getSize().y;
	if (b)
	{
		yz = yz * -1;

	}
	Vector2f k(xs, yz);

	this->shp1.move(k.x / 10, k.y / 10);

}
void enemy1::update1(const RenderTarget* target)
{
	//pl mov
	//win  bnd col
	this->updatecol1(target);
	this->AI(target);

	//kb

}

void enemy1::render1(RenderTarget* target)
{
	target->draw(this->shp1);
}
