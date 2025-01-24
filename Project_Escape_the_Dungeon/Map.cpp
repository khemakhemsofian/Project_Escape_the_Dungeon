#include "Map.h"
#include <fstream>
#include <sstream>

Map::Map(const std::string& filename, Player& player) : player(player) {
    loadMap(filename);
}

void Map::loadMap(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    int y = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        char tile;
        int x = 0;

        while (iss >> tile) {
            sf::RectangleShape shape(sf::Vector2f(50.0f, 50.0f));
            shape.setPosition(x * 50.0f, y * 50.0f);

            switch (tile) {
            case 'W': // Wall
                shape.setFillColor(sf::Color::White); // Couleur blanche pour les murs
                walls.push_back(shape);
                break;
            case 'P': // Potion
                potions.push_back(std::make_unique<Potion>(x * 50, y * 50, player));
                break;
            case 'K': // Key
                keys.push_back(std::make_unique<Key>(x * 50, y * 50));
                break;
            case 'C': // ChaserEnemy
                enemies.push_back(std::make_unique<ChaserEnemy>(x * 50, y * 50, 50.0f, player));
                break;
            case 'T': // PatrollingEnemy
                enemies.push_back(std::make_unique<PatrollingEnemy>(x * 50, y * 50, 70.0f, std::vector<sf::Vector2f>{{x * 50.0f, y * 50.0f}}, player));
                break;
            case 'D': // Door
                shape.setFillColor(sf::Color::Cyan); // Couleur cyan pour les portes
                doors.push_back(shape);
                break;
            case '.': // Floor
                shape.setFillColor(sf::Color::Magenta); // Couleur magenta pour les sols
                floors.push_back(shape);
                break;
            case ' ': // Empty space
                // Do nothing for empty spaces
                break;
            }
            x++;
        }
        y++;
    }
}

void Map::draw(sf::RenderWindow& window) {
    sf::View view = window.getView();
    sf::FloatRect viewBounds(view.getCenter() - view.getSize() / 2.0f, view.getSize());

    for (const auto& wall : walls) {
        if (viewBounds.intersects(wall.getGlobalBounds())) {
            window.draw(wall);
        }
    }
    for (const auto& floor : floors) {
        if (viewBounds.intersects(floor.getGlobalBounds())) {
            window.draw(floor);
        }
    }
    for (const auto& door : doors) {
        if (viewBounds.intersects(door.getGlobalBounds())) {
            window.draw(door);
        }
    }
    for (const auto& potion : potions) {
        if (viewBounds.intersects(potion->getGlobalBounds())) {
            potion->draw(window);
        }
    }
    for (const auto& key : keys) {
        if (viewBounds.intersects(key->getGlobalBounds())) {
            key->draw(window);
        }
    }
    for (const auto& enemy : enemies) {
        if (viewBounds.intersects(enemy->getGlobalBounds())) {
            enemy->draw(window);
        }
    }
}

void Map::update(float deltaTime) {
    for (auto& potion : potions) {
        potion->update(deltaTime);
    }
    for (auto& key : keys) {
        key->update(deltaTime);
    }
    for (auto& enemy : enemies) {
        enemy->update(deltaTime);
    }
}

//bool Map::checkCollision(const sf::FloatRect& bounds) const {
//    for (const auto& wall : walls) {
//        if (wall.getGlobalBounds().intersects(bounds)) {
//            return true;
//        }
//    }
//    return false;
//}