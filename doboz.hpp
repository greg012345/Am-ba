#ifndef DOBOZ_HPP
#define DOBOZ_HPP
#include "oswid.hpp"
#include "ablak.hpp"
class Doboz :public Oswid{
protected:
    int aka,_hossz;
    bool rajzol,kor,volte;
public:
    Doboz (Ablak * _ablak,int x, int y, int s_x, int s_y, int szél,int _hossz);
    virtual void rajz();
    virtual bool tallal(int poz_x, int poz_y,int _x,int _y,int doboz_x,int doboz_y);
    virtual void futas(genv::event ev);
    virtual int adat();
    virtual int adat2();
};





#endif // DOBOZ_HPP
