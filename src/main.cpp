#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AgacYoneticisi.hpp"

using namespace std;

int main() {
    srand(time(0));

    AgacYoneticisi yonetici;
    yonetici.DosyadanAgacOlustur("agaclar.txt");

    Dugum* mevcutDugum = yonetici.BasGetir();

    char komut;
    do {
        system("cls");   // Windows

        yonetici.AgacYazdir(mevcutDugum);

        cout << "\n(D) Ileri, (A) Geri, (S) Sil, (W) Aynala, (Q) Cikis: ";
        cin >> komut;

        if ((komut == 'D' || komut == 'd') && mevcutDugum && mevcutDugum->sonraki) {
            // Ileri git
            mevcutDugum = mevcutDugum->sonraki;
        }
        else if ((komut == 'A' || komut == 'a')) {
            // Geri gitmek için liste başından tara
            Dugum* onceki = yonetici.OncekiDugumuBul(mevcutDugum);
            if (onceki) {
                mevcutDugum = onceki;
            }
            // onceki null ise zaten bas'tayız, geri gidemeyiz
        }
        else if ((komut == 'S' || komut == 's') && mevcutDugum) {
            // Mevcut düğümü sil
            mevcutDugum = yonetici.MevcutDugumuSil(mevcutDugum);
            if (!mevcutDugum) {
                cout << "Listede hic dugum kalmadi, cikiliyor...\n";
                break;
            }
        }
        else if ((komut == 'W' || komut == 'w') && mevcutDugum) {
            // Aynalama
            yonetici.BSTAynala(mevcutDugum->kok);
            yonetici.DugumAsciiToplamiGuncelle(mevcutDugum);
        }

    } while (komut != 'Q' && komut != 'q');

    return 0;
}
