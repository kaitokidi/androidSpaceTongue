#ifndef GOAL_HPP
#define GOAL_HPP
#include "utils.hpp"
#include "Resources.hpp"

class Goal {


public:
    
sf::Texture goal;

Goal(){
    qttyAnimations = 1; //set here the qtty
    actualAnimation = 0;
    reached = false;
    timeBetweenAnimations = 0.2;
    timeSinceLastAnimaiton = 0.0;

    size = 100;

    
    goal.loadFromFile("res/End_02.png");
    sprite.setTexture(goal);
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    animationSize = sprite.getGlobalBounds().width/qttyAnimations;
    sprite.setScale(size/sprite.getLocalBounds().width, size/sprite.getLocalBounds().height);

}

void update(float deltatime, sf::Vector2f playerPos) {
    timeSinceLastAnimaiton += deltatime;
    if(timeSinceLastAnimaiton >= timeBetweenAnimations){
        actualAnimation = (actualAnimation + 1) % qttyAnimations;
        timeSinceLastAnimaiton = 0.0;
    }
    sprite.setRotation(getAngle(sprite.getPosition(),playerPos)+180);
}

void draw(sf::RenderWindow& window) {
    sprite.setPosition(position);
    window.draw(sprite);
}

sf::Vector2f getPosition() const {
    return position;
}

float getSize() const {
    return size;
}

void setPosition(const sf::Vector2f &value) {
    position = value;
}

void setPosition(float valueX, float valueY){
    setPosition(sf::Vector2f(valueX, valueY));
}



private:
    float size;
    bool  reached;

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;

    int qttyAnimations;
    int actualAnimation;
    float animationSize;
    float timeBetweenAnimations;
    float timeSinceLastAnimaiton;


};

#endif // GOAL_HPP
