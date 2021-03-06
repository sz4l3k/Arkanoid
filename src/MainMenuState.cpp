#include "../include/MainMenuState.hpp"
#include "../include/SingleMenuState.hpp"
#include "../include/HotSeatMenuState.hpp"


void MainMenuState::init(GameEngine* game)
{
    std::cout << "MainMenuState::init()" << std::endl;
    font = game->fontMenager.get("pixel.ttf").get();
    const_cast<sf::Texture&>(font->getTexture(mediumFontSize)).setSmooth(false);

    std::shared_ptr<TextButton> newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color::Yellow, sf::Vector2f(0, 0), sf::Text("Single Player", *font, mediumFontSize), [](GameEngine* game, Button* button){game->changeState(SingleMenuState::instance()); return true;});
    newButton.get()->setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - newButton.get()->getGlobalBounds().width/2.0, 100));
    buttons.push_back(newButton);

    newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color::Yellow, sf::Vector2f(0, 0), sf::Text("HotSeat", *font, mediumFontSize), [](GameEngine* game, Button* button){game->changeState(HotSeatMenuState::instance()); return true;});
    newButton.get()->setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - newButton.get()->getGlobalBounds().width/2.0, 150));
    buttons.push_back(newButton);

    newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color::Yellow, sf::Vector2f(0, 0), sf::Text("Exit", *font, mediumFontSize), [](GameEngine* game, Button* button){game->quit(); return true;});
    newButton.get()->setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - newButton.get()->getGlobalBounds().width/2.0, 200));
    buttons.push_back(newButton);

}
