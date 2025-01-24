#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include "Player.h"
#include "Potion.h"
#include "Key.h"
#include "ChaserEnemy.h"
#include "PatrollingEnemy.h"

class Map {
public:
    Map(const std::string& filename, Player& player);
    void loadMap(const std::string& filename);
    void draw(sf::RenderWindow& window);
    void update(float deltaTime);
    //bool checkCollision(const sf::FloatRect& bounds) const;
    const std::vector<sf::RectangleShape>& getWalls() const { return walls; }
    const std::vector<sf::RectangleShape>& getFloors() const { return floors; }

private:
    std::vector<sf::RectangleShape> walls;
    std::vector<sf::RectangleShape> floors;
    std::vector<sf::RectangleShape> doors;
    std::vector<std::unique_ptr<Potion>> potions;
    std::vector<std::unique_ptr<Key>> keys;
    std::vector<std::unique_ptr<Entity>> enemies;
    Player& player;
    sf::View view;
};

#endif // MAP_H