#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cassert>

static const float PI = 3.14159265359f;

/// <summary>
/// Return dot product between a and b
/// </summary>
inline float DotProduct(const sf::Vector2f& vector1, const sf::Vector2f& vector2)
{
    return (vector1.x * vector2.x) + (vector1.y * vector2.y);
}

/// <summary>
/// Return the length of a vector 2D
/// </summary>
inline float Length(const sf::Vector2f& vector2D)
{
    return std::sqrt(DotProduct(vector2D, vector2D));
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
    return vector2D / Length(vector2D);
}


/// <summary>
/// Return a unnormalized vector perpendicular to the direction
/// </summary>
inline sf::Vector2f Perpendicular(const sf::Vector2f& dir)
{
    sf::Vector2f perp = sf::Vector2f(dir.y, -dir.x);
    return perp;
}

inline float RadianToDegree(float radian)
{
    return radian * 180.0f / PI;
}
/// <summary>
// Return the oriented angle in degree between 2 segment
// Positive mean shortest angle is left side
// negative mean shortest angle is right side
/// </summary>
inline float GetAngleBetweenVector(const sf::Vector2f& vector1, const  sf::Vector2f& vector2)
{
    sf::Vector2f currentSegment = Normalized(vector1);
    sf::Vector2f nextSegment = Normalized(vector2);

    sf::Vector2f perpendicularCurrentSegment = Perpendicular(currentSegment);

    float dot = DotProduct(currentSegment, nextSegment);
    dot = fmaxf(dot, -1.0f);
    dot = fminf(dot, 1.0f);

    float sign = DotProduct(perpendicularCurrentSegment, nextSegment) >= 0.0f ? 1.0f : -1.0f;

    return sign * (RadianToDegree(acosf(dot)) + 180);
}

/// <summary>
/// Return a random int between min and max
/// </summary>
inline int getRandomInt (int min, int max) {
    return rand() % (max - min + 1) + min;
}
inline sf::Vector2f GetPositionMiddleRight(sf::Sprite childSprite, sf::Sprite parentSprite) {
	return { parentSprite.getPosition().x + parentSprite.getGlobalBounds().width, parentSprite.getPosition().y + parentSprite.getGlobalBounds().height / 2.f - childSprite.getGlobalBounds().height / 2.f };
}



/// <summary>
/// Return a direction from Vector2f1 to Vector2f2
/// </summary>
inline sf::Vector2f GetDirection(const sf::Vector2f& vecteur1, const sf::Vector2f& vecteur2)
{
    return vecteur2 - vecteur1;
}

/// <summary>
/// Return a bool if 2 vector are at the same position in a float offset
/// </summary>
inline bool VectorIsEqual(const sf::Vector2f& vecteur1, const sf::Vector2f& vecteur2, float offset)
{
    const sf::Vector2f direction = GetDirection(vecteur1, vecteur2);

    return std::abs(direction.x) < offset && std::abs(direction.y) < offset;
}
