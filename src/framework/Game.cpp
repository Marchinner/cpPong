#include "cpPong/framework/Game.h"
#include "cpPong/framework/Window.h"
#include "cpPong/entities/Player.h"
#include "cpPong/entities/Ball.h"
#include <SFML/Graphics.hpp>
#include <iostream>

const sf::Time Game::TimePerFrame{ sf::seconds(1.f / 60.f) };

Game::Game()
	: m_window{ new Window(820, 620, "C++ Pong Game Clone") }
	, m_player{ new Player(sf::Vector2f(30.f, 275.f)) }
	, m_ball{ new Ball() }
	, m_score{ 0 }
	, m_background{ new sf::RectangleShape(sf::Vector2f(800.f, 600.f)) }
{
	m_background->setFillColor(sf::Color::Transparent);
	m_background->setOutlineColor(sf::Color::Red);
	m_background->setOutlineThickness(2.f);
	m_background->setPosition(sf::Vector2f(10.f, 10.f));
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
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window->get_window()->close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_player->set_is_moving_up(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_player->set_is_moving_down(true);
		}
		else
		{
			m_player->set_is_moving_up(false);
			m_player->set_is_moving_down(false);
		}
	}
}

void Game::update(sf::Time deltaTime)
{
	m_player->update(deltaTime);
	m_ball->update();
	check_score();
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
	m_window->get_window()->draw(m_ball->get_ball());
	m_window->get_window()->draw(*m_background);
}

void Game::check_score()
{
	if (m_ball->get_ball().getPosition().x - m_ball->get_ball().getRadius() <= 0 || m_ball->get_ball().getPosition().x + m_ball->get_ball().getRadius() >= 800.f)
	{
		m_ball->revert_x_speed();
		m_score--;
	}
	if (m_ball->get_ball().getPosition().y - m_ball->get_ball().getRadius() <= 0 || m_ball->get_ball().getPosition().y + m_ball->get_ball().getRadius() >= 600.f)
	{
		m_ball->revert_y_speed();
	}

	if ((m_ball->get_ball().getPosition().y >= m_player->get_player().getPosition().y) && (m_ball->get_ball().getPosition().y <= m_player->get_player().getPosition().y + m_player->get_player().getSize().y))
	{
		if (m_ball->get_ball().getPosition().x <= m_player->get_player().getPosition().x + m_player->get_player().getSize().x)
		{
			m_ball->revert_x_speed();
			std::cout << "HIT" << std::endl;
			m_score++;
		}
	}
}
