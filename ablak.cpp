#include <iostream>
#include <fstream>
#include <vector>
#include "oswid.hpp"
#include "graphics.hpp"
#include "ablak.hpp"

using namespace std;
using namespace genv;

vector<int> adat;
vector<vector<int>> xx(15, vector<int>(15, 0));

Ablak::Ablak(int X, int Y) {
    gout.open(X, Y);
    gout << move_to(0, 0) << color(10, 141, 237) << box(X, Y);
}

void Ablak::megy() {
    gin.timer(30);
    event ev;
    int akt = -1;
    int meret = 0;
    while (gin >> ev) {
        if (!teli() && !gyoztes(1) && !gyoztes(2)) {
            if (ev.type == ev_mouse && ev.button == btn_left) {
                for (size_t i = 0; i < c.size(); i++) {
                    if (c[i]->aktiv(ev.pos_x, ev.pos_y)) {
                        akt = i;
                        meret++;
                    }
                }
                if (meret % 2 == 0) {
                    xx[c[akt]->adat2()][c[akt]->adat()] = 1;
                } else {
                    xx[c[akt]->adat2()][c[akt]->adat()] = 2;
                }
            }
            if (akt != -1) {
                c[akt]->futas(ev);
            }

            for (Oswid* w : c) {
                w->rajz();
            }
            gout << refresh;
        }
    }

    ofstream ofs("ki.txt");
    for (int a = 0; a < 15; a++) {
        for (int b = 0; b < 15; b++) {
            ofs << xx[a][b] << " ";
        }
        ofs << endl;
    }
    ofs.close();
}

int Ablak::ertekAtadas() {
    int meret = 0;
    for (int a = 0; a < 15; a++) {
        for (int b = 0; b < 15; b++) {
            if (xx[a][b] != 0) {
                meret++;
            }
        }
    }
    if (meret % 2 == 0) {
        return 1;
    } else {
        return 2;
    }
}

bool Ablak::teli() {
    int db = 0;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            if (xx[i][j] != 0) {
                db++;
            }
        }
    }
    return db == 15 * 15;
}

bool Ablak::gyoztes(int jatekos) {
    const int meret = 15;
    const int nyer = 5;

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
    for (int i = nyer - 1; i < meret; ++i) {
        for (int j = 0; j <= meret - nyer; ++j) {
            bool gyoz = true;
            for (int k = 0; k < nyer; ++k) {
                if (xx[i + k][j - k] != jatekos) {
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
                if (xx[i - k][j - k] != jatekos) {
                    gyoz = false;
                    break;
                }
            }
            if (gyoz) return true;
        }
    }
    return false;
}
