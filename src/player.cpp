#include "header.hpp"

/*class Player{
public:
	Player(sf::Color color, int posX, int posY, int radius);
	~Player();
	void update();
	void move(int x, int y);
	void draw(sf::RenderWindow &window);
	void setPos(int x, int y);
	void setColor(sf::Color color);
private:
	sf::CircleShape player;
};*/

Player::Player(sf::Color color, int posX, int posY, int radius){
	player.setRadius(radius);
	player.setFillColor(sf::Color::Red);
	player.setPosition(posX, posY);
}

void Player::move(double x, double y){
	player.move(x, y);
}

void Player::draw(sf::RenderWindow &window){
	window.draw(player);
}

void Player::update()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		move(0, -0.01);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		move(0, 0.01);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		move(-0.01, 0);
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		move(0.01, 0);
	}
}

void Player::setPos(int x, int y){
	player.setPosition(x, y);
}

void Player::setColor(sf::Color color){
	player.setFillColor(color);
}

Player::~Player(){
}

