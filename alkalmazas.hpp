#ifndef ALKALMAZAS_HPP
#define ALKALMAZAS_HPP
#include "ablak.hpp"
#include "menu.hpp"
#include "gomb.hpp"
#include "doboz.hpp"
#include <iostream>
class Alkalmazas : public Ablak{
    Doboz * d1;
    Gomb * d2;
public:
    Alkalmazas();
    void pakol();
    void visszapakol();
};
#endif // ALKALMAZAS_HPP
