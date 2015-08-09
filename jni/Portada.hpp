#ifndef PORTADA_H
#define PORTADA_H

#include "utils.hpp"

class Portada {

private:
    sf::Sprite s;
    sf::Texture t;
//    sf::Button b;
    bool open;

    int qttyAnimations;
    int actualAnimation;
    int width;
    int height;
    float animationWidth;
    float animationHeight;
    float timeBetweenAnimations;
    float timeSinceLastAnimation;

public:

Portada() {
    open = true;
}

~Portada(){}

void display(sf::RenderWindow* window, std::string pathImage, int qttyImagesX, int qttyImagesY, float time){
    open = true;
    if(! t.loadFromFile(pathImage)) { std::cout << "failed on load cover " << pathImage << std::endl;}
    
    s = sf::Sprite();
    s.setTexture(t, true);

    width = qttyImagesX;
    height = qttyImagesY;
    actualAnimation = 0;
    timeBetweenAnimations = time;
    timeSinceLastAnimation = -1.0;

    animationWidth = s.getGlobalBounds().width/width;
    animationHeight = s.getGlobalBounds().height/height;

    if(window->getSize().y/animationHeight < window->getSize().x/animationWidth)
        s.scale(window->getSize().y/animationHeight,window->getSize().y/animationHeight);
    else
        s.scale(window->getSize().x/animationWidth,window->getSize().x/animationWidth);

    s.setOrigin(sf::Vector2f(animationWidth/2, animationHeight/2));
    s.setPosition(window->getSize().x/2, window->getSize().y/2.0);

    sf::Clock c;

        while(open){
        float deltaTime = c.restart().asSeconds();
        sf::Event event;
        while (window->pollEvent(event)) {
            if( event.type == sf::Event::KeyPressed ||
                event.type == sf::Event::MouseButtonPressed||
                event.type == sf::Event::TouchEnded           )  open = false;
        }

        if (actualAnimation+1 < width*height) timeSinceLastAnimation += deltaTime;
        if(timeSinceLastAnimation >= timeBetweenAnimations){
            if (actualAnimation  >= width*height) { /*donothing*/}
            else { 
                ++actualAnimation;
//                if (actualAnimation == 1) timeSinceLastAnimation = -0.5;
//                else timeSinceLastAnimation = 0.0;
                  timeSinceLastAnimation = 0.0;
            }
        }

        window->clear();
        if (actualAnimation  < width*height)
            s.setTextureRect(
                sf::IntRect(
                    (actualAnimation%width)*animationWidth, 
                    (actualAnimation/width)*animationHeight, 
                            animationWidth, animationHeight));
        window->draw(s);
        window->display();
    }
}

};

#endif // PORTADA_H
