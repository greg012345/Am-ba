#include "alkalmazas.hpp"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class gomb;
class Menu;
void Alkalmazas::pakol(){
    d1 ->adat();
}
void Alkalmazas::visszapakol(){
    cout << "AA";
}
Alkalmazas::Alkalmazas() :Ablak(750,750){
    int akt = 0;
   // d2 = new Gomb(this,325,325,50,50,10,"jatek",[this](){visszapakol();});
    for(int i  = 0;i< 15;i++){ // oszlop
        for(int j = 0;j<15;j++){ // sor
            d1 = new Doboz(this,0+(i*50),0+(j*50),50,50,i,j,akt); //a*,x,y,dx,dy,szél i,hosz j,akt //sor,oszlop
        }
    }

};

