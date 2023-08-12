#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>

#include "consts.hpp"

class Player{
	public:
		Player(sf::Color color, int posX, int posY, int radius);
		~Player();
		void update();
		void move(double x, double y);
		void draw(sf::RenderWindow &window);
		void setPos(int x, int y);
		void setColor(sf::Color color);
		sf::FloatRect getRect();
		int* getPosition();
		int getRadius();
		void jump();

	private:
		sf::CircleShape player;
		bool isOnGround;
		bool isJumping;
		bool maxJumpHeightReached;
		bool jumpTopReached;
		double jumpSpeed;
		double gravity;
		int groundY = 500;
		std::chrono::steady_clock::time_point jumpStartTime;
};
#endif

