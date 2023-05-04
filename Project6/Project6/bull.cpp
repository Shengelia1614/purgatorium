#include "bull.h"

bull::~bull() {}
void bull::updatecol2(const RenderTarget* target) {
	//left


	if (shp2.getGlobalBounds().left <= 0.f) dir.x = dir.x * -1;

	if (shp2.getGlobalBounds().left + shp2.getGlobalBounds().width >= target->getSize().x) { dir.x = dir.x * -1; }

	if (shp2.getGlobalBounds().top <= 0.f)dir.y = dir.y * -1;

	if (shp2.getGlobalBounds().top + shp2.getGlobalBounds().height >= target->getSize().y) { dir.y = dir.y * -1;; }

};
void bull::getdir() {
	dir.x = plpos.x - enpos.x;
	dir.y = plpos.y - enpos.y;
}
void bull::updateinp2() {
	shp2.move(dir.x / 100, dir.y / 100);
	cout << dir.x << dir.y;
}
void bull::update2(const RenderTarget* target)
{
	//pl mov
	//win  bnd col
	updatecol2(target);
	updateinp2();

	//kb

}
void bull::render2(RenderTarget* target)
{
	target->draw(shp2);
}