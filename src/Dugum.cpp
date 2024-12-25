/*
* @file..........: Dugum.cpp
* @description...: Bu dosya, Dugum sınıfının uygulama detaylarını içerir. Düğümler, adres, ASCII toplamı ve bağlı liste yapısı için sonraki düğümü yönetir.
* @course........: 2-A
* @assignment....: 2. Ödev
* @date..........: 08.12.2024
* @author........: Melih Can Şengün melih.sengun@ogr.sakarya.edu.tr
*/

#include "Dugum.hpp"

// Yapıcı fonksiyon
Dugum::Dugum(const string& adr, int toplam)
    : adres(adr), asciiToplam(toplam), sonraki(0), kok(0)
{
}
