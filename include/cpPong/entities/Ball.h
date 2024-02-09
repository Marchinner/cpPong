#pragma once

#include "cpPong/entities/Entity.h"

namespace sf
{
	class CircleShape;
	class Time;
}

class Ball : public Entity
{
public:
	Ball();

	void update(const sf::Time deltaTime);
	const sf::CircleShape& get_ball();
private:
	sf::CircleShape* m_ball;
	float m_speed;
};
