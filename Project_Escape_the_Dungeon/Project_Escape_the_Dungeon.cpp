#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Entity.h"
#include "ChaserEnemy.h"
#include "PatrollingEnemy.h"
#include "Potion.h"
#include "Key.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 960), "The Escape Dungeon");

    Player player(100.0f, 100.0f, 150.0f);
    std::vector<std::unique_ptr<Entity>> ennemis;
    ennemis.push_back(std::make_unique<ChaserEnemy>(300, 100, 50.0f, player));
    ennemis.push_back(std::make_unique<PatrollingEnemy>(500, 200, 70.0f, std::vector<sf::Vector2f>{{500.0f, 200.0f}, { 700.0f, 200.0f }, { 700.0f, 400.0f }, { 500.0f, 400.0f }}, player));

    std::vector<sf::RectangleShape> platformShape;
    sf::RectangleShape platform1(sf::Vector2f(1200.0f, 50.0f));
    platform1.setPosition(0.0f, window.getSize().y - platform1.getSize().y);
    platformShape.push_back(platform1);

    std::vector<std::unique_ptr<Potion>> potions;
    potions.push_back(std::make_unique<Potion>(0,0, player));
    std::vector<std::unique_ptr<Key>> keys;
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int y = window.getSize().y - platform1.getSize().y - potions[0]->potionShape.getSize().y;
	potions.erase(potions.begin());
    int numPotions = std::rand() % 4 + 2;
    for (int i = 0; i < numPotions; ++i) {
        int x = std::rand() % 1200 + 50;
        potions.push_back(std::make_unique<Potion>(x, y, player));
    }
    int x = std::rand() % 1200 + 50;
    keys.push_back(std::make_unique<Key>(x, y));
   
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


        for (auto it = potions.begin(); it != potions.end();) {
            player.potionClock.restart();
            (*it)->update(deltaTime.asSeconds());
            if (!(*it)->isEffectActive() && player.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
                if (!(*it)->isAnyPotionActive()) {
                    
                    (*it)->interact(player);
                    it = potions.erase(it);
                    std::cout << "Potion recuperee et retiree du jeu." << std::endl;
                }
                else {
                    ++it;
                }
            }
            else {
                ++it;
            }
        }

        for (auto it = keys.begin(); it != keys.end();) {
            if (player.getGlobalBounds().intersects((*it)->getGlobalBounds())) {
                (*it)->interact(player);
                it = keys.erase(it);
                std::cout << "Cle recuperee et retiree du jeu." << std::endl;
            }
            else {
                ++it;
            }
        }

        window.clear();
        player.draw(window);
        for (const auto& platform : platformShape) {
            window.draw(platform);
        }
        if (!nullptr)
        {
            for (const auto& ennemi : ennemis) {
                ennemi->draw(window);
            }

            for (const auto& potion : potions) {

                potion->draw(window);
            }
            for (const auto& key : keys) {
                key->draw(window);
            }
        }
       
        window.display();
    }

    return 0;
}