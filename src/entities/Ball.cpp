#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include "cpPong/entities/Ball.h"
#include <iostream>

Ball::Ball()
	: Entity{ 395.f, 295.f }	// center of screen
	, m_ball{new sf::CircleShape(10.f)}
	, m_x_speed{5.f}
	, m_y_speed{5.f}
{
	m_ball->setPosition(m_position);
}

const sf::CircleShape& Ball::get_ball()
{
	return *m_ball;
}

void Ball::update(const sf::Time deltaTime)
{
	m_ball->move(m_x_speed, m_y_speed);
	if (m_ball->getPosition().x - m_ball->getRadius() <= 0 || m_ball->getPosition().x + m_ball->getRadius() >= 800.f)
	{
		m_x_speed *= -1;
	}
	if (m_ball->getPosition().y - m_ball->getRadius() <= 0 || m_ball->getPosition().y + m_ball->getRadius() >= 600.f)
	{
		m_y_speed *= -1;
	}


	std::cout << "X: " << m_ball->getPosition().x << "\tY: " << m_ball->getPosition().y << std::endl;
}