#ifndef Kuyruk_hpp
#define Kuyruk_hpp

#include "IkiliAgacDugumu.hpp"

class Kuyruk {
private:
    struct KuyrukDugumu {
        IkiliAgacDugumu* agacDugumu;
        KuyrukDugumu* sonraki;
        KuyrukDugumu(IkiliAgacDugumu* dugum) : agacDugumu(dugum), sonraki(0) {}
    };

    KuyrukDugumu* on;
    KuyrukDugumu* arka;

public:
    Kuyruk();
    ~Kuyruk();
    void Ekle(IkiliAgacDugumu* dugum);
    IkiliAgacDugumu* Cikar();
    bool BosMu() const;
};

#endif
