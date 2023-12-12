//
// Created by ASUS on 10/2/2023.
//

#include "clockHand.h"


clockHand::clockHand()
{

}

clockHand::clockHand(float speed, sf::Vector2f size, sf::Vector2f position, sf::Color color, float current_time, float unit)
: speed(speed), size(size), color(color), position(position), current_time(current_time), unit(unit)  //initializing area
{
    sf::FloatRect bounds = getGlobalBounds();

    setSize(size);
    setPosition(position);
    setFillColor(color);

    setOrigin({bounds.left, bounds.top + bounds.height/2});
    
    std::cout << "Current time: " << current_time << std::endl;
    std::cout << "Unit: " << unit << std::endl;

    sf::RectangleShape::rotate(unit * current_time - 90);

}

void clockHand::rotate()
{
    if(clock.getElapsedTime().asSeconds() > 1)
    {
        sf::RectangleShape::rotate(6*speed);
        clock.restart();
    }
}

