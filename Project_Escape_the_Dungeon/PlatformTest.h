#ifndef PLATFORMTEST_H
#define PLATFORMTEST_H

#include <SFML/Graphics.hpp>

class PlatformTest {
public:
    PlatformTest(float posX, float posY, float width, float height);
    void draw(sf::RenderWindow& window) const;
    sf::FloatRect getGlobalBounds() const;

private:
    sf::RectangleShape platformShape;
};

#endif // PLATFORMTEST_H
