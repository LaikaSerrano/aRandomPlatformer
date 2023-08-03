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
private:
	sf::CircleShape player;
};*/
//Constructor
Player::Player(sf::Color color, int posX, int posY, int radius){
	player.setRadius(radius);
	player.setFillColor(sf::Color::Red);
	player.setPosition(posX, posY);
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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move(0, -0.3);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(-0.01, 0);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(0.01, 0);
}
//Set the position of the player
void Player::setPos(int x, int y){
	player.setPosition(x, y);
}
//Set the color (in the future the sprite)
void Player::setColor(sf::Color color){
	player.setFillColor(color);
}
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
//Deconstructor
Player::~Player(){}
