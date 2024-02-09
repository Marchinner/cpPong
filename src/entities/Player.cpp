#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include "cpPong/entities/Player.h"

Player::Player(const sf::Vector2f& position)
	: Entity{ position }
	, m_player{ new sf::RectangleShape(sf::Vector2f(10.f, 50.f)) }
	, is_moving_up{ false }
	, is_moving_down{ false }
{
	m_player->setPosition(position);
	m_player->setFillColor(sf::Color::Red);
}

Player::Player(float x_position, float y_position)
	: Entity{ x_position, y_position}
	, m_player{ new sf::RectangleShape(sf::Vector2f(10.f, 50.f)) }
	, is_moving_up{ false }
	, is_moving_down{ false }
{
}

const sf::RectangleShape& Player::get_player()
{
	return *m_player;
}

void Player::update(const sf::Time& deltaTime)
{
	if (is_moving_up)
	{
		m_player->setPosition(m_player->getPosition().x, m_player->getPosition().y - 15.f);
	}
	if (is_moving_down)
	{
		m_player->setPosition(m_player->getPosition().x, m_player->getPosition().y + 15.f);
	}
}

void Player::set_is_moving_up(bool value)
{
	is_moving_up = value;
}

void Player::set_is_moving_down(bool value)
{
	is_moving_down = value;
}
