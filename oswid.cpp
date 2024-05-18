#include "oswid.hpp"
#include "ablak.hpp"
using namespace genv;

Oswid::Oswid(Ablak * a, int x, int y, int sx, int sy,int szam) :_ablak(a), _x(x), _y(y), doboz_x(sx), doboz_y(sy), _szam(szam)
{
    _ablak ->add_wid(this);
}

bool Oswid::aktiv(int poz_x, int poz_y)
{
    return poz_x>_x && poz_x<_x+doboz_x+doboz_x/2 && poz_y>_y && poz_y<_y+doboz_y+doboz_y/2;
}



