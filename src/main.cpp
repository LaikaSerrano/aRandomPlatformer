#include "header.hpp"
// petit type :)

int main(){
    // Create the SFML window
	sf::VideoMode videoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32); 
	sf::RenderWindow window(videoMode, "Platformer");

	//create the player
	Player player(sf::Color::Red, 100, 100, 50);
	player.setPos(100, 100);

	//create the terrain
	Terrain terrain(sf::Color::Green, SCREEN_WIDTH, SCREEN_HEIGHT, 100, 0);

	// runner
	while (window.isOpen()){

		sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
              	window.close();
			else if (event.type == sf::Event::KeyPressed){
				if (event.key.code == sf::Keyboard::Space && player.isOnGround){
					for (int i = 0; i < 100; i++)					
						player.move(0, i);
				}
			}
		}
		//draw logic
		terrain.draw(window);
		player.draw(window);
		
		terrain.applyGravity(player);
		player.update();
		window.display();
	}

    return 0;
}
