//
// Created by ASUS on 4/13/2023.
//

#include "functions.h"

sf::RectangleShape creatHand(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::Vector2f origin)
{
    sf::RectangleShape hand;
    hand.setSize(size);
    hand.setFillColor(color);
    hand.setPosition(position);
    hand.setOrigin(origin);

    return hand;
}
