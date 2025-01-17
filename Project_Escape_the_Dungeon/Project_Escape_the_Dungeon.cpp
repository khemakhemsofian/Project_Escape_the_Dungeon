#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Player.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(1600, 1200), "The Escape Dungeon");

    Player player(100, 100, 50.0f);
  
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); 
        }
        sf::Time deltaTime = clock.restart();
        player.handleInput(window);
        player.update(deltaTime.asSeconds());
        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}
