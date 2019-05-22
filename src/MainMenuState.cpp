#include <iostream>

#include "../include/MainMenuState.hpp"
#include "../include/PlayState.hpp"

void MainMenuState::init()
{
    std::cout << "MainMenuState::init()" << std::endl;
}

void MainMenuState::cleanup(GameEngine *game)
{
    
}

void MainMenuState::pause()
{
}

void MainMenuState::resume()
{
}

void MainMenuState::handleEvents(GameEngine *game)
{

    std::cout << "MainMenuState::handleEvents()" << std::endl;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        game->changeState(PlayState::instance());
    }
}

void MainMenuState::update(GameEngine *game)
{
    std::cout << "MainMenuState::update()" << std::endl;
}

void MainMenuState::render(GameEngine *game)
{
    std::cout << "MainMenuState::render()" << std::endl;
    sf::Font font;
    game->window.clear();
    if (!font.loadFromFile("resources/pixel.ttf"))
    {
        std::cout << "ERORR loading font" << std::endl;
        return;
    }
    sf::Text t("TEST", font, 40);
    t.setPosition(100, 100);
    t.setFillColor(sf::Color::Yellow);
    t.setOutlineColor(sf::Color::Blue);
    t.setOutlineThickness(5);


    game->window.draw(t);
    game->window.display();
}
