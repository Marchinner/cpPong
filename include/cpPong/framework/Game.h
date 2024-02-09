#pragma once

class Window;
class Player;

class Game
{
public:
	Game();
	~Game();
	void start();
	
private:
	void process_events();
	void process_internal_events();
	void render();
	void render_internal();
private:
	Window* m_window;
	Player* m_player;
};
