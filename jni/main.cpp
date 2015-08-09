#include "Menu.hpp"
#include "Scene.hpp"
#include "frases.hpp"
#include "Portada.hpp"
#include "readlevels.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cmath>


bool isWhite(sf::Image& image, float px, float py){
    return image.getPixel(px, py) == sf::Color::White;
}

float getAngle(sf::Vector2f &orig, sf::Vector2f &des) {
    return std::atan2(des.y - orig.y, des.x - orig.x)*180/(M_PI);
}

float getAngle(sf::Vector2f &orig, sf::Vector2i &des) {
    return std::atan2(des.y - orig.y, des.x - orig.x)*180/(M_PI);
}


int main(){

    //CREATE THE WINDOW
        sf::RenderWindow window(sf::VideoMode::getDesktopMode() // Size of the window <width,height>
                            ,"Space Tongue" // Title of the window
                            ,sf::Style::Default);
        
        
    sf::Music music;
    if (!music.openFromFile("res/starwars.ogg")) std::cout << "fail on music load" << std::endl; // error
    music.play();
    sf::Time t1 = sf::seconds(21);
    music.setPlayingOffset(t1);
          
     
     Portada portada;
     portada.display(&window, "res/Cover.png",5,2,0.35);
     
    Portada portada2;     
    portada2.display(&window, "res/thecredits.png", 2, 2, 2);
    
    Frases frases(window);
    frases.run(window);
    LevelManager lvlMng("res/levelsfile.txt");
    Menu menu(&window);
    music.stop();
    
    if (!music.openFromFile("res/music.ogg")) std::cout << "fail on music2 load" << std::endl; // error
    music.play();
    music.setLoop(true);

    while (true) {
        int currentLvl = menu.run();
        if (currentLvl >= 0) {
            bool playing = true;
            while (playing) {
                Scene mygame(&window, lvlMng.getLevel(currentLvl)); // Style of the window
                playing = mygame.run();
                if (mygame.getSuccess()) {
                    currentLvl += 1;
                    if (currentLvl >= lvlMng.getNumLevels()) currentLvl = 1;
                    else menu.setLevel(currentLvl);
                }
            }
        }
    }
    music.stop();
}
