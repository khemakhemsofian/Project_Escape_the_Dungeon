#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"

class Interactable {
public:
    virtual void interact(Player& player) = 0;
};

#endif // INTERACTABLE_H