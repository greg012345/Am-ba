#include "alkalmazas.hpp"
#include "ablak.hpp"

using namespace std;

const int XX = 750;
const int YY = 750;

Alkalmazas::Alkalmazas() :Ablak(XX,YY){
    for(int i  = 0;i< 15;i++){
        for(int j = 0;j<15;j++){
          d1 = new Doboz(this,0+(i*50),0+(j*50),50,50,i,j);
        }
    }
};

