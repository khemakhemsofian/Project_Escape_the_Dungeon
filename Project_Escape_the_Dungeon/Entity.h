#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Entity {
public:
	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	std::string tag;

};

#endif // !ENTITY_H

