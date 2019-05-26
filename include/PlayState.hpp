#ifndef PLAYSTATE_H
#define PLAYSTATE_H

#include <list>

#include "GameState.hpp"
#include "GameEngine.hpp"
#include "Block.hpp"

class PlayState : public GameState {
    private:
        std::list <Block> blocks;
    public:
        void init(GameEngine *game);
        void cleanup(GameEngine *game);

        void pause();
        void resume();

        void handleEvents(GameEngine*);
        void update(GameEngine*);
        void render(GameEngine*);

        static PlayState* instance(){
            static PlayState PlayStateInstance;
            return &PlayStateInstance;
        }
    
    protected:
        PlayState(){}

};












#endif