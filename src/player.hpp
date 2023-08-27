#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <chrono>
#include <thread>
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
		void jump();
		int* getPosition();
		int jumpHeight = -300;
		int getRadius();
		double jumpSpeed;
		double initialY; 
		bool isOnGround;
		bool isJumping = false;
		bool maxJumpHeightReached;
		bool jumpTopReached;
		sf::CircleShape player;
		sf::FloatRect getRect();

	private:
		double JUMP_SPEED = 1.;
		double GRAVITY;
		int GROUND_HEIGHT = GROUND_HEIGHT_CONST;
		int MAX_JUMP_HEIGHT = 100;		
		std::chrono::steady_clock::time_point jumpStartTime;
};
#endif

