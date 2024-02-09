#pragma once

#include <SFML/System/Vector2.hpp>

class Entity
{
public:
	Entity(const sf::Vector2f &position);
	Entity(float x_position, float y_position);
protected:
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
};
