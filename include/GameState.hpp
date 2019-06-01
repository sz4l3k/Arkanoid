#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>

#include "GameEngine.hpp"

class GameState{
    public:
        virtual void init(GameEngine* game) = 0;
        virtual void cleanup(GameEngine* game) = 0;
        
        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void handleEvents(GameEngine*, sf::Event) = 0;
        virtual void update(GameEngine*) = 0;
        virtual void render(GameEngine*) = 0;

        virtual bool isTransparent(){ return false; }

        void changeState(GameEngine* game, GameState* state){
            game->changeState(state);
        }
    
    protected:
        GameState(){}

};


#endif