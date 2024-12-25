/*
* @file..........: Kuyruk.hpp
* @description...: Kuyruk yapısı, ikili ağaç düğümlerini saklamak ve işlem sırasına göre yönetmek için kullanılır.
* @course........: 2-A
* @assignment....: 2. Ödev
* @date..........: 08.12.2024
* @author........: Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#ifndef Kuyruk_hpp
#define Kuyruk_hpp

#include "IkiliAgacDugumu.hpp"

class Kuyruk {
private:
    struct KuyrukDugumu {
        IkiliAgacDugumu* agacDugumu; // Kuyrukta saklanan ikili ağaç düğümü.
        KuyrukDugumu* sonraki;       // Sonraki kuyruk düğümüne işaretçi.

        // Yapıcı fonksiyon.
        KuyrukDugumu(IkiliAgacDugumu* dugum) : agacDugumu(dugum), sonraki(0) {}
    };

    KuyrukDugumu* on;  // Kuyruğun önündeki düğüm.
    KuyrukDugumu* arka; // Kuyruğun arkasındaki düğüm.

public:
    Kuyruk();
    ~Kuyruk();
    void Ekle(IkiliAgacDugumu* dugum);
    IkiliAgacDugumu* Cikar();
    bool BosMu() const;
};

#endif
