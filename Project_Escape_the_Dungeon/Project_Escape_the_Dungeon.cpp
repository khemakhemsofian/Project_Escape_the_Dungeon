#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Ennemi.h"
#include "ChaserEnemy.h"
#include "PatrollingEnemy.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "The Escape Dungeon");

    Player player(100, 100, 50.0f);
    std::vector<std::unique_ptr<Entity>> ennemis;
    ennemis.push_back(std::make_unique<ChaserEnemy>(300, 100, 50.0f));
    ennemis.push_back(std::make_unique<PatrollingEnemy>(500, 200, 70.0f, std::vector<sf::Vector2f>{{500.0f, 200.0f}, { 700.0f, 200.0f }, { 700.0f, 400.0f }, { 500.0f, 400.0f }}));

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

        for (auto& ennemi : ennemis) {
            if (auto* chaser = dynamic_cast<ChaserEnemy*>(ennemi.get())) {
                chaser->update(deltaTime.asSeconds(), player);
            }
            else {
                ennemi->update(deltaTime.asSeconds());
            }
        }

        for (const auto& ennemi : ennemis) {
            if (player.checkCollision(*ennemi)) {
                std::cout << "GameOver : il a toucher c'est foutu" << std::endl;
                window.close();
            }
        }

        window.clear();
        player.draw(window);
        for (const auto& ennemi : ennemis) {
            ennemi->draw(window);
        }
        window.display();
    }

    return 0;
}