#pragma once


#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;



class Paddle {

	Vector2f position;
	Texture paddle_texture;
public:
	float dx,speed;
	int dir;
	Sprite paddle_sprite;

	Paddle(Image& paddle_image, float speed) {
		this->speed = speed;
		paddle_texture.loadFromImage(paddle_image);
		paddle_sprite.setTexture(paddle_texture);
		paddle_sprite.setTextureRect(IntRect(0, 0, 104, 24));
		paddle_sprite.setOrigin(paddle_sprite.getLocalBounds().width / 2, paddle_sprite.getGlobalBounds().height);
		paddle_sprite.setPosition(Vector2f(500 / 2, 500 - paddle_sprite.getGlobalBounds().height));
	}
	void ban_exit() {

		if (paddle_sprite.getPosition().x < paddle_sprite.getGlobalBounds().width / 2)
		{
			paddle_sprite.setPosition(paddle_sprite.getGlobalBounds().width / 2, paddle_sprite.getPosition().y);
		}
		else if (paddle_sprite.getPosition().x > 500 - paddle_sprite.getGlobalBounds().width / 2)
		{
			paddle_sprite.setPosition(500 - paddle_sprite.getGlobalBounds().width / 2, paddle_sprite.getPosition().y);
		}
	}

	void update() {

		switch (dir)
		{

		case 1:
			dx = speed;
			break;
		case 2:
			dx = -speed;
			break;
		default:
			dx = 0;
			break;
		}
		paddle_sprite.setPosition(paddle_sprite.getPosition().x + dx, 500 - paddle_sprite.getGlobalBounds().height);

		speed = 0;

	}
	void movement() {

		dir = 0;
		if (Keyboard::isKeyPressed(Keyboard::D) or Keyboard::isKeyPressed(Keyboard::A))
		{
			speed = 10;
			

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				dir = 1;
				


			}
			else if (Keyboard::isKeyPressed(Keyboard::A))
			{
				dir = 2;

			
			}
			else {
				dir = 0;
			}
		}

	}

};


