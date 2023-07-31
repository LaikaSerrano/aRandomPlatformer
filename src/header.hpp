#ifndef HEADER_HPP
#define HEADER_HPP
#include <SFML/Graphics.hpp>

class Player{
public:
	Player(sf::Color color, int posX, int posY, int radius);
	~Player();
	void update();
	void move(double x, double y);
	void draw(sf::RenderWindow &window);
	void setPos(int x, int y);
	void setColor(sf::Color color);

private:
	sf::CircleShape player;
};

#endif
