#ifndef CHAMELEON_HPP
#define CHAMELEON_HPP

#include "utils.hpp"
#include "Tongue.hpp"

class Chameleon {
public:

    sf::Texture chameleon;
    sf::Texture chameleon2;
    sf::Texture chameleon3;
    
    
Chameleon() {
}

Chameleon(sf::Vector2f pos, int tipoFuerza)
  :
    tipoFuerza(tipoFuerza)
{
    chameleon.loadFromFile("res/chameleon.png");
    chameleon2.loadFromFile("res/chameleon2.png");
    chameleon3.loadFromFile("res/Eating.png");
    
    radius = 30; // Elegir el radio segund algo(?)
    isEating = false;
    licking = false;
    sprite.setRadius(radius);
    sprite.setTexture(&chameleon);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    sprite.setPosition(pos);

    tongue.setOrig(pos);
    tongue.setFatherRadius(radius);


    if (tipoFuerza == 1) sprite.setFillColor(sf::Color::Red);


    //std::cout << "chamaleon" << std::endl;
}

void update(float deltaTime, sf::Vector2f playerPos) {
    sprite.setTexture(&chameleon);
    if (licking) {
        sprite.setTexture(&chameleon2);
        tongue.setDest(playerPos);
        tongue.update(deltaTime);
    }
    if(isEating) sprite.setTexture(&chameleon3);
    sprite.setRotation(getAngle(sprite.getPosition(),playerPos)+90);
}

void draw(sf::RenderWindow& window) {
    sprite.getTexture();
    window.draw(sprite);
    if (licking) tongue.draw(window);
}

void lick() {
    if (!licking) {
        sprite.setTexture(&chameleon2);
        licking = true;
        tongue.reset();
    }
}

void release() {
    if (licking) {
        sprite.setTexture(&chameleon);
        licking = false;
    }
}

void eating() {
  isEating = true;
  sprite.setTexture(&chameleon3);
}

void setPosition(sf::Vector2f pos) {
  sprite.setPosition(pos);
}

sf::Vector2f getPosition() {
    return sprite.getPosition();
}

float getRadius() {
  return radius;
}

int getType() {
  return tipoFuerza;
}




private:
    sf::CircleShape sprite;
    Tongue tongue;
    float angle;
    bool licking;
    bool isEating;
    float radius;
    int tipoFuerza;
};

#endif // CHAMELEON_HPP
