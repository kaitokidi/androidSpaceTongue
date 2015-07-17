#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include "utils.hpp"

class Background {
public:
    
sf::Texture background;

Background(sf::RenderWindow &window) {
    background.loadFromFile("res/fondo1_baja.jpg");
    sprite.setTexture(background);
    width = 1;
    height = 1;
    actualAnimation = 0;
    timeBetweenAnimations = 1;
    timeSinceLastAnimation = 0.0;

    animationWidth = sprite.getGlobalBounds().width/width;
    animationHeight = sprite.getGlobalBounds().height/height;

    if(window.getSize().y/animationHeight < window.getSize().x/animationWidth)
        sprite.scale(2*window.getSize().y/animationHeight,2*window.getSize().y/animationHeight);
    else
        sprite.scale(2*window.getSize().x/animationWidth,2*window.getSize().x/animationWidth);

    //sprite.setOrigin(sf::Vector2f(animationWidth/2, animationHeight/2));
    sprite.setPosition(window.getSize().x/2, window.getSize().y/2.0);

}

void update(float deltaTime) {
    timeSinceLastAnimation += deltaTime;
    if(timeSinceLastAnimation >= timeBetweenAnimations){
        actualAnimation = (actualAnimation + 1)%width;
        timeSinceLastAnimation = 0.0;
    }
}

void draw(sf::RenderWindow &window) {
    int posx = - (window.getView().getSize().x/2 - window.getView().getCenter().x);
    int posy = - (window.getView().getSize().y/2 - window.getView().getCenter().y);

    int offsetx = sprite.getGlobalBounds().width - (-1*posx)%(int)sprite.getGlobalBounds().width;
    int offsety = sprite.getGlobalBounds().height - (-1*posy)%(int)sprite.getGlobalBounds().height;

    posx -= offsetx;
    posy -= offsety;
    int aux = posy;
    sprite.setTextureRect(sf::IntRect((actualAnimation%width)*animationWidth,
                                      (actualAnimation/width)*animationHeight,
                                      animationWidth, animationHeight));

    while(posx < window.getView().getSize().x){

        while(posy < window.getView().getSize().y){

            sprite.setPosition(posx,posy);
            window.draw(sprite);

            posy += sprite.getGlobalBounds().height;
        }

        posx += sprite.getGlobalBounds().width;
        posy = aux;
    }
}

private:
    sf::Sprite sprite;

    int qttyAnimations;
    int actualAnimation;
    int width;
    int height;
    float animationWidth;
    float animationHeight;
    float timeBetweenAnimations;
    float timeSinceLastAnimation;
};

#endif // BACKGROUND_HPP
