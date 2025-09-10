#include <SFML/Graphics.hpp>
#include "HexMap.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({1000u, 800u}), "HexMap Example");

    HexMap map(20, 25, 30.f);
    map.setTileColor(3, 3, sf::Color::Green);
    map.setTileColor(5, 7, sf::Color::Blue);
    map.setTileColor(15, 17, sf::Color::Red);

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(map);
        window.display();
    }
}