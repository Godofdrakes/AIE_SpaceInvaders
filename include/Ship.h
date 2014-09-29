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

	void SetKeys(int set_keyLeft, int set_keyRight, int set_keyShoot); // Only set input for the player, otherwise just ignore this.
	void SetPosMax(float set_xMax, float set_yMax); // Prevent the object from going past these limits (and below 0, obviously)
	void SetPos(float set_x, float set_y); // Used to set the initial position. Could be used to move the object but we have functions for that below.
	void SetSpeed(float set_speed);
	void SetSprite(int set_sprite, int set_w, int set_h); // Used as func(CreateSprite(), w, h) to hold the sprite's ID and dimentions.

	void MoveX(float deltaTime, bool moveRight, float mod = 1.f); // Use these to move the object
	void MoveY(float deltaTime, bool moveUp, float mod = 1.f); // Modifier value, if we want it to move faster without changing the speed
};

#endif
