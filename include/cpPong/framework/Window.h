#pragma once

#include <string>

namespace sf
{
	class RenderWindow;
}

class Window
{
public:
	Window(int witdh, int height, const std::string& title);
	~Window();
	sf::RenderWindow* get_window();
private:
	sf::RenderWindow* m_window;
};
