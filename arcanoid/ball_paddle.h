#pragma once
#include <iostream>
#include "ball.h"
#include"paddle.h"
#include "Bricks.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

void intersections_ball_paddle(Paddle& paddle, Ball& ball) {

	if (ball.ball_sprite.getGlobalBounds().intersects(paddle.paddle_sprite.getGlobalBounds()) and ball.ball_sprite.getPosition().y<=paddle.paddle_sprite.getPosition().y)
	{
		if (ball.ball_sprite.getPosition().y+ball.ball_sprite.getGlobalBounds().height/2  >= paddle.paddle_sprite.getPosition().y-paddle.paddle_sprite.getGlobalBounds().height)
		{


			if (!((paddle.dir == ball.dir) or paddle.dir == 0))
			{

				ball.ball_speed_vector.x = -ball.ball_speed_vector.x;
			}

			if (ball.ball_sprite.getPosition().y + ball.ball_sprite.getGlobalBounds().height / 2 >= paddle.paddle_sprite.getPosition().y)
			{

				ball.ball_speed_vector.y = -ball.ball_speed_vector.y;
			}
			ball.ball_speed_vector.y = -ball.ball_speed_vector.y;

		}
	}

}



bool intersects_ball_brick(Ball& ball, Bricks& brick, int& points) {

	return ball.ball_sprite.getGlobalBounds().intersects(brick.brick_sprite.getGlobalBounds());

}






