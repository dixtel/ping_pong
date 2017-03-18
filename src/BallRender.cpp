/*
 * BallRender.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: dixtel
 */

#include "BallRender.h"

std::vector <sf::CircleShape> MoveLeft(std::vector <sf::CircleShape> vector);
std::vector <sf::CircleShape> SetRGB_increase(std::vector <sf::CircleShape> vector, int r, int g, int b);

BallRender::BallRender(sf::RenderWindow *pointer, unsigned delay, int width, int height) {
	window = pointer;
	this->width = width;
	this->height = height;
	this->delay = delay;

	for(int i = 0; i < delay; i++) {
		sf::CircleShape ball;
		delayed_ball.push_back(ball);
	}
}

BallRender::~BallRender() {
	window = NULL;
}

void BallRender::Draw(sf::CircleShape ball, float delta) {
	delayed_ball.back() = ball;

	if(explosion) {
		std::string page;
		if(ball.getPosition().x < (width/2)) page = "left";
		else page = "right";

		friction_pad_animation tmp_animation;

		int width = 25;
		int height = 30;

		if(page == "right") {
			tmp_animation.SetPosition(ball.getPosition().x - (width - ball.getRadius()), ball.getPosition().y - (height/2));
		}
		else {
			tmp_animation.SetPosition(ball.getPosition().x, ball.getPosition().y - (height/2));
		}

		tmp_animation.SetPage(page);
		tmp_animation.Play();

		animation.push_back(tmp_animation);

		explosion = false;
	}

	std::cout << "size anim: " << animation.size() << std::endl;
	for(int i = 0; i < animation.size(); i++) {
		//std::cout << animation[i].animation_path[animation[i].animation_frame] << std::endl;
		std::cout << animation[i].reactangle.getSize().x << std::endl;

		if(!animation[i].IsPlay()) {
			animation.erase(animation.begin()+i);
			continue;
		}

		window->draw(animation[i].GetAnimation());
		animation[i].NextAnimation(delta);
	}

	if(delayed_draw) {
		delayed_ball = MoveLeft(delayed_ball);
		delayed_ball = SetRGB_increase(delayed_ball, 255, 255, 255);

		for(int i = 0; i < delayed_ball.size(); i ++) {
			window->draw(delayed_ball[i]);
		}
	}
	else {
		window->draw(ball);
	}
}

void BallRender::EnableExplosion() {
	explosion = true;
}

void BallRender::SetDelayedDraw(bool set) {
	delayed_draw = set;
}

std::vector <sf::CircleShape> MoveLeft(std::vector <sf::CircleShape> vector) {
	for(int i = 1; i < vector.size(); i++) {
		vector[i-1] = vector[i];
	}
	return vector;
}

std::vector <sf::CircleShape> SetRGB_increase(std::vector <sf::CircleShape> vector, int r, int g, int b) {
	float transparent = 0;
	float average = 255 / vector.size();
	for(int i = 0; i < vector.size() - 1; i++) {
		vector[i].setFillColor(sf::Color(r, g , b, transparent));
		transparent += average;
		if(transparent > 255) transparent = 255;
	}
	return vector;
}

