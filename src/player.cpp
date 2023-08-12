#include "player.hpp"
/*class Player{
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
	double jumpSpeed;
	double gravity;
	int groundY = 500;
};*/
//Constructor
Player::Player(sf::Color color, int posX, int posY, int radius){
	player.setRadius(radius);
	player.setFillColor(sf::Color::Red);
	player.setPosition(posX, posY);
	isOnGround = true;
	jumpSpeed = -0.1;
	gravity = 0.01;
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


void Player::jump(){
        if (isOnGround && !isJumping) {
		isOnGround = false;
		isJumping = true;
		jumpStartTime = std::chrono::steady_clock::now();
		jumpSpeed = -1.0;
		maxJumpHeightReached = false;
		jumpTopReached = false;
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
//Check if the player as to move
void Player::update()
{
	if (isJumping) {
		// Calculate time since jump start
		auto currentTime = std::chrono::steady_clock::now();
		double elapsedSeconds = std::chrono::duration<double>(currentTime - jumpStartTime).count();

		// Update player's position based on jump physics
		if (!maxJumpHeightReached) {
			jumpSpeed += gravity * elapsedSeconds;

			// Check for maximum jump height and start falling
			if (jumpSpeed <= 0.0) {
				maxJumpHeightReached = true;
			}
		} else if (!jumpTopReached) {
			if (elapsedSeconds >= 0.2)
				jumpTopReached = true;
		} else {
                	// Apply stronger gravity during fall to simulate acceleration
                	gravity = 0.01 + elapsedSeconds * 0.3; // Adjust the acceleration factor as needed
                	jumpSpeed += gravity * elapsedSeconds;
            	}

            	player.move(0, jumpSpeed);

            // Check if player has landed
            	if (player.getPosition().y >= groundY) {
                	player.setPosition(player.getPosition().x, groundY);
                	isOnGround = true;
                	isJumping = false;
                	gravity = 0.5; // Reset gravity when landing
            	}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(-0.01, 0);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(0.01, 0);
}
//Deconstructor
Player::~Player(){}
