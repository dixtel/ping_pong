/*
 * Ball.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: dixtel
 */

#include "Ball.h"

int Rand(int to_num);

Ball::Ball(sf::Vector2f pos, float radius , sf::Color color) {
	ball = new sf::CircleShape;
	ball->setPosition(pos);
	ball->setRadius(radius);
	ball->setFillColor(color);

	this->pos = pos;
}

Ball::~Ball() {
	delete ball;
	ball = NULL;
}


void Ball::Update(float delta) {
	velocity = sf::Vector2f(speed.x * direction.x, speed.y * direction.y);
	pos += sf::Vector2f(velocity.x * delta, velocity.y * delta);
	ball->setPosition(pos);
}

void Ball::ReverseVerticalMove() {
	if(direction.y < 0) direction.y -= direction.y * 2 ;
	else direction.y = - direction.y;
}

void Ball::ColidPad() {
	if(direction.x) direction.x = -direction.x;
	else direction.x -= direction.x + 2;

	if(direction.y > 0) direction.y = Rand(10) * 0.1;
	else direction.y = -(Rand(10) * 0.1);
}

void Ball::Faster() {
	speed.x += increase_speed;
}

sf::Vector2f Ball::GetPos() {
	return pos;
}

sf::CircleShape Ball::Get() {
	return *ball;
}

int Rand(int to_num) {
	static bool srand_bool = false;
	if(!srand_bool) {
		srand(time(NULL));
	}

	return rand() % to_num + 1;
}

