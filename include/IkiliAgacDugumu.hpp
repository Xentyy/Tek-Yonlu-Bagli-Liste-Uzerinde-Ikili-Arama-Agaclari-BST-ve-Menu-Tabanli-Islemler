/*
* @file..........: IkiliAgacDugumu.hpp
* @description...: İkili ağaç düğümleri, bir veri, sol ve sağ çocuk düğümlere işaretçileri içerir.
* @course........: 2-A
* @assignment....: 2. Ödev
* @date..........: 08.12.2024
* @author........: Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#ifndef IkiliAgacDugumu_hpp
#define IkiliAgacDugumu_hpp

// IkiliAgacDugumu sınıfı, ikili arama ağacı düğümünü temsil eder.
class IkiliAgacDugumu {
public:
    char veri;                     // Düğümün içeriği (veri).
    IkiliAgacDugumu* sol;          // Sol çocuk düğümüne işaretçi.
    IkiliAgacDugumu* sag;          // Sağ çocuk düğümüne işaretçi.

    // Yapıcı fonksiyon.
    IkiliAgacDugumu(char ch);
};

#endif
