#include "szam.hpp"
#include "graphics.hpp"
using namespace genv;
using namespace std;
Szam::Szam(Ablak* _ablak,int x, int y, int sx, int sy,int sza, int _min,int _max):
    Oswid(_ablak,x,y,sx,sy,sza),min(_min),max(_max)
{
    _checked=false;
}

int Szam::adat(){
    return _szam;
}
void Szam::rajz()
{
    gout << move_to(_x,_y) << color(255,255,255) << box(doboz_x,doboz_y)
         << color (100,0,0)<< move_to(_x+doboz_x/2-10,_y+doboz_y/2+10)<<text(to_string(_szam));
    gout << move_to(_x,_y+doboz_y)  <<color(255,51,51) << box(doboz_x/2,doboz_y/2)
         << color (0,0,0)<< move_to(_x+doboz_x/4,_y+doboz_y+20) <<text("+");
    gout << move_to(_x+(doboz_x/2),_y+doboz_y) << color(255,51,51) << box(doboz_x/2,doboz_y/2)
         << color (0,0,0)<< move_to(_x+doboz_x/2+doboz_x/4,_y+doboz_y+20) <<text("-");
}

void Szam::futas(event ev)
{
    if(ev.pos_x >= _x && ev.pos_x <= _x+doboz_x/2 && ev.pos_y >=_y+doboz_y  && ev.pos_y <= _y+doboz_y+doboz_y/2
        && ev.button == -btn_left){
        _szam++;
    }
    if(ev.pos_x >= _x+doboz_x/2 && ev.pos_x <= _x+doboz_x  && ev.pos_y >=_y+doboz_y
        && ev.pos_y <=_y+doboz_y+doboz_y/2 && ev.button == -btn_left){
        _szam--;
    }
    if(_szam > min){
        if(ev.keycode == key_down){
            _szam--;
        }
        if(ev.keycode == key_pgdn && (_szam-10 >= min)){
            _szam-= 10;
        }
    }
    if(_szam < max){
        if(ev.keycode == key_up){
            _szam++;
        }
        if(ev.keycode == key_pgup && (max >= _szam+10)){
            _szam+= 10;
        }
    }

}

