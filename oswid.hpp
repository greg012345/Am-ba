#ifndef OSWID_HPP
#define OSWID_HPP
#include "graphics.hpp"

class Ablak;
class Oswid {
protected:
    Ablak *_ablak;
    int _x, _y, doboz_x, doboz_y,_szam;
public:
    Oswid(Ablak * _ablak,int x, int y, int dobozx, int dobozy,int szam);
    virtual void rajz() = 0;
    virtual void futas(genv::event ev) = 0;
    virtual int adat() = 0;
    virtual int adat2() = 0;
    virtual bool aktiv(int poz_x, int poz_y);
};

#endif // OSWID_HPP
