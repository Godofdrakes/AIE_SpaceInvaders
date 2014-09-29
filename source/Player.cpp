#include "Player.h"

Player::Player(void) {}

Player::~Player(void) {}

void Player::SetKeys(int set_keyLeft, int set_keyRight, int set_keyShoot) {
	keyLeft = set_keyLeft;
	keyRight = set_keyRight;
	keyShoot = set_keyShoot;
}
