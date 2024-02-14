#pragma once

#include "cpPong/entities/Entity.h"

namespace sf
{
	class CircleShape;
	class Time;
}

class Player;

class Ball : public Entity
{
public:
	Ball();

	void update(const sf::Time deltaTime);
	const sf::CircleShape& get_ball();
	void revert_direction();

private:
	sf::CircleShape* m_ball;
	float m_x_speed;
	float m_y_speed;
};
