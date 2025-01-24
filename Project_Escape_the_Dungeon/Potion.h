#ifndef POTION_H
#define POTION_H
#include "Interactable.h"
#include "Player.h"

class Potion : public Entity, public Interactable {
public:
    Potion(int posX, int posY, Player _player);
    void interact(Player& player) override;
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) const override;
    sf::FloatRect getGlobalBounds() const override;
    //bool checkCollision(const Entity& other) const override;
	bool isEffectActive() const;
    bool isAnyPotionActive();
    void setAnyPotionActive(bool active);
    ~Potion();
    sf::RectangleShape potionShape;
    Player& player;
private:
    sf::Vector2f position;
    sf::Clock effectClock;
    const sf::Time effectDuration = sf::seconds(2.0f);
    bool effectActive;
    float originalSpeed;
    bool anyPotionActive;
	
};

#endif // POTION_H