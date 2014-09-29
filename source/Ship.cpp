#include <Ship.h>

Ship::Ship(void) {}

Ship::~Ship(void) {}

void Ship::SetKeys(int set_keyLeft, int set_keyRight, int set_keyShoot) {
	keyLeft = set_keyLeft;
	keyRight = set_keyRight;
	keyShoot = set_keyShoot;
}

void Ship::SetPosMax(float set_xMax, float set_yMax) {
	xMax = set_xMax;
	yMax = set_yMax;
}

void Ship::SetPos(float set_x, float set_y) {
	x = set_x;
	y = set_y;
}

void Ship::SetSpeed(float set_speed) {
	speed = set_speed;
}

void Ship::SetSprite(int set_sprite, int set_w, int set_h) {
	sprite = set_sprite;
	w = set_w;
	h = set_h;
}
