#include "functions.h"
#include "clockHand.h"

int main() {
    sf::VideoMode videoMode(720, 720, 32); // 32 bits are how many colors
    sf::RenderWindow window(videoMode, "Digital Analog Clock");   // "window" is the constructor
    window.setFramerateLimit(60);

    //Time
    auto pacificTime = std::chrono::system_clock::now();
    auto timeInfo = std::chrono::system_clock::to_time_t(pacificTime);
    std::tm localTime = *std::localtime(&timeInfo);

    //Objects
    sf::CircleShape clockFace;

    //Clock object
    clockFace.setRadius(window.getSize().y / 2);

    //Coordinate
    float xCenter, yCenter;
    sf::FloatRect bounds = clockFace.getGlobalBounds();
    xCenter = bounds.left + bounds.width / 2;
    yCenter = bounds.top + bounds.height / 2;

    //Create Hand
    clockHand hourHand
            (
                    1.f / 3600,
                    {clockFace.getRadius() * .4f, 7.f},
                    {xCenter, yCenter},
                    sf::Color::Blue,
                    static_cast<float>(localTime.tm_hour),
                    30.f
            );

    clockHand minuteHand
            (
                    1.f / 60,
                    {clockFace.getRadius() * .5f, 7.f},
                    {xCenter, yCenter},
                    sf::Color::Red,
                    static_cast<float>(localTime.tm_min),
                    6.f
            );

    clockHand secondHand
            (
                    1.f,
                    {clockFace.getRadius() * .9f, 7.f},
                    {xCenter, yCenter},
                    sf::Color::Black,
                    static_cast<float>(localTime.tm_sec),
                    6.f
    );

    while (window.isOpen()) {
        sf::Event event;

        //event listener
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        hourHand.rotate();
        minuteHand.rotate();
        secondHand.rotate();

        window.clear();         // clear screen,
        window.draw(clockFace);
        window.draw(secondHand);
        window.draw(minuteHand);
        window.draw(hourHand);
        window.display();       // display the screen.

    }
    return 0;
}
