#include "Kuyruk.hpp"

Kuyruk::Kuyruk() : on(0), arka(0) {}

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
        on = arka = yeniDugum;
    } else {
        arka->sonraki = yeniDugum;
        arka = yeniDugum;
    }
}

IkiliAgacDugumu* Kuyruk::Cikar() {
    if (!on) return 0;
    KuyrukDugumu* gecici = on;
    IkiliAgacDugumu* d = gecici->agacDugumu;
    on = on->sonraki;
    if (!on) arka = 0;
    delete gecici;
    return d;
}

bool Kuyruk::BosMu() const {
    return on == 0;
}
