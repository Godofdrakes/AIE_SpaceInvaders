#include "Sprite.h"
#include "AIE.h"

Sprite::Sprite(void) {}

Sprite::~Sprite(void) {
	if(sprite) { DestroySprite(sprite); }
}

void Sprite::SetSprite(int set_sprite, int set_w, int set_h) {
	sprite = set_sprite;
	w = set_w;
	h = set_h;
}
