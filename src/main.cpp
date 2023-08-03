#include "header.hpp"
#include <iostream>
// petit type :)

int main()
{
    // Create the SFML window
	sf::VideoMode videoMode(800, 600, 32); 
	sf::RenderWindow window(videoMode, "Platformer");

	//create the player
	Player player(sf::Color::Red, 100, 100, 50);
	player.setPos(100, 100);	    
	
	//create the terrain
	Terrain terrain(sf::Color::Black);
	terrain.setPos(0, 0);

	// runner
	while (window.isOpen()){

		sf::Event event;
        	while (window.pollEvent(event))
        	{
            	if (event.type == sf::Event::Closed)
                	window.close();
        	}
		window.clear(sf::Color::Blue);
	
		//draw logic
		terrain.draw(window);
		player.draw(window);
		
		terrain.applyGravity(player);
		player.update();
		window.display();
	}

    return 0;
}
