#pragma once

#include <SFML/System/Vector2.hpp>

class Entity
{
public:
	Entity(const sf::Vector2f &position, const sf::Vector2f &velocity);
	Entity(float x_position, float y_position, float x_velocity, float y_velocity);
protected:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
};
