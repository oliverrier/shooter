#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cassert>


/// <summary>
/// Return the length of a vector 2D
/// </summary>
inline float Length(const sf::Vector2f& vector2D)
{
    return std::sqrt( (vector2D.x * vector2D.x) + (vector2D.y * vector2D.y) );
}

/// <summary>
/// Return a copy normalized
/// If this vector is too small to be normalized, a copy of the initial vector will be returned
/// </summary>
inline sf::Vector2f Normalized(const sf::Vector2f& vector2D)
{
    if (vector2D.x == 0.f && vector2D.y == 0.f) {
        return vector2D;
    }
    const float norm = std::sqrt((vector2D.x * vector2D.x) + (vector2D.y * vector2D.y));
    return vector2D / norm;
}

inline int getRandomInt (int min, int max) {
    return rand() % (max - min + 1) + min;
}