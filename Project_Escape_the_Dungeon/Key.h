#ifndef KEY_H
#define KEY_H
#include "Interactable.h"



class Key : public Interactable {
public:
    Key(int posX, int posY);
    void interact(Player& player) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    sf::FloatRect getGlobalBounds() const override;
    void handleInteractableCollision(Player& player);
private:
    sf::RectangleShape keyShape;
    sf::Vector2f position;
};

#endif // KEY_H
