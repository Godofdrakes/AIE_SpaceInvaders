#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Ship.h"
#include "Bullet.h"
const int MAX_BULLETS = 20;

class Player : public Ship {
private:
protected:
	Bullet bullets[MAX_BULLETS];
public:
	int keyLeft, keyRight, keyShoot;

	Player(void);
	~Player(void);

	void Move(float deltaTime, float mod = 1.f);
	void SetKeys(int set_keyLeft, int set_keyRight, int set_keyShoot); // Only set input for the player, otherwise just ignore this.
	void Shoot();
	Bullet& GetInactiveBullet();
	void UpdateBullets(float deltaTime, float mod = 1.f);

};

#endif
