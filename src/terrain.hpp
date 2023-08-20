#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#include <SFML/Graphics.hpp>
#include "player.hpp"

class Terrain{
	public :
		Terrain(sf::Color color, int sizeX, int sizeY, int posX, int posY);
		~Terrain();
		void draw(sf::RenderWindow &window);
		void applyGravity(Player &player);
		void setPos(float x, float y);
	private : 
		sf::Color color;
		sf::RectangleShape rect;
};
#endif
