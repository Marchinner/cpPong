#include "cpPong/entities/Entity.h"


Entity::Entity(const sf::Vector2f &position)
	: m_position{ position }
	, m_velocity{ sf::Vector2f(0.f, 0.f)}
{

}

Entity::Entity(float x_position, float y_position)
	: m_position{sf::Vector2f(x_position, y_position)}
	, m_velocity{sf::Vector2f(0.f, 0.f)}
{
}
