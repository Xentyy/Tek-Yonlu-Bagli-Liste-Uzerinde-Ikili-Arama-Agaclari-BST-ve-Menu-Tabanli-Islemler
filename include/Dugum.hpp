// Dugum.hpp
#ifndef Dugum_hpp
#define Dugum_hpp

#include <string>
#include "IkiliAgacDugumu.hpp"
using namespace std;

class Dugum {
public:
    string adres;      // Adresi string olarak saklayacağız
    int asciiToplam;
    Dugum* sonraki;
    IkiliAgacDugumu* kok;

    Dugum(const string& adr, int toplam);
};

#endif
