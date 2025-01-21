#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "ChaserEnemy.h"
#include "PatrollingEnemy.h"
#include "Potion.h"
#include "Key.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "The Escape Dungeon");

    Player player(100.0f, 100.0f, 50.0f); 
    std::vector<std::unique_ptr<Entity>> ennemis;
    ennemis.push_back(std::make_unique<ChaserEnemy>(300, 100, 50.0f, player));
    ennemis.push_back(std::make_unique<PatrollingEnemy>(500, 200, 70.0f, std::vector<sf::Vector2f>{{500.0f, 200.0f}, { 700.0f, 200.0f }, { 700.0f, 400.0f }, { 500.0f, 400.0f }}, player));

    std::vector<sf::RectangleShape> platformShape;
    sf::RectangleShape platform1(sf::Vector2f(1600.0f, 50.0f));
    platform1.setPosition(0.0f, 1000.0f);
    platformShape.push_back(platform1);

    std::vector<std::unique_ptr<Interactable>> interactables;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int i = 0; i < 5; ++i) {
        int x = std::rand() % 1500 + 50;
        int y = std::rand() % 900 + 50;
        if (std::rand() % 2 == 0) {
            interactables.push_back(std::make_unique<Potion>(x, y));
        }
        else {
            interactables.push_back(std::make_unique<Key>(x, y));
        }
    }

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

        for (const auto& platform : platformShape) {
            player.handlePlatformCollision(platform);
        }

        for (auto& ennemi : ennemis) {
            if (auto* chaser = dynamic_cast<ChaserEnemy*>(ennemi.get())) {
                chaser->update(deltaTime.asSeconds());
            }
            else {
                ennemi->update(deltaTime.asSeconds());
            }
        }

        for (auto& interactable : interactables) {
            player.handleInteractableCollision(*interactable);
        }

        window.clear();
        player.draw(window);
        for (const auto& platform : platformShape) {
            window.draw(platform);
        }
        for (const auto& ennemi : ennemis) {
            ennemi->draw(window);
        }
        for (const auto& interactable : interactables) {
            interactable->draw(window);
        }
        window.display();
    }

    return 0;
}