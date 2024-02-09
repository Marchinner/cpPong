#include "cpPong/entities/Entity.h"


Entity::Entity(const sf::Vector2f &position, const sf::Vector2f &velocity)
	: m_position{ position }
	, m_velocity{ velocity }
{

}

Entity::Entity(float x_position, float y_position, float x_velocity, float y_velocity)
	: m_position{sf::Vector2f(x_position, y_position)}
	, m_velocity{sf::Vector2f(x_velocity, y_velocity)}
{
}
