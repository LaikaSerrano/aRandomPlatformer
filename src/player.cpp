#include "player.hpp"
// class Player{
// public:
// 	Player(sf::Color color, int posX, int posY, int radius);
// 	~Player();
// 	void update();
// 	void move(double x, double y);
// 	void draw(sf::RenderWindow &window);
// 	void setPos(int x, int y);
// 	void setColor(sf::Color color);
// 	sf::FloatRect getRect();
// 	int* getPosition();
// 	int getRadius();
// 	void jump();
//
// private:
// 	sf::CircleShape player;
// 	bool isOnGround;
// 	double jumpSpeed;
// 	double gravity;
// 	int groundY = 500;
// 	std::chrono::steady_clock::time_point jumpStartTime;
// };
//Constructor
Player::Player(sf::Color color, int posX, int posY, int radius){
	player.setRadius(radius);
	player.setFillColor(sf::Color::Red);
	player.setPosition(posX, posY);
	isOnGround = true;
	jumpSpeed = -0.1;
	GRAVITY = 0.01;
}

/*
 * 	SETTERS
 */
//Set the position of the player
void Player::setPos(int x, int y){
	player.setPosition(x, y);
}
//Set the color (in the future the sprite)
void Player::setColor(sf::Color color){
	player.setFillColor(color);
}

/*
 * 	GETTERS
 */

// get the position of the player's hitbox
sf::FloatRect Player::getRect(){
	return player.getGlobalBounds();
}

//Get both x and y positions of the player
int* Player::getPosition(){
	int* pos = new int[2];
	pos[0] = player.getPosition().x;
	pos[1] = player.getPosition().y;
	return pos;
}

int Player::getRadius(){
	return player.getRadius();
}

/* 
 * 	PLAYER ACTIONS
 */

void Player::jump() {
	// if	(!isOnGround)
	// 	return;
	if (isOnGround && !isJumping) {
		isOnGround = false;
		isJumping = true;
		jumpStartTime = std::chrono::steady_clock::now();
		jumpSpeed = -JUMP_SPEED;
		maxJumpHeightReached = false;
		jumpTopReached = false;
	}
	initialY = player.getPosition().y;
	if (isJumping) {
		auto now = std::chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - jumpStartTime).count() / 1000.0;
		// Calculate the player's new position based on the elapsed time and jump speed
		double jumpHeight = jumpSpeed * elapsed + 0.5 * GRAVITY * elapsed * elapsed;
		double newY = initialY + jumpHeight;

		// Check if the player has reached the maximum jump height
		if (jumpHeight <= -MAX_JUMP_HEIGHT) {
			maxJumpHeightReached = true;
		}
		if (maxJumpHeightReached)
			jumpSpeed = JUMP_SPEED;

		// Check if the player has reached the top of the jump
		if (jumpSpeed >= 0 && !jumpTopReached) {
			jumpTopReached = true;
		}

		player.move(0, jumpSpeed);	
		// Check if the player has landed on the ground
		if (int(newY - 50) <= GROUND_HEIGHT) {
			newY = GROUND_HEIGHT;
			// std::cout << "landed" << std::endl;
			isJumping = false;
			isOnGround = true;
			jumpSpeed = -JUMP_SPEED;
		}

		// Update the player's position
		// setPos(player.getPosition().x, newY);
		// Update the jump speed based on the elapsed time and gravity
		jumpSpeed = jumpSpeed + GRAVITY * elapsed;
	}
}

//Move the player by x and y
void Player::move(double x, double y){
	player.move(x, y);
}
//Draw the player
void Player::draw(sf::RenderWindow &window){	
	window.draw(player);
}
//Check if the player has to move
void Player::update(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        jump();
	if(int(player.getPosition().y) == GROUND_HEIGHT)
        isOnGround = true;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(-0.01, 0);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(0.01, 0);
}
//Deconstructor
Player::~Player(){}
