#ifndef GOMB_HPP
#define GOMB_HPP
#include "oswid.hpp"
#include <functional>

class Gomb:public Oswid{
protected:
    std ::string szo;
    //std::vector<std::string> _nev;
    std::function<void()> fv;
public:
    Gomb (Ablak * _ablak ,int x, int y, int s_x, int s_y,
         int szam, std::string szo,std::function<void()> fv);
    //Gomb (Ablak * _ablak ,int x, int y, int s_x, int s_y,
      //   int szam, std::string szo,std::vector<std::string> _nev,std::function<void()> stdf);
    void szovalt();
    virtual void rajz();
    virtual void futas(genv::event ev);
    virtual bool tallal(int poz_x, int poz_y,int doboz_x,int doboz_y);
    virtual int adat();
};
#endif // GOMB_HPP
