#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <list>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Ball.hpp"
#include "ResourceMenager.hpp"
#include "Block.hpp"

class GameState;

class GameEngine
{
public:
	GameEngine(int virtualWidth, int virtualHeight, int width, int height,  std::string title, std::string iconPath, int frameLimit, bool vsync);
	~GameEngine() { std::cout << "GameEngine destructor" << std::endl; };

	void changeState(GameState *state);
	void pushState(GameState *state);
	void popState();

	void handleEvents();
	void update();
	void render();

	inline bool running() { return m_running; }
	inline void quit() { m_running = false; }

	sf::RenderWindow window;
	const sf::Vector2u& getVirtualSize() const { return virtualSize; };

	Player p1, p2;
	Ball ball;
	ResourceMenager<sf::Texture> textureMenager;
	ResourceMenager<sf::Font> fontMenager;
	
	std::list<Block> blocks;
	void resetClock() { Clock.restart(); }
	void setElapsedTime() { elapsedTime = Clock.getElapsedTime().asMilliseconds(); }
	const uint getElapsedTime() const { return elapsedTime; }
	float getScreenRatio() const { return screenRatio; };

private:
	sf::Clock Clock;
	uint elapsedTime;
	std::vector<GameState *> states;
	sf::Vector2u virtualSize;
	float screenRatio;

	bool m_running;
	bool m_fullscreen;
};

#endif