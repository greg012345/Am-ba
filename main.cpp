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




int main()
{
    Alkalmazas *alk = new Alkalmazas;
    vector <string> szin {"kek","zold","sarga","feher","fekete"};
    vector <string> szamok{"egy","ketto","harom","negy","ot"};
    alk->megy();
    return 0;
}
