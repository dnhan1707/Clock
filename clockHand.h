//
// Created by ASUS on 10/2/2023.
//

#ifndef ANALOG_DIGITAL_CLOCK_CLOCKHAND_H
#define ANALOG_DIGITAL_CLOCK_CLOCKHAND_H
#include "iostream"
#include <SFML/Graphics.hpp>
#include <chrono>

class clockHand : public sf::RectangleShape
{

private:

    //member variable
    float current_time, unit;
    float speed;
    sf::Color color;
    sf::Vector2f position, size;
    sf::Clock clock;

public:
    //Constructor, 3 type: Default (no parameter), and... , and...
    clockHand();
    clockHand(float speed, sf::Vector2f size, sf::Vector2f position, sf::Color color, float current_time, float unit);

    void rotate();

};



#endif //ANALOG_DIGITAL_CLOCK_CLOCKHAND_H
