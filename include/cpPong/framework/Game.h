#pragma once

class Window;
class Player;
class Ball;

namespace sf
{
	class Time;
	class RectangleShape;
}

class Game
{
public:
	Game();
	~Game();
	void start();
	
private:
	void process_events();
	void update(sf::Time deltaTime);
	void render();
	void render_internal();
private:
	Window* m_window;
	Player* m_player;
	Ball* m_ball;
	sf::RectangleShape* m_background;
	static const sf::Time TimePerFrame;
};
