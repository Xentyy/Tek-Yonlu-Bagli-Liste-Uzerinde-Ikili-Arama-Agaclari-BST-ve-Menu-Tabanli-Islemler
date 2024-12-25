/*
* @file..........: AgacYoneticisi.hpp
* @description...: İkili arama ağaçları üzerinde çeşitli işlemler yaparak düğümleri yönetir.
* @course........: 2-A
* @assignment....: 2. Ödev
* @date..........: 08.12.2024
* @author........: Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#ifndef AgacYoneticisi_hpp
#define AgacYoneticisi_hpp

#include <string>
#include "Dugum.hpp"
#include "Kuyruk.hpp"

class AgacYoneticisi {
private:
    Dugum* bas; // Ağacın baş düğümünü tutar.
    Dugum* son; // Ağacın son düğümünü tutar.

    // Kaynak sınıfındaki fonksiyonların imzalarını tutuyoruz.

    static int maks(int a, int b);
    IkiliAgacDugumu* BSTEkle(IkiliAgacDugumu* dugum, char ch);
    int YukseklikAl(IkiliAgacDugumu* dugum) const;
    void BSTSil(IkiliAgacDugumu* dugum);
    int DuzenlenmisAsciiToplamYardimci(IkiliAgacDugumu* dugum, bool solCocukMu);
    int DuzenlenmisAsciiToplam(IkiliAgacDugumu* kok);

public:
    AgacYoneticisi();
    ~AgacYoneticisi();
    void DosyadanAgacOlustur(const string& dosyaAdi);
    Dugum* MevcutDugumuSil(Dugum* mevcutDugum);
    void BSTAynala(IkiliAgacDugumu* kok);
    void DugumAsciiToplamiGuncelle(Dugum* dugum);
    int DugumSayisi() const;
    int DugumIndeksi(Dugum* mevcutDugum) const;
    void AgacYazdir(Dugum* mevcutDugum) const;
    void IkiliAgacCiz(IkiliAgacDugumu* kok) const;
    Dugum* BasGetir() const;
    Dugum* SonGetir() const;
    Dugum* OncekiDugumuBul(Dugum* mevcut) const;
};

#endif
