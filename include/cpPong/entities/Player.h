#pragma once

#include <cpPong/entities/Entity.h>

namespace sf
{
	class RectangleShape;
	class Time;
}

class Player : public Entity
{

public:
	Player(const sf::Vector2f& position, const sf::Vector2f& velocity);
	Player(float x_position, float y_position, float x_velocity, float y_velocity);

	sf::RectangleShape& get_player();
	void update(const sf::Time& deltaTime);

	void set_is_moving_up(bool value);
	void set_is_moving_down(bool value);
private:
	sf::RectangleShape* m_player;
	bool is_moving_up;
	bool is_moving_down;
};
