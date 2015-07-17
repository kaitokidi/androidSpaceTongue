#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "utils.hpp"

class Player {
public:

sf::SoundBuffer expbuf;
sf::Texture ship;
    
Player() :
    pos(sf::Vector2f(0,0)), speed(sf::Vector2f(0,0))
{
    expbuf.loadFromFile("res/explos.ogg");
    expl.setBuffer(expbuf);

    expl.setVolume(100);
    alive = true;
    spriteTimer = 0.0;
    spriteAnimation = 0.0;
    timeSinceNextSprite = 0.2;
    angle = speedToRad(speed);
    ship.loadFromFile("res/ship.png");
    sprite.setTexture(ship);
    spriteHeight = ship.getSize().y;
    spriteWidth = ship.getSize().x/15;
    sprite.setTextureRect(sf::IntRect(spriteAnimation*spriteWidth, 0, spriteWidth, spriteHeight));
    sprite.setOrigin(sprite.getGlobalBounds().width/2,sprite.getGlobalBounds().height/2);
    licked = tensioning = false;
    tipofuerza = 0;
}

void setPosition(sf::Vector2f newPos){
    pos = newPos;
    sprite.setPosition(pos);
}

void setSpeed(sf::Vector2f newSpeed){
    speed = newSpeed;
}

void update(float deltaTime) {
    if (!alive) return;
    if (licked) timeSinceTriggered += deltaTime;
    if (tipofuerza==0)
      evoluciona(deltaTime);
    else
      evolucionabis(deltaTime);
    angle = radToAngle(speedToRad(speed))+90;
    sprite.setPosition(pos);
    spriteTimer += deltaTime;
    if(spriteTimer >= timeSinceNextSprite){
        ++spriteAnimation;
        spriteAnimation = (int)spriteAnimation % 15;
    }
}

void draw(sf::RenderWindow &window) {
    if (!alive) return;
    sprite.setTextureRect(sf::IntRect(spriteAnimation*spriteWidth, 0, spriteWidth, spriteHeight));
    sprite.setRotation(angle);sprite.setScale(sf::Vector2f(scalePlayer,scalePlayer));
    window.draw(sprite);
}


sf::Vector2f getPosition() {
    return pos;
}

void setLicked(bool b, sf::Vector2f cPos, int tipofuerza) {
  this->tipofuerza = tipofuerza;
    camaleonPos = cPos;
    licked = b;
    if (!b) {
        tensioning = false;
        timeSinceTriggered = 0;
    }
}

void setAlive(bool b) {
    if (!b && alive) {
    alive = b;
    expl.play();
    }
}


bool isAlive() {
  return alive;
}

sf::Vector2f getSpeed() {
  return speed;
}


sf::CircleShape getBox() {
    sf::CircleShape aux(spriteWidth/2*scalePlayer*0.5);
    aux.setPosition(pos);
    return aux;
}

//Private functions




private:
    //Player properties
    sf::Sound expl;
    sf::Vector2f pos;
    sf::Sprite sprite;
    sf::Vector2f speed;


    float angle;
    float spriteTimer;
    float spriteWidth;
    float spriteHeight;
    float spriteAnimation;
    float timeSinceNextSprite;
  int tipofuerza;
    // Camaleon related things
    bool licked;
    bool tensioning;
    float timeSinceTriggered;
    sf::Vector2f camaleonPos;


void evoluciona(float fdelta){
    double delta=fdelta;
    point p=vector2point(pos);
    point v=vector2point(speed);
  point c=vector2point(camaleonPos);
  if (not licked || timeSinceTriggered < animationTime) {
    p+=v*delta;
    pos=point2vector(p);
    return;
  }
  if (not tensioning) {
    p+=v*delta;
    pos=point2vector(p);
    if (prodesc(v,p-c)>=0)
      tensioning=true;
    return;
  }
  p-=c;
  double modulov=abs(v);
  double desp=modulov*delta;
  double r=abs(p);
  double alfa=desp/r;
  int signo=prodvec(p,v)>0?1:-1;
  p*=std::polar(1.0,signo*alfa);
  v=p*std::polar(1.0,signo*M_PI/2.0);
  v=(modulov/abs(v))*v;
  p+=c;
  pos=point2vector(p);
  speed=point2vector(v);
}

double fuerza(double distancia)
{
  if (tipofuerza==1)
    return sqrt(abs(distancia))*5;
  if (tipofuerza==2)
    return abs(distancia)/200;
  //return 30;
  //return 5000000/(distancia*distancia);
}

void evolucionabis(float fdelta)
{
  double delta=fdelta;
  point p=vector2point(pos);
  point v=vector2point(speed);
  if (not licked || timeSinceTriggered < animationTime) {
    p+=v*delta;
    pos=point2vector(p);
    return;
  }
  point c=vector2point(camaleonPos);
  int pasos=100;
  delta/=pasos;
  for (int paso=0;paso<pasos;paso++) {    
    point dir=c-p;
    v=v+(fuerza(abs(dir))*delta/abs(dir))*dir;
    p=p+v*delta;
  }
  pos=point2vector(p);
  speed=point2vector(v);
}


    // Comido
    bool alive;
};

#endif // PLAYER_HPP
