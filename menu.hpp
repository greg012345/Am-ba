#ifndef MENU_HPP
#define MENU_HPP
#include "oswid.hpp"
#include "graphics.hpp"

class Menu :public Oswid{
protected:
    int aka;
    bool csukva;
    std::string kiaras;
    std::vector <std::string> _nev;
public:
    Menu (Ablak * _ablak,int x, int y, int s_x, int s_y, int szam, std::vector<std::string> _nev, std::string _kiaras);
    virtual void rajz();
    virtual bool tallal(int poz_x, int poz_y,int _x,int _y,int doboz_x,int doboz_y);
    virtual void futas(genv::event ev);
    virtual int adat();
};
#endif // MENU_HPP
