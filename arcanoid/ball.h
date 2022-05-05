#pragma once



#include <SFML/Graphics.hpp>
using namespace sf;




class VECTOR {
public: 
	float x, y;

};


class Ball {
	Texture ball_t;

public:
	
	int dir;
	bool ball_life=1;
	Sprite ball_sprite;
	VECTOR ball_coord;
	VECTOR ball_speed_vector;
	Ball(Image& sprite_image, Vector2f position, float dx, float dy) {
		this->ball_t.loadFromImage(sprite_image);
	
		ball_speed_vector.x = dx;
		ball_speed_vector.y = dy;
		ball_sprite.setTexture(ball_t);
		ball_sprite.setTextureRect(IntRect(21, 21, 22, 22));
		ball_sprite.setOrigin(ball_sprite.getLocalBounds().width/2, ball_sprite.getLocalBounds().height / 2);
		ball_sprite.setPosition(position);
	}
	void ban_exit() {
		
		if (ball_sprite.getPosition().x-ball_sprite.getGlobalBounds().width/2<0 or ball_sprite.getPosition().x+ball_sprite.getLocalBounds().width / 2 >500)
		{
		
			ball_speed_vector.x = -ball_speed_vector.x;
		}
		if (ball_sprite.getPosition().y- ball_sprite.getLocalBounds().height / 2 < 0)
		{
			
			ball_speed_vector.y = -ball_speed_vector.y;
		}
		if (ball_sprite.getPosition().y+ ball_sprite.getLocalBounds().height / 2 > 500)
		{
			ball_life = !ball_life;
		}
	}


	void update() {

		if (ball_speed_vector.x>0)
		{
			dir = 1;
		}
		else {
			dir = 2;
		}
	}
	void movement() {

		ball_sprite.move(ball_speed_vector.x, ball_speed_vector.y);

	}

};