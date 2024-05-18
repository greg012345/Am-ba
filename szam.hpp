#ifndef SZAM_HPP
#define SZAM_HPP
#include "graphics.hpp"
#include "oswid.hpp"

class Szam : public Oswid {
protected:
    bool _checked;
    int min,max;
public:
    Szam(Ablak * _ablak,int x, int y, int sx, int sy,int szam, int _min,int _max);
    virtual void rajz() ;
    virtual void futas(genv::event ev);
    virtual int adat();
};

#endif // SZAM_HPP
