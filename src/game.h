#ifndef GAME_H_
#define GAME_H_

#include <memory>
#include <vector>
#include <stack>

#include <SFML/Graphics.hpp>

class GameState;

class Game {

    public:
        Game();
        void loop();
        std::stack<std::shared_ptr<GameState>> states;
        void pushState(std::shared_ptr<GameState> state);
        void popState();
        void changeState(std::shared_ptr<GameState> state);
        std::shared_ptr<GameState> peekState();
        sf::RenderWindow window;
    private:

};

#endif
