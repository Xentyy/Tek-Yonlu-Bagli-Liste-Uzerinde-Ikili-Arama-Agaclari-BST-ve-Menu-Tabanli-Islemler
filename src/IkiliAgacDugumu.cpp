/*
* @file..........: IkiliAgacDugumu.cpp
* @description...: Bu dosya, IkiliAgacDugumu sınıfının uygulama detaylarını içerir. İkili ağaç düğümleri, veri ve çocuk düğüm işaretçilerini yönetir.
* @course........: 2-A
* @assignment....: 2. Ödev
* @date..........: 08.12.2024
* @author........: Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#include "IkiliAgacDugumu.hpp"

// Yapıcı fonksiyon.
IkiliAgacDugumu::IkiliAgacDugumu(char ch) : veri(ch), sol(0), sag(0) {}
