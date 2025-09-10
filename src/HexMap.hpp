#ifndef HEXMAP_HPP
#define HEXMAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>

// A single hex tile
struct HexTile {
    sf::ConvexShape shape;  // Hexagon geometry
    sf::Color color;        // Fill color
    int row, col;           // Grid position
};

class HexMap : public sf::Drawable {
public:
    HexMap(unsigned int rows, unsigned int cols, float radius);

    // Generate hexagonal grid
    void generate();

    // Set color of a specific tile
    void setTileColor(unsigned int row, unsigned int col, const sf::Color& color);

    // Get tile at grid position (nullptr if out of bounds)
    HexTile* getTile(unsigned int row, unsigned int col);

private:
    unsigned int m_rows;
    unsigned int m_cols;
    float m_radius;
    std::vector<HexTile> m_tiles;

    // Helper: create a single hex shape centered at (x, y)
    sf::ConvexShape createHexagon(float x, float y, float radius) const;

    // For sf::Drawable
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif