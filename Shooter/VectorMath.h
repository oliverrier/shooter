#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>


/// <summary>
/// Return the length of a vector 2D
/// </summary>
inline float Length(const sf::Vector2f& vector2D)
{
    return sqrtf( (vector2D.x * vector2D.x) + (vector2D.y * vector2D.y) );
}

/// <summary>
/// Return a copy normalized
/// If this vector is too small to be normalized, a copy of the initial vector will be returned
/// </summary>
inline sf::Vector2f Normalize(const sf::Vector2f& vector2D)
{
    const float norm = sqrtf(powf(vector2D.x, 2) + powf(vector2D.y, 2));

    return norm > 0 ? *new sf::Vector2f(vector2D.x / norm, vector2D.y / norm ) : *new sf::Vector2f(vector2D.x, vector2D.y);
}
