#include "alkalmazas.hpp"
#include <vector>
#include <iostream>
using namespace std;
class gomb;
class Menu;
void Alkalmazas::pakol(){
    cout << "BB";
}
void Alkalmazas::visszapakol(){
    cout << "AA";
}
Alkalmazas::Alkalmazas() :Ablak(750,750){
    int akt = 0;
    /*Menu * d3 = new Menu(this,100,250,70,60,4,
        vector <string>{"kek","zold","sarga","feher","fekete"},"szinek");//x,y,dobozx,dobozy,db,vector,kezdő
    Menu * d4 = new Menu(this,500,250,70,60,3,
    vector <string>{"egy","ketto","harom","negy","ot"},"szamok");
    Gomb * d1 = new Gomb(this,300,250,50,50,0,">",[this](){this->pakol();});
    Gomb * d2 = new Gomb(this,370,250,50,50,0,"<",[this](){this->visszapakol();});*/
    for(int i  = 0;i< 15;i++){ // oszlop
        for(int j = 0;j<15;j++){ // sor
            Doboz * d1 = new Doboz(this,0+(i*50),0+(j*50),50,50,j,i,akt); //a*,x,y,dx,dy,szél i,hosz j,akt //sor,oszlop
            //Doboz * d2 = new Doboz(this,50,250+(i*50),50,50,10,10);
        }
    }

    //Doboz * d6 = new Doboz(this,400,250,50,50,10,10);
}

