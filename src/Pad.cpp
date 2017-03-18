/*
 * Pad.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: dixtel
 */

#include "Pad.h"

Pad::Pad(sf::Vector2f pos, sf::Vector2f size, sf::Color color) {
	pad = new sf::RectangleShape;
	pad->setPosition(pos);
	pad->setSize(size);
	pad->setFillColor(color);

	this->pos = pos;
}

Pad::~Pad() {
	delete pad;
	pad = NULL;
}


void Pad::Update(float delta) {
	if(up) {
		velocityy -= speed * acceleration;
	}
	else if(down) {
		velocityy += speed * acceleration;
	}

	if(velocityy > 0) {
		velocityy -= friction;
		if(velocityy < 0) velocityy = 0;
	}
	else if(velocityy < 0) {
		velocityy += friction;
		if(velocityy > 0) velocityy = 0;
	}

	if(abs(velocityy) > max_speed) {
		if(velocityy > 0) velocityy = max_speed;
		else velocityy = -max_speed;
	}


	pos.y += velocityy * delta;
	pad->setPosition(pos);
}

void Pad::SetPosition(float x, float y) {
	pos.x = x;
	pos.y = y;
	pad->setPosition(x, y);
}


sf::Vector2f Pad::GetPos() {
	return pos;
}

sf::RectangleShape Pad::Get() {
	return *pad;
}


