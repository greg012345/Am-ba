#include "doboz.hpp"
#include "graphics.hpp"
#include "ablak.hpp"
#include <cmath>
#include <iostream>

using namespace genv;
using namespace std;

Doboz ::Doboz(Ablak * _ablak,int x, int y , int s_x, int s_y, int szam,int hossz)
    :Oswid(_ablak,x,y,s_x,s_y,szam),_hossz(hossz)
{
    volte = true;
    rajzol = false;
    kor = false;
}

bool Doboz::tallal(int poz_x, int poz_y,int _x,int _y,int doboz_x,int doboz_y)
{
    return poz_x>=_x && poz_x<=_x+doboz_x && poz_y>=_y && poz_y<=_y+doboz_y;
}

void Doboz::rajz(){
    gout << color(0,0,0) << move_to(_x,_y) << box(doboz_x,doboz_y)
         <<color  (10,141,237) << move_to(_x+2,_y+2) << box(doboz_x-4,doboz_y-4);
    if(rajzol){
        gout << color(0,0,0);
        gout << move_to(_x+4, _y+4) << line(doboz_x-8, doboz_y-8);
        gout << move_to(_x+5, _y+4) << line(doboz_x-8, doboz_y-8);
        gout << move_to(_x+doboz_x-4, _y+4) << line(-doboz_x+8, doboz_y-8);
        gout << move_to(_x+doboz_x-5, _y+4) << line(-doboz_x+8, doboz_y-8);
    }
    if(kor){
        gout << color(255,51,51);
        int radius = doboz_x / 3;
        int x = _x + doboz_x / 2;
        int y = _y + doboz_x / 2;

        for (int i = 0; i < 360; i++) {
            int x1 = x + radius * cos(i * M_PI / 180);
            int y1 = y + radius * sin(i * M_PI / 180);
            int x2 = x + radius * cos((i+1) * M_PI / 180);
            int y2 = y + radius * sin((i+1) * M_PI / 180);
            gout << move_to(x1, y1) << line(x2 - x1, y2 - y1);
        }
    }
    if(_ablak->gyoztes(1)){
        gout << move_to(0, 0) << color(10, 141, 237) << box(750, 750)
             << color(255, 255, 255) << move_to(355, 375) << box(100, 50)
             << color(10, 141, 237) << move_to(360, 380) << box(90, 40)
             << color(255, 255, 255) << move_to(365, 405) << text("O Gyozott!") << refresh;
    }
    if(_ablak->gyoztes(2)){
        gout << move_to(0, 0) << color(10, 141, 237) << box(750, 750)
             << color(255, 255, 255) << move_to(375, 375) << box(100, 50)
             << color(10, 141, 237) << move_to(380, 380) << box(90, 40)
             << color(255, 255, 255) << move_to(385, 405) << text("X Gyozott!") << refresh;
    }
    if(_ablak->teli()){
        gout << move_to(0, 0) << color(10, 141, 237) << box(750, 750)
             << color(255, 255, 255) << move_to(375, 375) << box(100, 50)
             << color(10, 141, 237) << move_to(380, 380) << box(90, 40)
             << color(255, 255, 255) << move_to(385, 405) << text("Teli") << refresh;
    }
}
void Doboz::futas(event ev)
{
    if(volte){
        if(tallal(ev.pos_x,ev.pos_y,_x,_y,doboz_x,doboz_y)
            && ev.button == -btn_left &&_ablak->ertekAtadas() == 2){
            rajzol = true;
            volte = false;
        }
        if(tallal(ev.pos_x,ev.pos_y,_x,_y,doboz_x,doboz_y)
            && ev.button == -btn_left && _ablak->ertekAtadas() == 1 ){
            kor = true;
            volte = false;
        }
    }
}

int Doboz::adat(){
    return _szam;
}

int Doboz::adat2(){
    return _hossz;
}


