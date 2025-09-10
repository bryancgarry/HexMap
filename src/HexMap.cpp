#include "HexMap.hpp"
#include <cmath>

HexMap::HexMap(unsigned int rows, unsigned int cols, float radius)
    : m_rows(rows), m_cols(cols), m_radius(radius) {
    generate();
}

void HexMap::generate() {
    m_tiles.clear();

    float hexHeight = m_radius * 2.f;
    float hexWidth = std::sqrt(3.f) * m_radius;
    float vertSpacing = hexHeight * 0.75f; // vertical spacing for offset rows

    for (unsigned int row = 0; row < m_rows; ++row) {
        for (unsigned int col = 0; col < m_cols; ++col) {
            float x = col * hexWidth + ((row % 2) ? hexWidth / 2.f : 0.f);
            float y = row * vertSpacing;

            HexTile tile;
            tile.shape = createHexagon(x, y, m_radius);
            tile.shape.setFillColor(sf::Color::White);
            tile.color = sf::Color::White;
            tile.row = row;
            tile.col = col;

            m_tiles.push_back(tile);
        }
    }
}

sf::ConvexShape HexMap::createHexagon(float x, float y, float radius) const {
    sf::ConvexShape hex;
    hex.setPointCount(6);
    for (int i = 0; i < 6; ++i) {
        float angle = M_PI / 3.f * i - M_PI / 6.f; // flat-topped
        hex.setPoint(i, sf::Vector2f(
            radius * std::cos(angle),
            radius * std::sin(angle)
        ));
    }
    hex.setOrigin(sf::Vector2f(radius, radius)); // adjust origin for positioning
    hex.setPosition(sf::Vector2f(x, y));
    hex.setOutlineColor(sf::Color::Black);
    hex.setOutlineThickness(1.f);
    return hex;
}

void HexMap::setTileColor(unsigned int row, unsigned int col, const sf::Color& color) {
    HexTile* tile = getTile(row, col);
    if (tile) {
        tile->color = color;
        tile->shape.setFillColor(color);
    }
}

HexTile* HexMap::getTile(unsigned int row, unsigned int col) {
    if (row >= m_rows || col >= m_cols) return nullptr;
    return &m_tiles[row * m_cols + col];
}

void HexMap::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& tile : m_tiles) {
        target.draw(tile.shape, states);
    }
}