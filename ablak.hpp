#ifndef ABLAK_HPP
#define ABLAK_HPP
#include <vector>
class Oswid;
class Ablak{
private:
public:
    std::vector<Oswid*> c;
public:
    void megy();
    Ablak(int X,int Y);
    void add_wid(Oswid * _ablak){c.push_back(_ablak);}
    int ertekAtadas();
    bool gyoztes(int jatekos);
    bool teli();
};



#endif // ABLAK_HPP
