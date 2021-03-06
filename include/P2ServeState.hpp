#ifndef __P2SERVESTATE_HPP__
#define __P2SERVESTATE_HPP__

#include <list>

#include "ServeState.hpp"
#include "GameEngine.hpp"
#include "Block.hpp"
///Serve state after player2 loses life - reuses ServeState
class P2ServeState : public ServeState
{
private:
public:
    void init(GameEngine *game);
    void cleanup(GameEngine *game);

    void pause();
    void resume();

    void handleEvents(GameEngine *, sf::Event);
    void update(GameEngine *);
    void render(GameEngine *);

    static P2ServeState *instance()
    {
        static P2ServeState P2ServeStateInstance;
        return &P2ServeStateInstance;
    }

    bool isTransparent(){ return true; }

protected:
    P2ServeState() {}
};

#endif // __P2SERVESTATE_HPP__