#ifndef _BULLET_H_
#define _BULLET_H_

#include "Sprite.h"

class Bullet : public Sprite {
private:
protected:
public:
	float speedX, speedY;
	bool isAvtive;

	Bullet(void);
	~Bullet(void);

	void Move(float deltaTime, float mod = 1.f);
	void Init(float set_x, float set_y, float set_speedX, float set_speedY, const char* SET_SPRITE, int set_w, int set_h); // Initialise

};

#endif
