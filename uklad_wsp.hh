#ifndef UKLAD_WSP_HH
#define UKLAD_WSP_HH
#include "wektor.hh"
#include "macierz.hh"

class uklad_wspolrzednych
{
    protected:
        uklad_wspolrzednych *wskaznik_na_poprzedniego;     //nullptr to uklad globalny
        Wektor<3> srodek;
        Macierz_obrotu<3> orientacja;
    public:
        uklad_wspolrzednych()=default;
        uklad_wspolrzednych(Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic);
        void translacja (Wektor<3> nowy);
        void rotacja (Macierz_obrotu<3> nowa);
        uklad_wspolrzednych przelicz_uklad_do_dziadka();
        Wektor<3> przelicz_punkt_do_rodzica (Wektor<3> W);
        Wektor<3> przelicz_punkt_do_globalnego (Wektor<3> W);
};

#endif