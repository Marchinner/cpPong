#include <SFML/Graphics/RenderWindow.hpp>
#include "../../include/cpPong/framework/Window.h"

Window::Window(int width, int height, const std::string& title)
	: m_window{new sf::RenderWindow(sf::VideoMode(width, height), title)}
{

}

Window::~Window()
{
	delete m_window;
}

sf::RenderWindow* Window::get_window()
{
	return m_window;
}
