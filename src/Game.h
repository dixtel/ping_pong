/*
 * Game.h
 *
 *  Created on: Mar 4, 2017
 *      Author: dixtel
 */

#ifndef GAME_H_
#define GAME_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#include "Pad.h"
#include "Ball.h"
#include "BallRender.h"

class Game {
public:
	Game();
	~Game();

	void Start();

	bool Exit();
protected:
	const int width = 500;
	const int height = 500;
	const std::string title = "Ping Pong!";

private:
	sf::RenderWindow *window = NULL;

	bool exit = false;

	int left_score = 0;
	int right_score = 0;
};

#endif /* GAME_H_ */
