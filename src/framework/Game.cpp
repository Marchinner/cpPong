#include "cpPong/framework/Game.h"
#include "cpPong/framework/Window.h"
#include "cpPong/entities/Player.h"
#include <SFML/Graphics.hpp>

const sf::Time Game::TimePerFrame{ sf::seconds(1.f / 60.f) };

Game::Game()
	: m_window{ new Window(800, 600, "C++ Pong Game Clone")}
	, m_player{ new Player(sf::Vector2f(350.f, 300.f), sf::Vector2f(0.f,0.f))}
{

}

Game::~Game()
{
	delete m_player;
	delete m_window;
}

void Game::start()
{
	sf::Clock clock;
	sf::Time deltaTime = sf::Time::Zero;
	while (m_window->get_window()->isOpen())
	{
		process_events();
		deltaTime += clock.restart();
		while (deltaTime > TimePerFrame)
		{
			deltaTime -= TimePerFrame;
			process_events();
			update(deltaTime);
		}
		render();
	}
}

void Game::process_events()
{
	sf::Event event;
	while (m_window->get_window()->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window->get_window()->close();
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	
}

void Game::render()
{
	m_window->get_window()->clear();
	render_internal();
	m_window->get_window()->display();
}

void Game::render_internal()
{
	m_window->get_window()->draw(m_player->get_player());
}
