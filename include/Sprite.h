#ifndef _SPRITE_H_
#define _SPRITE_H_

class Sprite {
private:
protected:
public:
	float x, y;
	int w, h, sprite;

	Sprite(void);
	~Sprite(void);

	void SetSprite(int set_sprite, int set_w, int set_h); // Used as func(CreateSprite(), w, h) to hold the sprite's ID and dimentions.
};

#endif
