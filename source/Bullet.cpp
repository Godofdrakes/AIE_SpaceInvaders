#include <Bullet.h>

Bullet::Bullet(void) {}

Bullet::~Bullet(void) {}

void Bullet::Move(float deltaTime, bool moveRight, float mod) {
	y = y + ((speed*mod)*deltaTime);
}
