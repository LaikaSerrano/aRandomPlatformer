#include "terrain.hpp"

/*
 * Terrain class, this class will be herited to create platforms and other things
 * class Terrain{
 * 	public :
 * 		Terrain(sf::Color color, int sizeX, int sizeY, int posX, int posY);
 * 		~Terrain();
 * 		void draw(sf::RenderWindow &window);
 *		void applyGravity(Player &player);
 *		void setPos(float x, float y);
 *	private : 
 *		sf::Color color;
 *		sf::RectangleShape rect;
 * };
 * */

Terrain::Terrain(sf::Color color, int sizeX, int sizeY, int posX, int posY){
	this->color = color;
	this->rect = sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
	this->rect.setFillColor(this->color);
}

Terrain::~Terrain(){}

void Terrain::setPos(float x, float y){
	this->rect.setPosition(x, y);
}

void Terrain::draw(sf::RenderWindow &window){
	window.draw(this->rect);
}

void Terrain::applyGravity(Player &player){
	if(player.getRect().getPosition().y + player.getRect().getSize().y < SCREEN_HEIGHT){
		player.move(0, 0.2);
	}
}
