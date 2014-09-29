#include <Bullet.h>

Bullet::Bullet(void) {}

Bullet::~Bullet(void) {}

void Bullet::Move(float deltaTime, float mod) {
	y = y + ((speedY*mod)*deltaTime);
	x = x + ((speedX*mod)*deltaTime);
}

void Bullet::Init(float set_x, float set_y, float set_speedX, float set_speedY, const char* SET_SPRITE, int set_w, int set_h) {
	this->x = set_x;
	this->y = set_y;
	this->speedX = set_speedX;
	this->speedY = set_speedY;
	this->SetSprite(SET_SPRITE, set_x, set_y);
}
