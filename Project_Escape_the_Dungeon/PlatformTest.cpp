#include "PlatformTest.h"

PlatformTest::PlatformTest(float posX, float posY, float width, float height) {
    platformShape.setSize(sf::Vector2f(width, height));
    platformShape.setPosition(sf::Vector2f(posX, posY));
    platformShape.setFillColor(sf::Color::Red);
}

void PlatformTest::draw(sf::RenderWindow& window) const {
    window.draw(platformShape);
}

sf::FloatRect PlatformTest::getGlobalBounds() const {
    return platformShape.getGlobalBounds();
}