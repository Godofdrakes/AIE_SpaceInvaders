#ifndef _SHIP_H_
#define _SHIP_H_

/*

Ship has
	a sprite (int)
	x/y pos (float)
	xMax/yMax pos (float)
	sprite w/h (int)
	speed (float)
	move/shoot keys (int)

*/

class Ship {
private:
public:
	float x, y, xMax, yMax, speed;
	int w, h, keyLeft, keyRight, keyShoot, sprite;

	Ship(void);
	~Ship(void);

	void SetKeys(int set_keyLeft, int set_keyRight, int set_keyShoot);
	void SetPosMax(float set_xMax, float set_yMax);
	void SetPos(float set_x, float set_y);
	void SetSpeed(float set_speed);
	void SetSprite(int set_sprite, int set_w, int set_h);
};

#endif
