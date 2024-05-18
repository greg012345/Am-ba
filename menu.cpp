#include "menu.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;


int keres(int aktx, int x, int sizex){
    int val = (aktx / sizex)*sizex;
    return (val-x)/sizex;
}
Menu ::Menu(Ablak * _ablak,int x, int y , int s_x, int s_y, int szam,vector<string> nev,string _kiaras)
    :Oswid(_ablak,x,y,s_x,s_y,szam),kiaras(_kiaras),_nev(nev){
    aka = 0;
    csukva = false;
}
bool Menu::tallal(int poz_x, int poz_y,int _x,int _y,int doboz_x,int doboz_y)
{
    return poz_x>=_x && poz_x<=_x+doboz_x && poz_y>=_y && poz_y<=_y+doboz_y;
}


void Menu::rajz(){
    if(csukva){
        for(int i =  0; i< _szam;i++){
            gout << move_to(_x,_y+(doboz_y*i)+doboz_y) <<color(51,255,51)
                 << box(doboz_x,doboz_y) <<   color(255,51,51)
                 <<move_to(_x+doboz_x/3,_y+doboz_y/3+doboz_y+(i*doboz_y)) <<text(_nev[i]);
            gout << refresh;

        }
    }
    else{
        gout << move_to(_x,_y) <<color(51,255,51)
             << box(doboz_x,doboz_y) << color(255,51,51) << move_to(_x+doboz_x/6,_y+doboz_y/2)
             << text(kiaras);
        gout << move_to(_x,_y+doboz_y) << color(10,141,237)<< box(doboz_x,(_szam*doboz_y)) << refresh;
    }
}

void Menu::futas(event ev)
{
    int akt = -1;
    if(tallal(ev.pos_x,ev.pos_y,_x,_y,doboz_x,doboz_y)){
        csukva = true;
    }
    for(int i = _x;i<_x+doboz_x;i++){
        for(int j = _y+doboz_y;j <=_y+(doboz_y*(_szam+1));j+= doboz_y){
            akt ++;
            if(tallal(ev.pos_x,ev.pos_y,i,j,doboz_x,doboz_y) && ev.button == btn_left&& csukva && i != ev.pos_x && j != ev.pos_y){
                csukva = false;
                kiaras = _nev[akt];
                aka = akt;
            }
        }
    }
    if(tallal(ev.pos_x,ev.pos_y,_x,_y+(doboz_y*_szam)+doboz_y,doboz_x,doboz_y) && csukva){
        csukva = false;
    }
    if(tallal(ev.pos_x,ev.pos_y,_x-doboz_x,_y,doboz_x,doboz_y )&& csukva){
        csukva = false;
    }
    if(tallal(ev.pos_x,ev.pos_y,_x+doboz_x,_y,doboz_x,doboz_y )&& csukva){
        csukva = false;
    }
    if(tallal(ev.pos_x,ev.pos_y,_x,_y-doboz_y,doboz_x,doboz_y )&& csukva){
        csukva = false;
    }
    for(int i = 0;i < _szam;i++){
        if(tallal(ev.pos_x,ev.pos_y,_x+doboz_x,_y+(doboz_y*i)+doboz_y,doboz_x,doboz_y) && csukva){
            csukva = false;
        }
        if(tallal(ev.pos_x,ev.pos_y,_x-doboz_x,_y+(doboz_y*i)+doboz_y,doboz_x,doboz_y) && csukva){
            csukva = false;
        }
    }
}

int Menu::adat(){
    return aka;
}
