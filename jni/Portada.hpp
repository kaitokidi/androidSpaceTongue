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

void display(sf::RenderWindow* window){
    open = true;
    while(open){

        sf::Event event;
        while (window->pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    exit(0);
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) { window->close(); exit(0); }
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        open = false;
                    }
                default:
                    break;
            }
        }


        if(! t.loadFromFile("res/cover.png")) std::cout << "error on loading cover.png" << std::endl;
        s.setTexture(t);
        if(window->getSize().y/s.getGlobalBounds().height < window->getSize().x/s.getGlobalBounds().width)
            s.scale(window->getSize().y/s.getGlobalBounds().height,window->getSize().y/s.getGlobalBounds().height);
        else
            s.scale(window->getSize().x/s.getGlobalBounds().width,window->getSize().x/s.getGlobalBounds().width);
        s.setPosition(window->getSize().x/2 - s.getGlobalBounds().width/2, 0);
        window->draw(s);
        window->display();
    }
}

void display(sf::RenderWindow* window, std::string pathImage){
    open = true;
    if(! t.loadFromFile(pathImage)) std::cout << "failed on load cover " << pathImage << std::endl;
    s = sf::Sprite();
    s.setTexture(t);

    width = 5;
    height = 2;
    actualAnimation = 0;
    timeBetweenAnimations = 0.25;
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

        timeSinceLastAnimation += deltaTime;
        if(timeSinceLastAnimation >= timeBetweenAnimations){
            if (actualAnimation+2  >= width*height) timeSinceLastAnimation = -2;
            else if (actualAnimation+1  >= width*height) { /*donothing*/}
            else { 
                actualAnimation = (actualAnimation + 1);
                if (actualAnimation == 1) timeSinceLastAnimation = -0.5;
                else timeSinceLastAnimation = 0.0;
            }
        }



        window->clear();
        if (actualAnimation+2  < width*height)
            s.setTextureRect(sf::IntRect((actualAnimation%width)*animationWidth, (actualAnimation/width)*animationHeight, animationWidth, animationHeight));
        window->draw(s);
        window->display();
    }

}



};

#endif // PORTADA_H
