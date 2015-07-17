#ifndef GAME_H
#define GAME_H

#include "utils.hpp"

class Game {
public:

    virtual bool update(float deltaTime) = 0;
    virtual void draw() = 0;
    virtual void processEvents() = 0;
    
    Game(sf::RenderWindow *w) {
    window = w;
    goToMenu = false;
}

virtual ~Game() {}

bool run() {
    sf::Clock c;
    srand(time(0));
    while(window->isOpen()) {
        float deltaTime = c.restart().asSeconds();
        processEvents();
        if (goToMenu) return false;
        if (update(deltaTime)) return true;
        render();
    }
    return false;
}


protected:
    sf::RenderWindow *window;
    bool goToMenu;
private:
    void render() {
    window->clear();
    draw();
    window->display();
}

};

#endif // GAME_H
