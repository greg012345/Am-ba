#include "gomb.hpp"
#include <iostream>
using namespace std;
using namespace genv;
#include <functional>

Gomb :: Gomb(Ablak * _ablak,int x, int y, int sx, int sy,int szam, string szok
            ,std::function<void()> fv)
    : Oswid(_ablak,x,y,sx,sy,szam) , szo(szok),fv(fv){
      };


bool Gomb::tallal(int poz_x, int poz_y,int doboz_x,int doboz_y)
{
    return poz_x>=_x && poz_x<=_x+doboz_x && poz_y>=_y && poz_y<=_y+doboz_y;
}

void Gomb::rajz(){
    gout << color(0,0,0) << move_to(_x,_y) << box(doboz_x,doboz_y)
         << color(255,255,255) << move_to(_x+15,_y+15) << text(szo);
    //gout << color(255,0,0) << move_to(_x,_y+doboz_y) << box(doboz_x,doboz_y) << move_to(_x,_y+doboz_y+20)
         //<< color(0,0,0)<< text(szo);
}

void Gomb::futas(genv::event ev){
    if(tallal(ev.pos_x,ev.pos_y,doboz_x,doboz_y) && ev.button == btn_right){
        //szo = _nev[rand() % _nev.size()];
        fv();
    }
}
int Gomb::adat(){
    return 0;
}


