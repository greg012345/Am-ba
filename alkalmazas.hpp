#ifndef ALKALMAZAS_HPP
#define ALKALMAZAS_HPP
#include "ablak.hpp"
#include "menu.hpp"
#include "gomb.hpp"
#include "doboz.hpp"
class Alkalmazas : public Ablak{
    /*Gomb * d1;
    Gomb * d2;
    Menu * d3;
    Menu * d4;*/
    Doboz * d5;
    //Doboz * d6;
public:
    Alkalmazas();
    void pakol();
    void visszapakol();
};
#endif // ALKALMAZAS_HPP
