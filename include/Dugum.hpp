/*
* @file..........: Dugum.hpp
* @description...: Düğümler zincirleme yapı oluşturmak için sonraki düğüme işaret eder.
* @course........: 2-A
* @assignment....: 2. Ödev
* @date..........: 08.12.2024
* @author........: Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#ifndef Dugum_hpp
#define Dugum_hpp

#include <string>
#include "IkiliAgacDugumu.hpp"
using namespace std;

// Dugum sınıfı, bir bağlı liste yapısı içinde düğümleri temsil eder.
class Dugum {
public:
    string adres;      // Düğümün adresini tutar.
    int asciiToplam;   // ASCII karakter toplamını saklar.
    Dugum* sonraki;    // Bir sonraki düğüme işaret eder.
    IkiliAgacDugumu* kok; // İkili ağacın kökünü saklar.

    // Yapıcı fonksiyon
    Dugum(const string& adr, int toplam);
};

#endif
