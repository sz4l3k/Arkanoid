#include <iostream>
#include <memory>
#include <algorithm>

#include "../include/BaseMenuState.hpp"
#include "../include/PlayState.hpp"

#include "../include/Buttons.hpp"


void BaseMenuState::cleanup(GameEngine *game)
{
    buttons.clear();
    objects.clear();
}

void BaseMenuState::pause()
{
}

void BaseMenuState::resume()
{
}

void BaseMenuState::handleEvents(GameEngine *game, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            for(auto button : buttons){
                if(button->isHovered(sf::Vector2f(sf::Mouse::getPosition(game->window)) * game->getScreenRatio())){
                    if(button->click(game))
                        return;
                }
            }
        }
    }
    else if(event.type == sf::Event::MouseMoved){
        for(auto button : buttons){
            if(button->isActive()){
                if(button->isHovered(sf::Vector2f(sf::Mouse::getPosition(game->window)) * game->getScreenRatio())){
                    button->hover();
                }
                else
                {
                    button->reset();
                }
            }
            
        }
    }

}

void BaseMenuState::update(GameEngine *game)
{
}

void BaseMenuState::render(GameEngine *game)
{
    for(auto button : buttons)
        button.get()->draw(game);
    
    for(auto object : objects)
        game->window.draw(*object);

}
