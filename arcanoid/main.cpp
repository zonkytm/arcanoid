#include <SFML/Graphics.hpp>
#include "ball.h"
#include "paddle.h"
#include "ball_paddle.h"
#include "Bricks.h"
using namespace sf;



int main() {
	RenderWindow window(VideoMode(500, 500),"Arcanoid");
	window.setFramerateLimit(60);
	Image ball_image, paddle_image;
	ball_image.loadFromFile("sprites/Breakout/img/ball.png");
	paddle_image.loadFromFile("sprites/Breakout/img/paddle.png");
	Paddle game_paddle(paddle_image,10);
	Ball game_ball(ball_image, Vector2f(game_paddle.paddle_sprite.getPosition().x, game_paddle.paddle_sprite.getPosition().y - 50), -6 , -5);
	Bricks bricks[100];
	int n_brick = 0;
	int points = 0;
	for (int  i = 1; i <= 7; i++)
	{
		for (int  j = 1; j <=7; j++)
		{
			bricks[n_brick].brick_sprite.setPosition((i) * 64, j * 32+10);
			bricks[n_brick].brick_sprite.setColor(Color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1));
			n_brick++;
		}
	}

	Font font;
	font.loadFromFile("fonts/GangSmallYuxian.ttf");
	Text kill_number("", font);
	kill_number.setFillColor(Color::Yellow);




	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type==Event::Closed)
			{
				window.close();
			}
			if (!game_ball.ball_life)
			{


				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Space)
					{
						
						game_ball.ball_life = !game_ball.ball_life;
						game_ball.ball_speed_vector = VECTOR(-6, -5);
					}
				}
			}
		}
		game_paddle.ban_exit();
		game_paddle.movement();
		game_paddle.update();
		if (game_ball.ball_life)
		{

			intersections_ball_paddle(game_paddle, game_ball);

			

			game_ball.ban_exit(game_paddle);
			game_ball.update();
			game_ball.ball_sprite.move(game_ball.ball_speed_vector.x, 0);
			for (int k = 0; k < n_brick; k++)
			{
				if (intersects_ball_brick(game_ball, bricks[k], points)) {

					game_ball.ball_speed_vector.x = -game_ball.ball_speed_vector.x;
					bricks[k].brick_sprite.setPosition(-100, 0);
					points++;
				}

			}
			game_ball.ball_sprite.move( 0, game_ball.ball_speed_vector.y);
			for (int k = 0; k < n_brick; k++)
			{
				if (intersects_ball_brick(game_ball, bricks[k], points)) {

					game_ball.ball_speed_vector.y = -game_ball.ball_speed_vector.y;
					bricks[k].brick_sprite.setPosition(-100, 0);
					points++;
				}

			}
			

		}
		else
		{
			game_ball.ball_sprite.setPosition(game_paddle.paddle_sprite.getPosition().x, game_paddle.paddle_sprite.getPosition().y-game_ball.ball_sprite.getGlobalBounds().height/2-game_paddle.paddle_sprite.getGlobalBounds().height);
		}
		window.clear();
		window.draw(game_ball.ball_sprite);
		for (int  i = 0; i < n_brick; i++)
		{
			window.draw(bricks[i].brick_sprite);
		}
		window.draw(game_paddle.paddle_sprite);
		kill_number.setString("points: " + to_string(points));
		window.draw(kill_number);
		window.display();


	}





}