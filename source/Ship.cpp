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

void Ship::MoveX(float deltaTime, bool moveRight, float mod) {
	if(moveRight) {
		x = x + ((speed*mod)*deltaTime);
	} else {
		x = x - ((speed*mod)*deltaTime);
	}

	if( x + (w/2) > xMax ) { x = xMax - (w/2); }
	if( x - (w/2) < 0 ) { x = (w/2); }
}

void Ship::MoveY(float deltaTime, bool moveUp, float mod) {
	if(moveUp) {
		y = y + ((speed*mod)*deltaTime);
	} else {
		y = y - ((speed*mod)*deltaTime);
	}

	if( y + (w/2) > yMax ) { y = yMax - (w/2); }
	if( y - (w/2) < 0 ) { y = (w/2); }
}
