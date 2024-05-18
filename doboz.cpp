#include "doboz.hpp"
#include "graphics.hpp"
#include "ablak.hpp"
#include <cmath>
#include <iostream>
using namespace genv;
using namespace std;
class Ablak;

Doboz ::Doboz(Ablak * _ablak,int x, int y , int s_x, int s_y, int szam,int hossz,int akt)
    :Oswid(_ablak,x,y,s_x,s_y,szam),_akt(akt),_hossz(hossz)
{
    volte = true;
    rajzol = false;
    kor = false;
}

bool Doboz::tallal(int poz_x, int poz_y,int _x,int _y,int doboz_x,int doboz_y)
{
    return poz_x>=_x && poz_x<=_x+doboz_x && poz_y>=_y && poz_y<=_y+doboz_y;
}

//10,141,237
// 2 x 1 kor
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
        gout << color(0,0,0);
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
    if(_ablak->gyoztes(2)){
        gout << move_to(300,300) << color(212,22,10) << text("Fasza x");
    }
    if(_ablak->gyoztes(1)){
        gout << move_to(300,300) << color(212,22,10) << text("Fasza kor");
    }
}

void Doboz::futas(event ev)
{
    if(volte){
    if(tallal(ev.pos_x,ev.pos_y,_x,_y,doboz_x,doboz_y)
        && ev.button == -btn_left && _ablak->ertekAtadas() == 2){
        rajzol = true;
        kiirás();
        volte = false;
    }
    if(tallal(ev.pos_x,ev.pos_y,_x,_y,doboz_x,doboz_y)
        && ev.button == -btn_left && _ablak->ertekAtadas() == 1 ){
        kor = true;
        kiirás();
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

void Doboz::kiirás(){
    //cout << _ablak->ertekAtadas();
    cout << _ablak->gyoztes(1);
}


