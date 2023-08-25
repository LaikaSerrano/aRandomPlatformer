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
		bool isOnGround;

	private:
		sf::CircleShape player;
		bool isJumping = false;
		bool maxJumpHeightReached;
		bool jumpTopReached;
		double jumpSpeed;
		double JUMP_SPEED = 1.;
		double GRAVITY;
		double initialY; 
		int GROUND_HEIGHT = 500;
		int MAX_JUMP_HEIGHT = 100;		
		std::chrono::steady_clock::time_point jumpStartTime;
};
#endif

