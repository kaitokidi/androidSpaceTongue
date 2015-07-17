#ifndef SCENE_H
#define SCENE_H
#include "Goal.hpp"
#include "Game.hpp"
#include "Player.hpp"
#include "Chameleon.hpp"
#include "IngameMenu.hpp"
#include "readlevels.hpp"
#include "Background.hpp"
#include "Obstacle.hpp"

class Scene : public Game {
public:

    sf::SoundBuffer buffer;
    
Scene(sf::RenderWindow* w, Level lvl)
    : Game(w),
      background(*w),
      iMenu(sf::Vector2f(w->getSize().x/2,w->getSize().y/2))
{
    buffer.loadFromFile("res/Cobra2.ogg");
    sound.setBuffer(buffer);

    finishLvl = false;
    success = false;
    menuIsActive = false;

    goal.setPosition(lvl.final);

    player.setSpeed(lvl.velocidad);
    player.setPosition(lvl.inicio);

    currentChameleon = nullptr;

    chameleons = std::vector<Chameleon>();
    for (uint i = 0; i < lvl.camaleon.size(); ++i) chameleons.push_back(Chameleon(lvl.camaleon[i],lvl.tipocamaleon[i]));
    obstacles = std::vector<Obstacle>();
    for (uint i = 0; i < lvl.obstaculo.size(); ++i) obstacles.push_back(Obstacle(lvl.obstaculo[i]));

}

~Scene() {}

bool update(float deltaTime){
    background.update(deltaTime);
    if (menuIsActive) return false;
    if (!player.isAlive()) {
        timeFromDeath += deltaTime;
        if (timeFromDeath > 0.5) {
            finishLvl = true;
            success = false;
        }
    }
    player.update(deltaTime);
    for (Chameleon &c : chameleons) c.update(deltaTime, player.getPosition());
    goal.update(deltaTime,player.getPosition());

    lookCollisions();

    float offset = 50;
    std::vector<sf::Vector2f> positions;
    positions.push_back(goal.getPosition());
    for(Chameleon &c : chameleons) positions.push_back(c.getPosition());
    float maxX, minX, maxY, minY;
    maxX = player.getPosition().x+offset;
    minX = player.getPosition().x-offset;
    maxY = player.getPosition().y+offset;
    minY = player.getPosition().y-offset;
    for(uint i = 0; i < positions.size(); ++i){
        //maxX = max(maxX, positions[i].x + offset);
        if(positions[i].x+offset > maxX) maxX = positions[i].x+offset;
        if(positions[i].x-offset < minX) minX = positions[i].x-offset;
        if(positions[i].y+offset > maxY) maxY = positions[i].y+offset;
        if(positions[i].y-offset < minY) minY = positions[i].y-offset;
    }

    float escalatX, escalatY;
    escalatX = window->getSize().x/(maxX-minX);
    escalatY = window->getSize().y/(maxY-minY);
    viewScale = std::min(escalatX, escalatY);
    view.setCenter((maxX+minX)/2, (maxY+minY)/2);
    view.setSize(window->getSize().x/viewScale, window->getSize().y/viewScale);

    return finishLvl;

}

void draw(){
    window->setView(view);
    background.draw(*window);
    goal.draw(*window);
    player.draw(*window);
    for (Chameleon &c : chameleons) c.draw(*window);
    for (Obstacle &o : obstacles) o.draw(*window);
    window->setView(window->getDefaultView());
    if (menuIsActive) iMenu.draw(*window);

}

void processEvents(){
    sf::Event event;
    while (window->pollEvent(event)) {
        if (menuIsActive) iMenu.handleEvent(event);
        switch (event.type) {
            case sf::Event::Closed:
                window->close();
                exit(0);
                break;
            case  sf::Event::KeyPressed:
                //Close key
                if (event.key.code == sf::Keyboard::Escape) {
                    menuIsActive = !menuIsActive;
                }
                else if (event.key.code == sf::Keyboard::R) { // Restart de lvl
                  finishLvl = true;
                  success = false;
                }
                break;
            default:
                break;
        }
    }
    if (menuIsActive) {
        if (iMenu.wantToResume()) menuIsActive = false;
        else if (iMenu.wantToMenu()) goToMenu = true;
    }
    else {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            sf::Vector2f mouse;
            mouse.x = view.getCenter().x + (sf::Mouse::getPosition(*window).x - window->getSize().x/2.0) / viewScale;
            mouse.y = view.getCenter().y + (sf::Mouse::getPosition(*window).y - window->getSize().y/2.0) / viewScale;

            activeChameleon(sf::Vector2f( mouse.x, mouse.y));
        }
        if (sf::Touch::isDown(0)) {
           
            sf::Vector2f mouse;
            mouse.x = view.getCenter().x + (sf::Touch::getPosition(0,*window).x - window->getSize().x/2.0) / viewScale;
            mouse.y = view.getCenter().y + (sf::Touch::getPosition(0,*window).y - window->getSize().y/2.0) / viewScale;

            activeChameleon(sf::Vector2f( mouse.x, mouse.y));
        }
        else releaseChameleon();
    }
}

bool getSuccess() const {
    return success;
}

void releaseChameleon() {
    if (currentChameleon == nullptr) return;

    currentChameleon->release();
    currentChameleon = nullptr;
    player.setLicked(false,sf::Vector2f(0,0),0);
}

void activeChameleon(sf::Vector2f pos) {
    
    if (currentChameleon != nullptr) return;
    long long int min = 99999999999999999;
    for (Chameleon &c : chameleons) {
        float module = getModule(pos,c.getPosition());
        if (module < 4*c.getRadius()) {
            if(module < min){
                min = module;
                currentChameleon = &c;
            }
         }
    }
    if(currentChameleon != nullptr){
        sound.play();
        sound.setVolume(100);
    }
    if (currentChameleon == nullptr) return;

    currentChameleon->lick();
    player.setLicked(true,currentChameleon->getPosition(),currentChameleon->getType());
}

void lookCollisions() {
    sf::CircleShape playerBounds = player.getBox();
    for (Chameleon& c : chameleons) {
        if (isCollisioning(playerBounds.getPosition(),playerBounds.getRadius(),c.getPosition(),c.getRadius())) {
            //WOPS HA CHOCADO. DO THINGS
            if (player.isAlive()) {
                player.setAlive(false);
                timeFromDeath = 0;
                c.eating();
                return;
            }
        }
    }
    for (Obstacle& o : obstacles) {
      if (isCollisioning(playerBounds.getPosition(),playerBounds.getRadius(),o.getPosition(),o.getRadius())) {
          //WOPS HA CHOCADO. DO THINGS
          if (player.isAlive()) {
              player.setAlive(false);
              timeFromDeath = 0;
              //c.eating();
              return;
          }
      }
    }
    if (isCollisioning(playerBounds.getPosition(),playerBounds.getRadius(),goal.getPosition(),goal.getSize()/2)) {
        finishLvl = true;
        success = true;
    }
}




private:

    Goal goal;
    sf::View view;
    Player player;
    sf::Sound sound;
    Background background;
    Chameleon *currentChameleon;
    std::vector<Obstacle> obstacles;
    std::vector<Chameleon> chameleons;

    // lvl aids
    float timeFromDeath;
    bool finishLvl; // Said if the level has finish (restart or go to the next lvl, menu, etc);
    bool success; // if you have pass the lvl or not
    IngameMenu iMenu;
    bool menuIsActive;
    float viewScale;


};

#endif // SCENE_H
