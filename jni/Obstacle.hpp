#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include "utils.hpp"


class Obstacle {
public:

sf::Texture obstacle;
    
    
Obstacle(){}

Obstacle(sf::Vector2f pos) {
  radius = 30;
  sprite.setRadius(radius);
  obstacle.loadFromFile("res/piedra.png");
  sprite.setTexture(&obstacle);
  sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
  sprite.setPosition(pos);
  sprite.setRotation(rand()%360);


  nSprites = 1; // Numero de Sprites
  angle = 0; // Angulo de rotacion
  spriteTimer = 0;
  spriteWidth = sprite.getLocalBounds().width;
  spriteHeight = sprite.getLocalBounds().height;
  timeSinceNextSprite = 100000;
  spriteAnimation = 0;
}

void update(float deltaTime) {
  sprite.setTexture(&obstacle);
  spriteTimer += deltaTime;
  if(spriteTimer >= timeSinceNextSprite){
      ++spriteAnimation;
      spriteAnimation = (int)spriteAnimation % nSprites;
      sprite.setTextureRect(sf::IntRect(spriteAnimation*spriteWidth, 0, spriteWidth, spriteHeight));
  }
}

void draw(sf::RenderWindow &window) {
      sprite.setTexture(&obstacle);
        if(spriteTimer >= timeSinceNextSprite){
      ++spriteAnimation;
      spriteAnimation = (int)spriteAnimation % nSprites;
      sprite.setTextureRect(sf::IntRect(spriteAnimation*spriteWidth, 0, spriteWidth, spriteHeight));
  }
  window.draw(sprite);
}

float getRadius() {
  return radius;
}

sf::Vector2f getPosition() {
  return sprite.getPosition();
}

void setPosition(sf::Vector2f pos) {
  sprite.setPosition(pos);
}


private:
  sf::CircleShape sprite;
  float radius;

  float angle;
  int nSprites;
  float spriteTimer;
  float spriteWidth;
  float spriteHeight;
  float spriteAnimation;
  float timeSinceNextSprite;
};

#endif // OBSTACLE_HPP
