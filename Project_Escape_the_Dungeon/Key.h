#ifndef KEY_H
#define KEY_H
#include "Interactable.h"

class Key : public Entity, public Interactable {
public:
    Key(int posX, int posY);
    void interact(Player& player) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    sf::FloatRect getGlobalBounds() const override;
	bool checkCollision(const Entity& other) const override;
    // void handleInteractableCollision(Player& player); // Commentée ou supprimée

private:
    sf::RectangleShape keyShape;
    sf::Vector2f position;
};

#endif // KEY_H