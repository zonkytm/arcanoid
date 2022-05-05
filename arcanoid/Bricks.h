#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;

class Bricks {
	Texture bricks_texture;
	
public:
	Sprite brick_sprite;
	bool life;
	Bricks() {
		Image bricks_image;
		bricks_image.loadFromFile("sprites/Breakout/img/green_brick.png");
		bricks_texture.loadFromImage(bricks_image);
		brick_sprite.setTexture(bricks_texture);
		brick_sprite.setTextureRect(IntRect(0, 0, 64, 32));
		brick_sprite.setOrigin(64 / 2, 32 / 2);
		life = 1;
		
	}

};