#include "ablak.hpp"
#include <iostream>
#include <vector>
#include "oswid.hpp"
#include <set>
using namespace std;
using namespace genv;
#include "graphics.hpp"
vector <int> adat;
#include <fstream>
Ablak::Ablak(int X, int Y){
    gout.open(X,Y);
    gout << move_to(0,0) << color(10,141,237)<< box(X,Y);
}
vector<vector<int>> xx(15, vector<int>(15, 0)); // sor oszlop
vector<vector<int>> yy(15, vector<int>(15, 0)); // sor oszlop

void Ablak::megy(){
event ev;
int akt = -1;
vector <int> x;
vector <int> korx;
vector <int> kory;
int meret = 0;
while(gin >> ev ) {
    if (ev.type == ev_mouse && ev.button == btn_left) {
        for (size_t i = 0; i < c.size();i++) {
            if (c[i]->aktiv(ev.pos_x, ev.pos_y)) {
                cout << "Widget " << i << " activated." << endl ;
                akt = i;
                meret ++;
                korx.push_back(c[akt]->adat());
                kory.push_back(c[akt]->adat2());
                if (meret % 2 == 0){
                    xx[c[i]->adat2()][c[i]->adat()] = 1;
                }
                else{
                    xx[c[i]->adat2()][c[i]->adat()] = 2;
                }
            }
        }
    }
    if (akt!=-1) {
        c[akt]->futas(ev);
    }
    for (Oswid * w : c) {
        w->rajz();
    }
    gout << refresh;
};

ofstream ofs("ki.txt");
for(int a = 0; a<15;a++){{
        for(int b = 0;b<15;b++){
            ofs << xx[a][b] << " ";
        }
        ofs << endl;
    }
}
ofs.close();
};
int Ablak::ertekAtadas(){
    int meret = 0;
    for(int a = 0; a<15;a++){{
            for(int b = 0;b<15;b++){
                if(xx[a][b] != 0){
                    meret++;
                }
            }
        }
    }
    if(meret % 2 == 0){
        return 1;
    }
    else{
        return 2;
    }
};
// 2 = x 1 = kör
/*bool Ablak::gyoztes(){
    for(int a = 0; a<15;a++){
        for(int b = 0;b<15;b++){
            bool gyoz = true;
            for(size_t k = 0;k<5;k++){
                if(xx[a][b+k] != 2){
                    gyoz = false;
                    break;
                }
            }
            if(gyoz){
                return true;
            }
        }
    }
};*/

bool Ablak::gyoztes(int jatekos){
const int meret = 15;
const int nyer  = 5;

for (int i = 0; i < meret; ++i) {
    for (int j = 0; j <= meret - nyer; ++j) {
        bool gyoz = true;
        for (int k = 0; k < nyer; ++k) {
            if (xx[i][j + k] != jatekos) {
                gyoz = false;
                break;
            }
        }
        if (gyoz) return true;
    }
}

for (int j = 0; j < meret; ++j) {
    for (int i = 0; i <= meret - nyer; ++i) {
        bool gyoz = true;
        for (int k = 0; k < nyer; ++k) {
            if (xx[i + k][j] != jatekos) {
                gyoz = false;
                break;
            }
        }
        if (gyoz) return true;
    }
}

for (int i = 0; i <= meret - nyer; ++i) {
    for (int j = 0; j <= meret - nyer; ++j) {
        bool gyoz = true;
        for (int k = 0; k < nyer; ++k) {
            if (xx[i + k][j + k] != jatekos) {
                gyoz = false;
                break;
            }
        }
        if (gyoz) return true;
    }
}
for (int i = nyer - 1; i < meret; ++i) {
    for (int j = 0; j <= meret - nyer; ++j) {
        bool gyoz = true;
        for (int k = 0; k < nyer; ++k) {
            if (xx[i - k][j + k] != jatekos) {
                gyoz = false;
                break;
            }
        }
        if (gyoz) return true;
    }
}
return false;
};

