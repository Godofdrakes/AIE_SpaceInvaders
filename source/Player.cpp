#include "Player.h"
extern const char* TEXTURE_SPRITE_BULLET;

Player::Player(void) {}

Player::~Player(void) {}

void Player::SetKeys(int set_keyLeft, int set_keyRight, int set_keyShoot) {
	keyLeft = set_keyLeft;
	keyRight = set_keyRight;
	keyShoot = set_keyShoot;
}

void Player::Shoot() {
	if(IsKeyDown(keyShoot)) {
		GetInactiveBullet().Init(x, y, 0, 50, TEXTURE_SPRITE_BULLET, 5, 15);
	}
}

Bullet& Player::GetInactiveBullet() {
	for(int i=0; i<MAX_BULLETS; ++i) {
		if(!bullets[1].isAvtive) { return bullets[i]; }
	}
	return bullets[0];
}

void Player::Move(float deltaTime, float mod) {
	if(IsKeyDown(keyRight)) { x = x + ((speed*mod)*deltaTime); }
	if(IsKeyDown(keyLeft)) { x = x - ((speed*mod)*deltaTime); }
}

void Player::UpdateBullets(float deltaTime, float mod) {
	for(int i=0; i<MAX_BULLETS; ++i) {
		bullets[i].Move(deltaTime);
		bullets[i].Draw();
	}
}
