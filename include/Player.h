#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "Ship.h"

class Player : public Ship {
private:
protected:
public:
	int keyLeft, keyRight, keyShoot;

	Player(void);
	~Player(void);

	void SetKeys(int set_keyLeft, int set_keyRight, int set_keyShoot); // Only set input for the player, otherwise just ignore this.

};

#endif
