/*
 * Pad.h
 *
 *  Created on: Mar 4, 2017
 *      Author: dixtel
 */

#ifndef PAD_H_
#define PAD_H_

#include <SFML/Graphics.hpp>

class Pad {
public:
	Pad(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
	~Pad();

	bool up = false;
	bool down = false;

	void Update(float delta);
	void SetPosition(float x, float y);
	sf::Vector2f GetPos();
	sf::RectangleShape Get();
private:
	sf::Vector2f pos = sf::Vector2f(0, 0);
	float velocityy = 0;
	float speed = 100;
	float acceleration = 0.7;
	float friction = 20;
	float max_speed = 200;

	sf::RectangleShape *pad = NULL;
};

#endif /* PAD_H_ */
