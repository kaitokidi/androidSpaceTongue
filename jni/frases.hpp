#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "Portada.hpp"
#include "Stdiobuf.hpp"
#include "Background.hpp"

using namespace std;

class Frases {

private:

  float tiempo;
  sf::Font font;
  float velocidad;

  vector<string> frases;
  map<char,string> c2s;

  Background background;

public:

wstring stow(string frase)
{
  map<string,wstring> mapa;
  mapa["à"]=L"à";
  mapa["á"]=L"á";
  mapa["è"]=L"è";
  mapa["é"]=L"é";
  mapa["í"]=L"í";
  mapa["ì"]=L"ì";
  mapa["ó"]=L"ó";
  mapa["ò"]=L"ò";
  mapa["ú"]=L"ú";
  mapa["ù"]=L"ù";
  mapa["ü"]=L"ü";
  mapa["ç"]=L"ç";
  wstring wfrase;
  for (int i=0;i<int(frase.size());) {
    bool trobat=false;
    for (map<string,wstring>::iterator it=mapa.begin();it!=mapa.end() and !trobat;it++) {
      string s=it->first;
      wstring ws=it->second;
      if (i+int(s.size())<=int(frase.size()) and frase.substr(i,int(s.size()))==s) {
    wfrase+=ws;
    i+=int(ws.size());
    trobat=true;
      }
    }
    if (not trobat) {
      wfrase+=frase[i];
      i++;
    }
  }
  return wfrase;
}


float computaEscala(float h,float despobjeto)
{
    return h/despobjeto;
}

void dibujafrase(int centropantalla,int hobservador,int despobservador,
                         int numfrase,int desp,int hcaracter,string &frase,sf::RenderWindow &window)
{
  float factor=3.0;

  float despobjeto=desp-(hcaracter+10)*numfrase;
  if (despobjeto<despobservador/2.0) return;
  hobservador-=despobjeto*factor;
  float escala=computaEscala(float(hobservador),despobjeto-despobservador);
  float escalacaracter=computaEscala(float(hobservador),40+despobjeto-despobservador);
  sf::Text text;


  std::wstring wfrase=stow(frase);

  text.setString(wfrase);

  text.setFont(font);
  text.setColor(sf::Color::Yellow);
  
  float hfrase=escala*despobjeto;
  float midahfrase=escalacaracter*hcaracter;
  text.setOrigin(sf::Vector2f(text.getLocalBounds().width/2.0,text.getLocalBounds().height/2.0));
  text.setScale(sf::Vector2f(midahfrase/(1.7*text.getLocalBounds().height),midahfrase/text.getLocalBounds().height));
  text.setPosition(sf::Vector2f(float(centropantalla),hobservador-hfrase));

  //text.setPosition(sf::Vector2f(float(centropantalla),0));
 // std::cout<<frase<<std::endl;
  window.draw(text);
}


Frases(sf::RenderWindow& window) : background(window){

    tiempo=0;
    velocidad=20;
    if (!font.loadFromFile("res/font.otf")) {
        cout<<"no carrega la font"<<endl;
        exit(0);
    }
  
    frases.push_back("  En una galaxia molt molt llunyana");
    frases.push_back("el pilot pingüí Darth Lubitz queda");
    frases.push_back("sotmès al costat depressiu de la");
    frases.push_back("força i estabella la seva nau tot");
    frases.push_back("acabant amb la vida de 150 passatgers.");
    frases.push_back("                                     ");

    frases.push_back("Els pingüins Jedi decideixen que");
    frases.push_back("això no pot tornar a passar i creen");
    frases.push_back("un mecanisme de vols no pilotats");
    frases.push_back("basat en uns camaleons titànics que");
    frases.push_back("funcionen com a controladors aèris,");
    frases.push_back("i que condueixen les naus al seu destí.");
    frases.push_back("                                     ");
    
    frases.push_back("La teva missió serà entrenar als");
    frases.push_back("camaleons en aquesta nova tasca,");
    frases.push_back("doncs no hi estan acostumats,");
    frases.push_back("ja que habitualment fan servir la seva");
    frases.push_back("fastigosa llengua per a capturar insectes.");
    frases.push_back("                                     "); 
    
}

void dibujafrases(int centropantalla,int hobservador,int despobservador,int hcaracter,
                          sf::RenderWindow &window,float delta) {
    tiempo+=delta;
    int desp=50+tiempo*velocidad;
    for (int i=0;i<int(frases.size());i++)
        dibujafrase(centropantalla,hobservador,despobservador,i,desp,hcaracter,frases[i],window);
}

void run(sf::RenderWindow & window) {
    sf::Clock c;
    while(window.isOpen() && tiempo < frases.size()*25/16 /*25-16  30*/) {
        float deltaTime = c.restart().asSeconds();
        sf::Event event;
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                    ((event.type == sf::Event::KeyPressed) &&
                     (event.key.code == sf::Keyboard::Escape)))
            {
                return;
            }
        }
        background.update(deltaTime);
        window.clear();
        background.draw(window);
        dibujafrases(window.getSize().x/2.0,window.getSize().y+100,-100,20,window,deltaTime);
        window.display();
    }

}

};
