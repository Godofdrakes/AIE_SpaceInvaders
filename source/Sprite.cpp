#include "Sprite.h"

Sprite::Sprite(void) {}

Sprite::~Sprite(void) {}

void Sprite::SetSprite(const char* SET_SPRITE, int set_w, int set_h) {
	w = set_w;
	h = set_h;
	sprite = CreateSprite(SET_SPRITE, w, h, true);
}

void Sprite::Draw() {
	MoveSprite(sprite, x, y); //-------------------------
	DrawSprite(sprite);
}
