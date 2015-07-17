#ifndef LEVELMANAGER_HPP
#define LEVELMANAGER_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "utils.hpp"

using namespace std;

void readlevels(std::vector<std::string> &text){
text.push_back(" inicio 412 227 " ); 
text.push_back(" final 1406 773 " ); 
text.push_back(" velocidad 100 100 " ); 
text.push_back(" camaleon 612 527 1 " ); 
text.push_back(" camaleon 1112 327 0 " ); 
text.push_back(" camaleon 812 627 0 " ); 
text.push_back(" camaleon 0 98 0 " ); 
text.push_back(" obstaculo 662 177 " ); 
text.push_back(" obstaculo 622 0 " ); 
text.push_back(" obstaculo 521 16 " ); 
text.push_back(" obstaculo 433 26 " ); 
text.push_back(" obstaculo 366 59 " ); 
text.push_back(" obstaculo 327 118 " ); 
text.push_back(" obstaculo 302 185 " ); 
text.push_back(" obstaculo 280 302 " ); 
text.push_back(" obstaculo 280 302 " ); 
text.push_back(" obstaculo 267 490 " ); 
text.push_back(" obstaculo 267 613 " ); 
text.push_back(" obstaculo 285 663 " ); 
text.push_back(" obstaculo 325 715 " ); 
text.push_back(" obstaculo 426 792 " ); 
text.push_back(" obstaculo 454 800 " ); 
text.push_back(" obstaculo 541 848 " ); 
text.push_back(" obstaculo 611 881 " ); 
text.push_back(" obstaculo 701 899 " ); 
text.push_back(" obstaculo 771 899 " ); 
text.push_back(" obstaculo 785 899 " ); 
text.push_back("  " ); 
text.push_back(" nuevonivel " ); 
text.push_back(" inicio 100 100 " ); 
text.push_back(" final 1500 700 " ); 
text.push_back(" velocidad 200 0 " ); 
text.push_back(" camaleon 300 300 0 " ); 
text.push_back(" camaleon 800 300 0 " ); 
text.push_back(" camaleon 120 300 0 " ); 
text.push_back(" camaleon 300 700 0 " ); 
text.push_back(" camaleon 800 700 0 " ); 
text.push_back(" camaleon 120 700 0 " ); 
text.push_back("  " ); 
text.push_back(" nuevonivel " ); 
text.push_back(" inicio 100 0 " ); 
text.push_back(" final 100 900 " ); 
text.push_back(" velocidad 200 0 " ); 
text.push_back(" camaleon 100 500 0 " ); 
text.push_back(" camaleon 300 500 0 " ); 
text.push_back(" camaleon 500 500 0 " ); 
text.push_back(" camaleon 700 500 0 " ); 
text.push_back(" camaleon 900 500 0 " ); 
text.push_back(" camaleon 1200 500 0 " ); 
text.push_back("  " ); 
text.push_back(" nuevonivel " ); 
text.push_back(" inicio 100 0 " ); 
text.push_back(" final 100 500 " ); 
text.push_back(" velocidad 200 0 " ); 
text.push_back(" camaleon 100 300 0 " ); 
text.push_back(" camaleon 300 300 0 " ); 
text.push_back(" camaleon 500 300 0 " ); 
text.push_back(" camaleon 700 300 0 " ); 
text.push_back(" camaleon 900 300 0 " ); 
text.push_back(" camaleon 1200 300 0 " ); 
text.push_back(" camaleon 100 900 0 " ); 
text.push_back(" camaleon 300 900 0 " ); 
text.push_back(" camaleon 500 900 0 " ); 
text.push_back(" camaleon 700 900 0 " ); 
text.push_back(" camaleon 900 900 0 " ); 
text.push_back(" camaleon 1200 900 0 " ); 
text.push_back("  " ); 
text.push_back(" nuevonivel " ); 
text.push_back(" inicio 100 0 " ); 
text.push_back(" final 100 500 " ); 
text.push_back(" velocidad 200 0 " ); 
text.push_back(" camaleon 100 200 0 " ); 
text.push_back(" camaleon 200 200 0 " ); 
text.push_back(" camaleon 300 200 0 " ); 
text.push_back(" camaleon 400 200 0 " ); 
text.push_back(" camaleon 500 200 0 " ); 
text.push_back(" camaleon 100 350 0 " ); 
text.push_back(" camaleon 200 350 0 " ); 
text.push_back(" camaleon 300 350 0 " ); 
text.push_back(" camaleon 400 350 0 " ); 
text.push_back(" camaleon 500 350 0 " ); 
text.push_back(" camaleon 100 650 0 " ); 
text.push_back(" camaleon 200 650 0 " ); 
text.push_back(" camaleon 300 650 0 " ); 
text.push_back(" camaleon 400 650 0 " ); 
text.push_back(" camaleon 500 650 0 " ); 
text.push_back(" camaleon 100 800 0 " ); 
text.push_back(" camaleon 200 800 0 " ); 
text.push_back(" camaleon 300 800 0 " ); 
text.push_back(" camaleon 400 800 0 " ); 
text.push_back(" camaleon 500 800 0 " ); 
text.push_back("  " ); 
text.push_back(" nuevonivel " ); 
text.push_back(" inicio 350 500 " ); 
text.push_back(" final 500 950 " ); 
text.push_back(" velocidad 200 0 " ); 
text.push_back(" camaleon 100 200 0 " ); 
text.push_back(" camaleon 200 200 0 " ); 
text.push_back(" camaleon 300 200 0 " ); 
text.push_back(" camaleon 400 200 0 " ); 
text.push_back(" camaleon 500 200 0 " ); 
text.push_back(" camaleon 100 350 0 " ); 
text.push_back(" camaleon 500 350 0 " ); 
text.push_back(" camaleon 100 650 0 " ); 
text.push_back(" camaleon 500 650 0 " ); 
text.push_back(" camaleon 100 800 0 " ); 
text.push_back(" camaleon 200 800 0 " ); 
text.push_back(" camaleon 300 800 0 " ); 
text.push_back(" camaleon 400 800 0 " ); 
text.push_back(" camaleon 500 800 0 " ); 
text.push_back("  " ); 
text.push_back(" nuevonivel " ); 
text.push_back(" inicio 150 573 " ); 
text.push_back(" final 1427 444 " ); 
text.push_back(" velocidad 100 100 " ); 
text.push_back(" camaleon 565 230 1 " ); 
text.push_back(" camaleon 665 841 1 " ); 
text.push_back(" camaleon 1059 774 1 " ); 
text.push_back(" camaleon 1010 221 1 " ); 
text.push_back(" camaleon 0 584 0 " ); 
text.push_back(" obstaculo 666 711 " ); 
text.push_back(" obstaculo 658 657 " ); 
text.push_back(" obstaculo 652 618 " ); 
text.push_back(" obstaculo 641 557 " ); 
text.push_back(" obstaculo 640 547 " ); 
text.push_back(" obstaculo 632 499 " ); 
text.push_back(" obstaculo 620 449 " ); 
text.push_back(" obstaculo 616 423 " ); 
text.push_back(" obstaculo 612 406 " ); 
text.push_back(" obstaculo 607 379 " ); 
text.push_back(" obstaculo 605 360 " ); 
text.push_back(" obstaculo 598 329 " ); 
text.push_back(" obstaculo 645 582 " ); 
text.push_back(" obstaculo 657 671 " ); 
text.push_back(" obstaculo 1015 285 " ); 
text.push_back(" obstaculo 1015 339 " ); 
text.push_back(" obstaculo 1016 370 " ); 
text.push_back(" obstaculo 1026 401 " ); 
text.push_back(" obstaculo 1036 453 " ); 
text.push_back(" obstaculo 1040 503 " ); 
text.push_back(" obstaculo 1040 550 " ); 
text.push_back(" obstaculo 1040 581 " ); 
text.push_back(" obstaculo 1046 624 " ); 
text.push_back(" obstaculo 1051 662 " ); 
text.push_back(" obstaculo 1054 677 " ); 
text.push_back(" obstaculo 795 814 " ); 
text.push_back(" obstaculo 675 914 " ); 
text.push_back(" obstaculo 675 961 " ); 
text.push_back(" obstaculo 675 1028 " ); 
text.push_back(" obstaculo 675 1085 " ); 
text.push_back(" obstaculo 675 1114 " ); 
text.push_back(" obstaculo 675 1162 " ); 
text.push_back(" obstaculo 675 1241 " ); 
text.push_back(" obstaculo 675 1187 " ); 
text.push_back(" obstaculo 743 821 " ); 
text.push_back(" obstaculo 859 824 " ); 
text.push_back(" obstaculo 884 821 " ); 
text.push_back(" obstaculo 905 818 " ); 
text.push_back(" obstaculo 936 809 " ); 
text.push_back(" obstaculo 958 802 " ); 
text.push_back(" obstaculo 1007 796 " ); 
text.push_back(" obstaculo 1037 789 " ); 
text.push_back(" obstaculo 1071 818 " ); 
text.push_back(" obstaculo 1071 844 " ); 
text.push_back(" obstaculo 1071 891 " ); 
text.push_back(" obstaculo 1071 926 " ); 
text.push_back(" obstaculo 1071 968 " ); 
text.push_back(" obstaculo 1071 1031 " ); 
text.push_back(" obstaculo 1074 1079 " ); 
text.push_back(" obstaculo 1083 1114 " ); 
text.push_back(" obstaculo 1083 1155 " ); 
text.push_back(" obstaculo 1083 1184 " ); 
text.push_back(" obstaculo 1086 1190 " ); 
text.push_back(" obstaculo 1086 1225 " );     
}

struct Level {
  sf::Vector2f inicio,velocidad,final;
  vector<sf::Vector2f> camaleon;
  vector<sf::Vector2f> obstaculo;
  vector<int> tipocamaleon;
  bool iniciodefined,velocidaddefined,finaldefined;
  Level() {
    iniciodefined=velocidaddefined=finaldefined=false;
  }
};


class LevelManager {
private:
  string path;
  vector<Level> vl;

public:
    
    void checkwelldefined(int numlevel,Level level){
  if (not level.iniciodefined) {
    cout<<"Level "<<numlevel<<" with no inicio defined."<<endl;
    exit(0);
  } else if (not level.finaldefined) {
    cout<<"Level "<<numlevel<<" with no final defined."<<endl;
    exit(0);
  } else if (not level.velocidaddefined) {
    cout<<"Level "<<numlevel<<" with no velocidad defined."<<endl;
    exit(0);
  } else if (int(level.camaleon.size())==0) {
    cout<<"Level "<<numlevel<<" with no camaleon."<<endl;
    exit(0);
  }
}

bool my_isint(string s){
  for (int i=0;i<int(s.size());i++)
    if (not (s[i]>='0' and s[i]<='9'))
      return false;
  return true;
}

float my_stof(string s) {
  int x=0;
  for (int i=0;i<int(s.size());i++)
    x=10*x+s[i]-'0';
  return float(x);
}


LevelManager() {}

LevelManager(std::string path){
  this->path = path;
//   ifstream fci(path);
//   if (not fci.is_open()) {
//     cout<<"ERROR opening levelsfile.txt"<<endl;
//     exit(0);
//   }
  
  std::vector<std::string> text;
  
  readlevels(text);
  
  vector<pair<int,string> > vs;
  {
    int numlinea=0;
    string linea;
//     while (getline(fci,linea)) {
    while(numlinea < text.size()){
        linea = text[numlinea];
        numlinea++;
        {
            for (int i=0;i<int(linea.size())-1;i++) {
            if (linea[i]=='/' and linea[i+1]=='/') {
                linea=linea.substr(0,i);
                break;
            }
            }
        }
        istringstream ci(linea);
        {
            string s;
            while(ci>>s)
            vs.push_back(pair<int,string> (numlinea,s));
        }
    }
  }
  vl.push_back(Level());
  for (int i=0;i<int(vs.size());i++) {
    int numlinea=vs[i].first;
    string comando=vs[i].second;
    if (comando=="nuevonivel") {
      checkwelldefined(int(vl.size())-1,vl.back());
      vl.push_back(Level());
      continue;
    }
    Level &level=vl.back();
    if (comando!="inicio" and comando!="final" and
        comando!="velocidad" and comando!="camaleon" and comando!="obstaculo") {
      cout<<"Error line "<<numlinea<<": wrong instruction "<<comando<<"."<<endl;
      exit(0);
    }
    /*
    if (comando=="camaleon" and (i+3>=int(vs.size()) or not my_isint(vs[i+1].second) or not my_isint(vs[i+2].second) or not my_isint(vs[i+3].second))) {
      cout<<"Error line "<<numlinea<<": three integers are needed for "<<comando<<"."<<endl;
      exit(0);
    }
    */
    if (i+2>=int(vs.size()) or not my_isint(vs[i+1].second) or not my_isint(vs[i+2].second)) {
      cout<<"Error line "<<numlinea<<": two integers are needed for "<<comando<<"."<<endl;
      exit(0);
    }
    sf::Vector2f p(my_stof(vs[i+1].second),my_stof(vs[i+2].second));
    if (comando=="inicio") {
      if (level.iniciodefined) {
        cout<<"Error line "<<numlinea<<": inicio already defined."<<endl;
        exit(0);
      }
      level.iniciodefined=true;
      level.inicio=p;
      i+=2;
    } else if (comando=="final") {
      if (level.finaldefined) {
        cout<<"Error line "<<numlinea<<": final already defined."<<endl;
        exit(0);
      }
      level.finaldefined=true;
      level.final=p;
      i+=2;
    } else if (comando=="velocidad") {
      if (level.velocidaddefined) {
        cout<<"Error line "<<numlinea<<": velocidad already defined."<<endl;
        exit(0);
      }
      level.velocidaddefined=true;
      level.velocidad=p;
      i+=2;
    } else if (comando=="camaleon") {
      level.camaleon.push_back(p);
      if (i+3<int(vs.size()) and my_isint(vs[i+3].second)) {
        level.tipocamaleon.push_back(my_stoi(vs[i+3].second));
        i+=3;
      } else {
        level.tipocamaleon.push_back(0);
        i+=2;
      }
      //i++;
    } else if (comando=="obstaculo") {
      level.obstaculo.push_back(p);
      i+=2;
    }
  }
  checkwelldefined(int(vl.size()),vl.back());
}

int getNumLevels(){
  return int(vl.size());
}

Level getLevel(int i){
  return vl[i];
}

void setLevel(int i, Level l) {
  if (i >= vl.size()) vl.push_back(l);
  else vl[i] = l;
}

void escribe(sf::Vector2f &v){
  cout<<v.x<<" "<<v.y<<endl;
}

void escribe(){
  for (int i=0;i<int(vl.size());i++) {
    cout<<"Level "<<i<<endl;
    Level &level=vl[i];
    cout<<"inicio ";escribe(level.inicio);
    cout<<"final ";escribe(level.final);
    cout<<"velocidad ";escribe(level.velocidad);
    for (int j=0;j<int(level.camaleon.size());j++) {
      cout<<"camaleon ";
      escribe(level.camaleon[j]);
    }
    cout<<endl;
  }
}

void escribeAFichero() {
  ofstream file;
  file.open(path);
  for (int i=0;i<int(vl.size());i++) {
    if (i != 0) file<<"nuevonivel"<<endl;
    Level &level=vl[i];
    file<<"inicio " << (int)level.inicio.x << " " << (int)level.inicio.y << endl;
    file<<"final " << (int)level.final.x << " " << (int)level.final.y << endl;
    file<<"velocidad " << (int)level.velocidad.x << " " << (int)level.velocidad.y << endl;
    for (int j=0;j<int(level.camaleon.size());j++) {
      file<<"camaleon " << (int)level.camaleon[j].x << " " << (int)level.camaleon[j].y << " " << level.tipocamaleon[j] << endl;
    }
    for (int j=0;j<int(level.obstaculo.size());j++) {
      file<<"obstaculo " << (int)level.obstaculo[j].x << " " << (int)level.obstaculo[j].y << endl;
    }
    file<<endl;
  }
}

};

#endif
