#pragma once
#include <iostream>
#include "ball.h"
#include"paddle.h"
#include "Bricks.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

void intersections_ball_paddle(Paddle& paddle, Ball& ball) {

	if (ball.ball_sprite.getGlobalBounds().intersects(paddle.paddle_sprite.getGlobalBounds()))
	{
		if (!((paddle.dir == ball.dir) or paddle.dir == 0))
		{
			
			ball.ball_speed_vector.x = -ball.ball_speed_vector.x;
		}

		if (ball.ball_sprite.getPosition().y + ball.ball_sprite.getGlobalBounds().height / 2>= paddle.paddle_sprite.getPosition().y)
		{
			
			ball.ball_speed_vector.y = -ball.ball_speed_vector.y;
		}
	

	}
}


void intersection(Ball& ball, Bricks& brick, int& points) {
	if (ball.ball_sprite.getGlobalBounds().intersects(brick.brick_sprite.getGlobalBounds())) {
		cout << "intersects" << endl;
		brick.life = 0;
		points++;
	
	}
}




/*


void intersections_ball_paddle(Paddle& paddle, Ball& ball) {

	if (ball.ball_sprite.getGlobalBounds().intersects(paddle.paddle_sprite.getGlobalBounds()))
	{
		if (ball.ball_sprite.getPosition().y + ball.ball_sprite.getGlobalBounds().height / 2 >= paddle.paddle_sprite.getPosition().y)
		{


			ball.dy = -ball.dy;
			if ((paddle.dir == ball.dir) or paddle.dir == 0)
			{

				std::cout << "direction matches\n";
			}
			else {
				ball.dx = -ball.dx;

				std::cout << "direction doesn't matches\n";
			}
		}
		else if (ball.ball_sprite.getPosition().x + ball.ball_sprite.getGlobalBounds().width / 2 >= paddle.paddle_sprite.getPosition().x + paddle.paddle_sprite.getGlobalBounds().width / 2
			or ball.ball_sprite.getPosition().x + ball.ball_sprite.getGlobalBounds().width / 2 < paddle.paddle_sprite.getPosition().x - paddle.paddle_sprite.getGlobalBounds().width / 2)
		{
			ball.ball_life = 0;
		}

	}
}

void intersection(Ball& ball, Bricks& brick, int& points) {

	if (ball.ball_sprite.getGlobalBounds().intersects(brick.brick_sprite.getGlobalBounds()))
	{
		ball.ball_sprite.setColor(Color(255, 0, 0));
		brick.brick_sprite.setPosition(-100, 0);
		points++;
	}
	else {
		ball.ball_sprite.setColor(Color::White);
		
	}
}*/