#ifndef OBJET_H
#define OBJET_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"

class Objet : public Entity {

public:
	Objet(int posX, int posY, float objetSpeed);
	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	std::string tag = "Objet";

};
#endif // !OBJET_H

