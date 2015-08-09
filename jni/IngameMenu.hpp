#ifndef INGAMEMENU_HPP
#define INGAMEMENU_HPP

#include "utils.hpp"
#include "Button.hpp"
#include "Resources.hpp"


class IngameMenu {
public:

IngameMenu() {}

IngameMenu(sf::Vector2f center) :
    resume("", "res/boton_01.png", center.x/8,center.y/6),
    reset("", "res/button_resset.png", center.x/8,center.y/6),
    menu("", "res/boton_02.png", center.x/8,center.y/6)
{

    resume.setSize(center.x/4,center.y/3);
    resume.setPosition(center.x-resume.getSize().x,center.y + 10);
    
    reset.setSize(center.x/4,center.y/3);
    reset.setPosition(center.x-reset.getSize().x,center.y + center.y/3);

    menu.setSize(center.x/4,center.y/3);
    menu.setPosition(center.x-menu.getSize().x,center.y - center.y/3);

    background = sf::RectangleShape(
                sf::Vector2f(
                    std::max(resume.getSize().x, menu.getSize().x) + 20,
                    resume.getSize().y + menu.getSize().y +30));
    background.setOrigin(background.getSize().x/2, background.getSize().y/2);
    background.setPosition(center);
    background.setFillColor(sf::Color::Black);

    resume.setPosition(resume.getPosition().x+background.getSize().x/2-10, resume.getPosition().y);
    reset.setPosition(reset.getPosition().x+background.getSize().x/2-10, reset.getPosition().y);
    menu.setPosition(menu.getPosition().x+background.getSize().x/2-10, menu.getPosition().y);
}

void draw(sf::RenderWindow &window) {
    //window.draw(background);
    resume.draw(window);
    menu.draw(window);
    reset.draw(window);
}

void handleEvent(sf::Event event) {
    menu.handleEvent(event);
    reset.handleEvent(event);
    resume.handleEvent(event);
}

bool wantToResume() {
    return resume.hasBeenClicked();
}

bool wantToReset() {
    return reset.hasBeenClicked();
}

bool wantToMenu() {
    return menu.hasBeenClicked();
}


private:
    Button resume;
    Button reset;
    Button menu;
    sf::RectangleShape background;
};

#endif // INGAMEMENU_HPP
