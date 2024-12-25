#ifndef AgacYoneticisi_hpp
#define AgacYoneticisi_hpp

#include <string>
#include "Dugum.hpp"
#include "Kuyruk.hpp"

class AgacYoneticisi {
private:
    Dugum* bas;  // Tek yönlü listede baş düğüm
    Dugum* son;  // Ekleme kolaylığı için son düğümü tutuyoruz

    static int maks(int a, int b);
    IkiliAgacDugumu* BSTEkle(IkiliAgacDugumu* dugum, char ch);
    int YukseklikAl(IkiliAgacDugumu* dugum) const;
    void BSTSil(IkiliAgacDugumu* dugum);
    int DuzenlenmisAsciiToplamYardimci(IkiliAgacDugumu* dugum, bool solCocukMu);
    int DuzenlenmisAsciiToplam(IkiliAgacDugumu* kok);

public:
    AgacYoneticisi();
    ~AgacYoneticisi();

    void DosyadanAgacOlustur(const std::string& dosyaAdi);

    // Tek yönlü listede düğüm silme
    Dugum* MevcutDugumuSil(Dugum* mevcutDugum);

    void BSTAynala(IkiliAgacDugumu* kok);
    void DugumAsciiToplamiGuncelle(Dugum* dugum);

    int DugumSayisi() const;
    int DugumIndeksi(Dugum* mevcutDugum) const;

    void AgacYazdir(Dugum* mevcutDugum) const;
    void IkiliAgacCiz(IkiliAgacDugumu* kok) const;

    Dugum* BasGetir() const;
    Dugum* SonGetir() const;

    // Geri gitmede kullanmak için yardımcı fonksiyon:
    Dugum* OncekiDugumuBul(Dugum* mevcut) const;
};

#endif