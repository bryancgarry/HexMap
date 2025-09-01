#include <SFML/Graphics.hpp>
//#include <optional> // needed for pollEvent return type

int main() {
    // In SFML 3, VideoMode takes a sf::Vector2u
    sf::RenderWindow window(sf::VideoMode({800u, 600u}), "SFML Window");

    sf::CircleShape shape(100.f, 6);
    shape.setFillColor(sf::Color::Green);

    shape.setOrigin({shape.getRadius(), shape.getRadius()});
    sf::Vector2f pos(400.0f, 300.0f);
    shape.setPosition(pos);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }
 
        // Clear screen
        window.clear();
 
        // Draw the sprite
        window.draw(shape);
 
        // Update the window
        window.display();
    }

    return 0;
}