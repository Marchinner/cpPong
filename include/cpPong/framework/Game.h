#pragma once

class Window;
class Player;

namespace sf
{
	class Time;
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
	static const sf::Time TimePerFrame;
};
