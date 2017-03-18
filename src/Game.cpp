/*
 * Game.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: dixtel
 */

#include "Game.h"

std::string ToString(int num);

Game::Game() {
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
}

Game::~Game() {
	delete window;
	window = NULL;
}


void Game::Start() {

	sf::Font font;
	if(!font.loadFromFile("font/Orbitron-Bold.ttf")) {
		std::cout << "Error load font" << std::endl;
	}

	sf::Text text_score_left;
	sf::Text text_score_right;

	sf::Text shadow_text_score_left;
	sf::Text shadow_text_score_right;

	text_score_left.setFont(font);
	text_score_left.setString("0");
	text_score_left.setPosition(width/4 - 64, 10);
	text_score_left.setCharacterSize(64);
	text_score_left.setColor(sf::Color(255, 255, 255, 100));

	text_score_right.setFont(font);
	text_score_right.setString("0");
	text_score_right.setPosition(width - width/4 + 18, 10);
	text_score_right.setCharacterSize(64);
	text_score_right.setColor(sf::Color(255, 255, 255, 100));

	shadow_text_score_left.setFont(font);
	shadow_text_score_left.setString("0");
	shadow_text_score_left.setPosition(width/4 - 64 + 5, 5);
	shadow_text_score_left.setCharacterSize(64);
	shadow_text_score_left.setColor(sf::Color(255, 255, 255, 255));

	shadow_text_score_right.setFont(font);
	shadow_text_score_right.setString("0");
	shadow_text_score_right.setPosition(width - width/4 + 18 + 5, 5);
	shadow_text_score_right.setCharacterSize(64);
	shadow_text_score_right.setColor(sf::Color(255, 255, 255, 255));



	sf::Clock clock;

	float radius_ball = 3;
	Ball ball(sf::Vector2f(width/2, height/2), radius_ball, sf::Color::White);
	Pad pad1(sf::Vector2f(20, height/2), sf::Vector2f(5, 30), sf::Color::White);
	Pad pad2(sf::Vector2f(480, height/2), sf::Vector2f(5, 30), sf::Color::White);

	Pad line(sf::Vector2f(width/2, 0), sf::Vector2f(5, height), sf::Color::White);

	BallRender ball_render(window, 20, width, height);

	while(!exit) {
		sf::Time delta = clock.restart();

		sf::Event event;
		if(window->pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				window->close();
				exit = true;
				return;
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			pad1.up = true;
		}
		else {
			pad1.up = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
			pad1.down = true;
		}
		else {
			pad1.down = false;
		}


		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			pad2.up = true;
		}
		else {
			pad2.up = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			pad2.down = true;
		}
		else {
			pad2.down = false;
		}

		pad1.Update(delta.asSeconds());
		pad2.Update(delta.asSeconds());

		ball.Update(delta.asSeconds());

		// collision

		if(ball.GetPos().y <= 0) ball.ReverseVerticalMove();
		else if(ball.GetPos().y >= height - radius_ball) ball.ReverseVerticalMove();

		if(ball.GetPos().x <= 0) {
			right_score++;
			return;
		}
		else if(ball.GetPos().x >= width - radius_ball) {
			left_score++;
			return;
		}

		if(pad1.Get().getGlobalBounds().intersects(ball.Get().getGlobalBounds())) {
			ball.ColidPad();
			ball.Faster();
			ball_render.EnableExplosion();

		}
		else if(pad2.Get().getGlobalBounds().intersects(ball.Get().getGlobalBounds())) {
			ball.ColidPad();
			ball.Faster();
			ball_render.EnableExplosion();
		}


		if(pad1.GetPos().y < 0) {
			pad1.SetPosition(pad1.Get().getPosition().x, 0 );
		}
		else if((pad1.GetPos().y + pad1.Get().getGlobalBounds().height ) > height) {
			pad1.SetPosition(pad1.Get().getPosition().x, height - pad1.Get().getGlobalBounds().height );
		}

		if(pad2.GetPos().y < 0) {
			pad2.SetPosition(pad2.Get().getPosition().x, 0);
		}
		else if((pad2.GetPos().y + pad2.Get().getGlobalBounds().height) > height) {
			pad2.SetPosition(pad2.Get().getPosition().x, height - pad2.Get().getGlobalBounds().height );
		}

		//

		text_score_left.setString(ToString(left_score));
		shadow_text_score_left.setString(ToString(left_score));
		text_score_right.setString(ToString(right_score));
		shadow_text_score_right.setString(ToString(right_score));

		window->clear(sf::Color::Black);
		window->draw(pad1.Get());
		window->draw(pad2.Get());
		window->draw(line.Get());
		window->draw(text_score_left);
		window->draw(text_score_right);
		window->draw(shadow_text_score_left);
		window->draw(shadow_text_score_right);

		ball_render.Draw(ball.Get(), delta.asSeconds());

		window->display();

	}
}

bool Game::Exit() {
	return exit;
}

std::string ToString(int num) {
	std::stringstream stream;
	stream << num;
	return stream.str();
}


