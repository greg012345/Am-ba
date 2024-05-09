#include "graphics.hpp"
#include "oswid.hpp"
#include "szam.hpp"
#include "menu.hpp"
#include "gomb.hpp"
#include "alkalmazas.hpp"
#include <vector>
#include "ablak.hpp"
#include <iostream>
using namespace std;

/*void kiir(){
    cout << "X";
}*/


int main()
{
    //Ablak *a = new Ablak(600,600);
    Alkalmazas *alk = new Alkalmazas;
    vector <string> szin {"kek","zold","sarga","feher","fekete"};
    vector <string> szamok{"egy","ketto","harom","negy","ot"};

    //Szam * d1 = new Szam(a,10,10,100,50,10,-10,20);
    //Szam * d2 = new Szam(a,200,10,200,100,4,-30,150); //x,y,dobozx,dobozy,szam,min,max
    //Menu * d3 = new Menu(a,100,250,70,60,4,szin,"szinek");//x,y,dobozx,dobozy,db,vector,kezdő
    //Menu * d4 = new Menu(a,500,250,70,60,3,szamok,"szamok");
    //Gomb * b1 = new Gomb(alk,300,250,50,50,0,">",[alk](){alk->pakol();});
    //Gomb * b2 = new Gomb(a,370,250,50,50,0,"<",kiir);

    alk->megy();


    /*ofstream ofs("adatok.txt");
    ofs << adat[0] << endl << adat[1] << endl << szin[adat[2]] << endl << szamok[adat[3]];
    ofs.close();*/
    return 0;
}
