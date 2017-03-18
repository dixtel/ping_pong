/*
 * BallRender.h
 *
 *  Created on: Mar 7, 2017
 *      Author: dixtel
 */

#ifndef BALLRENDER_H_
#define BALLRENDER_H_

#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

class BallRender {
public:
	BallRender(sf::RenderWindow *pointer, unsigned delay, int width, int height);
	~BallRender();

	void Draw(sf::CircleShape ball, float delta);

	void EnableExplosion();
	void SetDelayedDraw(bool set);

protected:
	sf::RenderWindow *window = NULL;
	int width = 0;
	int height = 0;

	std::vector <sf::CircleShape> delayed_ball;

	struct friction_pad_animation {
		float x = 0;
		float y = 0;
		int width = 25;
		int height = 30;
		int animation_frame = 0;
		int max_frame = 10;
		int fps = 10;
		float time = 0;


		bool right = false;
		bool left = false;

		bool play = false;

		sf::Texture texture;
		sf::RectangleShape reactangle;

		std::string path = "Sprite/";
		std::string animation_path[10] = {path + "sprite_1.png", path + "sprite_2.png", path + "sprite_3.png", path + "sprite_4.png", path + "sprite_5.png", path + "sprite_6.png", path + "sprite_7.png", path + "sprite_8.png", path + "sprite_9.png", path + "sprite_10.png"};

		void SetPosition(float x, float y) {
			if(!play) {
				this->x = x;
				this->y = y;
			}
		}

		void SetPage(std::string page) {
			if(page == "right") {
				right = true;
				left = false;
			}
			else if(page == "left") {
				left = true;
				right = false;
			}
		}

		void SetFps(int fps) {
			this->fps = fps;
		}

		void ResetAnimation() {
			animation_frame = 0;
		}

		void Play() {
			play = true;
		}

		void NextAnimation(float delta) {
			if(play) {
				time += delta;

				if(time >= fps/1000) {
					animation_frame++;
					if(animation_frame >= max_frame) {
						ResetAnimation();
						play = false;
					}
					time = 0;
				}
			}
		}

		sf::RectangleShape GetAnimation() {

			if(left) {
				if(texture.loadFromFile(animation_path[animation_frame], sf::IntRect(width, 0, width, height))) {
					reactangle.setTexture(&texture, true);
				}
				else {
					std::cout << "Error load texture " << animation_path[animation_frame] << std::endl;
				}
			}
			else {
				if(texture.loadFromFile(animation_path[animation_frame], sf::IntRect(0, 0, width, height))) {
					reactangle.setTexture(&texture, true);
				}
				else {
					std::cout << "Error load texture " << animation_path[animation_frame] << std::endl;
				}
			}


			//reactangle.setFillColor(sf::Color::Red);
			reactangle.setSize(sf::Vector2f(width, height));
			reactangle.setPosition(x, y);

			return reactangle;
		}

		bool IsPlay() {
			return play;
		}

	};

	std::vector <friction_pad_animation> animation;

	bool delayed_draw = true;
	bool explosion = false;
	unsigned delay = 0;
};

#endif /* BALLRENDER_H_ */
