#pragma once

class Window;

class Game
{
public:
	Game();
	void start();
	
private:
	void process_events();
	void process_internal_events();
	void render();
	void render_internal();
private:
	Window* m_window;
};
