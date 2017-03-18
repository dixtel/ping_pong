/*
 * Ball.h
 *
 *  Created on: Mar 4, 2017
 *      Author: dixtel
 */

#ifndef BALL_H_
#define BALL_H_

#include "SFML/Graphics.hpp"
#include <stdlib.h>
#include <time.h>

#include <iostream>

class Ball {
public:
	Ball(sf::Vector2f pos, float radius, sf::Color color);
	~Ball();

	void Update(float delta);
	void ReverseVerticalMove();
	void ColidPad();
	void Faster();

	sf::Vector2f GetPos();
	sf::CircleShape Get();
private:
	sf::Vector2f pos = sf::Vector2f(0, 0);
	sf::Vector2f velocity = sf::Vector2f(100, 0);
	sf::Vector2f direction = sf::Vector2f(1, 0);
	sf::Vector2f speed = sf::Vector2f(100, 200);

	int increase_speed = 10;

	sf::CircleShape *ball = NULL;
};

#endif /* BALL_H_ */
