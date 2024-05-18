#include "ablak.hpp"
#include <iostream>
#include <vector>
#include "oswid.hpp"
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
while(gin >> ev ) {
    if (ev.type == ev_mouse && ev.button == -btn_left) {
        for (int i = 0; i < c.size();i++) {
            if (c[i]->aktiv(ev.pos_x, ev.pos_y)) {
                akt = i;
                x.push_back(c[akt]->adat());
                x.push_back(c[akt]->adat2());
                xx[c[i]->adat()][c[i]->adat2()] = 1;
            }
        }
    }
    if (akt!=-1) {
        c[akt]->futas(ev);
    }
    /*if(ev.keycode == ' '){
        adat.clear();
        for (Oswid * w : c) {
            adat.push_back(w->adat());
        }
    }*/
    for (Oswid * w : c) {
        w->rajz();
    }
    gout << refresh;
};

ofstream ofs("ki.txt");
for(int i  = 0; i<x.size();i++){
    ofs << x[i] << endl;
}

/*for(int a = 0; a<15;a++){{
        for(int b = 0;b<15;b++){
            ofs << xx[a][b] << " ";
        }
        ofs << endl;
    }
}*/
ofs.close();
};
int Ablak::ertekAtadas(){
    int meret = 0;
    for(int a = 0; a<15;a++){{
            for(int b = 0;b<15;b++){
                if(xx[a][b] ==1){
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

