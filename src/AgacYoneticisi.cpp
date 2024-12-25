/*
* @file..........: AgacYoneticisi.cpp
* @description...: Bu dosya, AgacYoneticisi sınıfının uygulama detaylarını içerir. İkili arama ağaçları üzerinde ekleme, silme, yükseklik hesaplama, aynalama ve ASCII toplamları gibi işlemler gerçekleştirilir.
* @course........: 2-A
* @assignment....: 2. Ödev
* @date..........: 08.12.2024
* @author........: Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include "AgacYoneticisi.hpp"
using namespace std;

// İki sayı arasında maksimum değeri döndürür
int AgacYoneticisi::maks(int a, int b) {
    return (a > b) ? a : b;
}

// İkili ağaç düğümüne veri ekler.
IkiliAgacDugumu* AgacYoneticisi::BSTEkle(IkiliAgacDugumu* dugum, char ch) {
    if (!dugum) return new IkiliAgacDugumu(ch);
    if (ch < dugum->veri)
        dugum->sol = BSTEkle(dugum->sol, ch);
    else
        dugum->sag = BSTEkle(dugum->sag, ch);
    return dugum;
}

// İkili ağacın yüksekliğini hesaplar.
int AgacYoneticisi::YukseklikAl(IkiliAgacDugumu* dugum) const {
    if (!dugum) return 0;
    int solY = YukseklikAl(dugum->sol);
    int sagY = YukseklikAl(dugum->sag);
    return maks(solY, sagY) + 1;
}

// İkili ağacı siler ve bellekten temizler.
void AgacYoneticisi::BSTSil(IkiliAgacDugumu* dugum) {
    if (!dugum) return;
    BSTSil(dugum->sol);
    BSTSil(dugum->sag);
    delete dugum;
}

// ASCII toplamlarını hesaplamak için yardımcı fonksiyon.
int AgacYoneticisi::DuzenlenmisAsciiToplamYardimci(IkiliAgacDugumu* dugum, bool solCocukMu) {
    if (!dugum) return 0;
    int deger = (int)dugum->veri;
    if (solCocukMu) deger *= 2;
    return deger
        + DuzenlenmisAsciiToplamYardimci(dugum->sol, true)
        + DuzenlenmisAsciiToplamYardimci(dugum->sag, false);
}

// Kök düğüm üzerinden ASCII toplamını hesaplar.
int AgacYoneticisi::DuzenlenmisAsciiToplam(IkiliAgacDugumu* kok) {
    return DuzenlenmisAsciiToplamYardimci(kok, false);
}

// Yapıcı fonksiyon: Sınıfın başlangıç değerlerini atar.
AgacYoneticisi::AgacYoneticisi() : bas(0), son(0) {}

// Yıkıcı fonksiyon: Bellekteki kaynakları serbest bırakır.
AgacYoneticisi::~AgacYoneticisi() {
    Dugum* temp = bas;
    while (temp) {
        Dugum* sonrakiDugum = temp->sonraki;
        BSTSil(temp->kok);
        delete temp;
        temp = sonrakiDugum;
    }
    bas = 0;
    son = 0;
}

// Dosyadan veri okuyarak ikili ağaçlar oluşturur.
void AgacYoneticisi::DosyadanAgacOlustur(const string& dosyaAdi) {
    ifstream dosya(dosyaAdi.c_str());
    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi: " << dosyaAdi << endl;
        return;
    }

    string satir;
    while (getline(dosya, satir)) {
        Dugum* yeniDugum = new Dugum("", 0);
        uintptr_t ptrValue = reinterpret_cast<uintptr_t>(yeniDugum);
        int kisaAdres = static_cast<int>(ptrValue % 10000);
        yeniDugum->adres = to_string(kisaAdres);
        IkiliAgacDugumu* kok = 0;
        for (size_t i = 0; i < satir.size(); i++) {
            kok = BSTEkle(kok, satir[i]);
        }
        yeniDugum->kok = kok;
        if (kok) {
            yeniDugum->asciiToplam = DuzenlenmisAsciiToplam(kok);
        }
        if (!bas) {
            bas = son = yeniDugum;
        }
        else {
            son->sonraki = yeniDugum;
            son = yeniDugum;
        }
    }
    dosya.close();
}

// Mevcut düğümü siler ve belleği temizler.
Dugum* AgacYoneticisi::MevcutDugumuSil(Dugum* mevcutDugum) {
    if (!mevcutDugum) return 0;
    BSTSil(mevcutDugum->kok);
    if (bas == mevcutDugum) {
        bas = bas->sonraki;

        if (!bas) son = 0;
        delete mevcutDugum;
        return bas;
    }
    Dugum* onceki = OncekiDugumuBul(mevcutDugum);
    if (onceki) {
        onceki->sonraki = mevcutDugum->sonraki;
        if (mevcutDugum == son) {
            son = onceki;
        }
    }

    Dugum* sonraki = mevcutDugum->sonraki;
    delete mevcutDugum;
    return (sonraki ? sonraki : onceki);
}

// Üzerinde bulunan düğümün bir öncekş düğümünü bulur. Bulamazsa temp en son null olur
Dugum* AgacYoneticisi::OncekiDugumuBul(Dugum* mevcut) const {
    if (!mevcut || mevcut == bas) return 0;

    Dugum* temp = bas;
    while (temp && temp->sonraki != mevcut) {
        temp = temp->sonraki;
    }
    return temp;
}

// Aynalama gorevini yapar
void AgacYoneticisi::BSTAynala(IkiliAgacDugumu* kok) {
    if (!kok) return;
    IkiliAgacDugumu* gecici = kok->sol;
    kok->sol = kok->sag;
    kok->sag = gecici;

    BSTAynala(kok->sol);
    BSTAynala(kok->sag);
}

// Verilen toplama görevini doğru bir şekilde yapar
void AgacYoneticisi::DugumAsciiToplamiGuncelle(Dugum* dugum) {
    if (dugum && dugum->kok) {
        dugum->asciiToplam = DuzenlenmisAsciiToplam(dugum->kok);
    }
    else if (dugum) {
        dugum->asciiToplam = 0;
    }
}

// Toplam düğüm sayısını bulur
int AgacYoneticisi::DugumSayisi() const {
    int sayac = 0;
    Dugum* temp = bas;
    while (temp) {
        sayac++;
        temp = temp->sonraki;
    }
    return sayac;
}

int AgacYoneticisi::DugumIndeksi(Dugum* mevcutDugum) const {
    int indeks = 0;
    Dugum* temp = bas;
    while (temp) {
        if (temp == mevcutDugum) return indeks;
        indeks++;
        temp = temp->sonraki;
    }
    return -1;
}

// Düğümlerin bulunduğu bağlı liste şeklini ekrana yazdırır.
void AgacYoneticisi::AgacYazdir(Dugum* mevcutDugum) const {
    if (!mevcutDugum) {
        cout << "Listede hic dugum kalmadi.\n";
        return;
    }

    int toplamDugum = DugumSayisi();
    if (toplamDugum == 0) {
        cout << "Listede hic dugum kalmadi.\n";
        return;
    }

    Dugum** dugumDizisi = new Dugum*[toplamDugum];
    {
        Dugum* temp = bas;
        int idx = 0;
        while (temp) {
            dugumDizisi[idx] = temp;
            temp = temp->sonraki;
            idx++;
        }
    }

    int mevcutIndeks = DugumIndeksi(mevcutDugum);
    if (mevcutIndeks == -1) {
        cout << "Mevcut dugum listede bulunamadi.\n";
        delete[] dugumDizisi;
        return;
    }

    int sayfaDugum = 10;
    int sayfaIndeks = mevcutIndeks / sayfaDugum;
    int baslangic = sayfaIndeks * sayfaDugum;
    int bitis = baslangic + sayfaDugum - 1;
    if (bitis >= toplamDugum) {
        bitis = toplamDugum - 1;
    }

    for (int i = baslangic; i <= bitis; i++) {
        cout << "**********   ";
    }
    cout << "\n";

    for (int i = baslangic; i <= bitis; i++) {
        cout << "* " << setw(5) << dugumDizisi[i]->adres << "  *   ";
    }
    cout << "\n";

    for (int i = baslangic; i <= bitis; i++) {
        cout << "**********   ";
    }
    cout << "\n";

    for (int i = baslangic; i <= bitis; i++) {
        cout << "* " << setw(5) << dugumDizisi[i]->asciiToplam << "  *   ";
    }
    cout << "\n";

    for (int i = baslangic; i <= bitis; i++) {
        cout << "**********   ";
    }
    cout << "\n";

    for (int i = baslangic; i <= bitis; i++) {
        if (dugumDizisi[i]->sonraki) {
            cout << "* " << setw(5) << dugumDizisi[i]->sonraki->adres << "  *   ";
        }
        else {
            cout << "* " << setw(5) << "0" << "  *   ";
        }
    }
    cout << "\n";

    for (int i = baslangic; i <= bitis; i++) {
        cout << "**********   ";
    }
    cout << "\n";

    for (int i = baslangic; i <= bitis; i++) {
        if (dugumDizisi[i] == mevcutDugum) {
            cout << "^^^^^^^^^^     ";
        }
        else {
            cout << "             ";
        }
    }
    cout << "\n";

    for (int i = baslangic; i <= bitis; i++) {
        if (dugumDizisi[i] == mevcutDugum) {
            cout << "||||||||||     ";
        }
        else {
            cout << "             ";
        }
    }
    cout << "\n";

    delete[] dugumDizisi;

    cout << "\n";
    IkiliAgacCiz(mevcutDugum->kok);
}

// İkili arama ağacını ekrana çizdirir.
void AgacYoneticisi::IkiliAgacCiz(IkiliAgacDugumu* kok) const {
    if (!kok) {
        cout << "Ağaç boş.\n";
        return;
    }

    int yukseklik = YukseklikAl(kok);
    Kuyruk q;
    q.Ekle(kok);

    int maksGenislik = (1 << yukseklik) - 1;

    for (int seviye = 0; seviye < yukseklik; ++seviye) {
        int dugumSayisi = (1 << seviye);
        int bosluk = maksGenislik / dugumSayisi;

        IkiliAgacDugumu** seviyeDizisi = new IkiliAgacDugumu*[dugumSayisi];
        for (int i = 0; i < dugumSayisi; i++) {
            seviyeDizisi[i] = 0;
        }

        for (int i = 0; i < dugumSayisi; ++i) {
            IkiliAgacDugumu* dugum = 0;
            if (!q.BosMu()) {
                dugum = q.Cikar();
            }

            seviyeDizisi[i] = dugum;

            if (i == 0) {
                for (int s = 0; s < bosluk / 2; s++) cout << ' ';
            } else {
                for (int s = 0; s < bosluk; s++) cout << ' ';
            }

            if (dugum) {
                cout << dugum->veri;
                q.Ekle(dugum->sol);
                q.Ekle(dugum->sag);
            } else {
                cout << ' ';
                q.Ekle(0);
                q.Ekle(0);
            }
        }
        cout << "\n";

        // Bağlantı çizgileri
        if (seviye < yukseklik - 1) {
            int baglantiBosluk = bosluk / 2;

            for (int i = 0; i < dugumSayisi; ++i) {
                if (i == 0) {
                    for (int s = 0; s < baglantiBosluk / 2; s++) cout << ' ';
                } else {
                    for (int s = 0; s < baglantiBosluk; s++) cout << ' ';
                }

                IkiliAgacDugumu* dugum = seviyeDizisi[i];
                // Eğer düğüm varsa ve en az bir çocuğu varsa bağlantı çiz
                if (dugum && (dugum->sol || dugum->sag)) {
                    cout << "*";
                    for (int s = 0; s < baglantiBosluk - 1; s++) cout << '*';
                    cout << "*";
                } else {
                    for (int s = 0; s < baglantiBosluk + 1; s++) cout << ' ';
                }
            }
            cout << "\n";
        }

        delete[] seviyeDizisi;
    }
}

Dugum* AgacYoneticisi::BasGetir() const { return bas; }
Dugum* AgacYoneticisi::SonGetir() const { return son; }