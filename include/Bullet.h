#ifndef _BULLET_H_
#define _BULLET_H_

#include "Sprite.h"

class Bullet : public Sprite {
private:
protected:
public:
	float speed;

	Bullet(void);
	~Bullet(void);

	void Move(float deltaTime, bool moveRight, float mod = 1.f);

};

#endif
