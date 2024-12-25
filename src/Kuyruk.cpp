/*
* @file..........: Kuyruk.cpp
* @description...: Bu dosya, Kuyruk sınıfının uygulama detaylarını içerir. Kuyruk yapısı, ikili ağaç düğümlerini FIFO (İlk Giren İlk Çıkar) mantığı ile yönetir.
* @course........: 2-A
* @assignment....: 2. Ödev
* @date..........: 08.12.2024
* @author........: Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#include "Kuyruk.hpp"

// Yapıcı fonksiyon.
Kuyruk::Kuyruk() : on(0), arka(0) {}

// Yıkıcı fonksiyon: Kuyruğu temizler ve belleği serbest bırakır.
Kuyruk::~Kuyruk() {
    while (on) {
        KuyrukDugumu* gecici = on;
        on = on->sonraki;
        delete gecici;
    }
}

void Kuyruk::Ekle(IkiliAgacDugumu* dugum) {
    KuyrukDugumu* yeniDugum = new KuyrukDugumu(dugum);
    if (!arka) {
        on = arka = yeniDugum; // Kuyruk boşsa, yeni düğüm baş ve arka olur.
    } else {
        arka->sonraki = yeniDugum; // Kuyruğun sonuna ekler.
        arka = yeniDugum;
    }
}

IkiliAgacDugumu* Kuyruk::Cikar() {
    if (!on) return 0; // Kuyruk boşsa, null döndür.
    KuyrukDugumu* gecici = on;
    IkiliAgacDugumu* d = gecici->agacDugumu;
    on = on->sonraki;
    if (!on) arka = 0; // Kuyruk boşaldıysa, arka da sıfırlanır.
    delete gecici;
    return d;
}

bool Kuyruk::BosMu() const {
    return on == 0; // Ön işaretçi sıfırsa, kuyruk boştur.
}
