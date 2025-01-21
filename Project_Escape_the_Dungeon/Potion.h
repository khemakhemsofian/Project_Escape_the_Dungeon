#ifndef POTION_H
#define POTION_H
#include "Interactable.h"

class Potion : public Interactable {
public:
    Potion(int posX, int posY);
    void interact(Player& player) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    sf::FloatRect getGlobalBounds() const override;
    void handleInteractableCollision(Player& player); 

private:
    sf::RectangleShape potionShape;
    sf::Vector2f position;
};

#endif // POTION_H
