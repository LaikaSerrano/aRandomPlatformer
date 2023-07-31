#include "header.hpp"

int main()
{
    // Create the SFML window
	sf::VideoMode videoMode(800, 600, 32); // 800x600 resolution with 32 bits per pixel
	sf::RenderWindow window(videoMode, "SFML Window");
	
	// init the player with a size of 50x50
	Player player(sf::Color::Red, 100, 100, 50);

	player.setPos(100, 100);
    // runner
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
	window.clear(sf::Color::Blue);
        // Your game logic and drawing code here
	
	player.draw(window);
	player.update();
	window.display();
    }

    return 0;
}
