#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Time.hpp>
#include "cpPong/entities/Ball.h"
#include <iostream>

Ball::Ball()
	: Entity{ 395.f, 295.f }	// center of screen
	, m_ball{new sf::CircleShape(10.f)}
	, m_speed{5.f}
{
	m_ball->setPosition(m_position);
}

const sf::CircleShape& Ball::get_ball()
{
	return *m_ball;
}

void Ball::update(const sf::Time deltaTime)
{
	
	std::cout << "X: " << m_ball->getPosition().x << "\tY: " << m_ball->getPosition().y << std::endl;
}