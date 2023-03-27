#include "uklad_wsp.hh"


uklad_wspolrzednych::uklad_wspolrzednych(Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic)
: wskaznik_na_poprzedniego(rodzic),
srodek (_srodek),
orientacja (_orientacja)
{}


void uklad_wspolrzednych::translacja (Wektor<3> nowy)
{
    srodek = srodek + nowy;
}


void uklad_wspolrzednych::rotacja (Macierz_obrotu<3> nowa)
{
    orientacja = orientacja * nowa;
}


uklad_wspolrzednych uklad_wspolrzednych::przelicz_uklad_do_dziadka()
{
    if (wskaznik_na_poprzedniego == nullptr)
    {
        return *this;                       // jesli jestesmy w ukl dziadka to nic nie robimy
    }
    else
    {
        Wektor<3> srodek_w_dziadku = wskaznik_na_poprzedniego->srodek + srodek;      
        Macierz_obrotu<3> orientacja_w_dziadku = wskaznik_na_poprzedniego->orientacja * orientacja;
        return uklad_wspolrzednych(srodek_w_dziadku, orientacja_w_dziadku, wskaznik_na_poprzedniego->wskaznik_na_poprzedniego);
    }
}


Wektor<3> uklad_wspolrzednych::przelicz_punkt_do_rodzica (Wektor<3> punkt)
{
    return srodek + (orientacja * punkt);
}           

Wektor<3> uklad_wspolrzednych::przelicz_punkt_do_globalnego (Wektor<3> w)
{
    uklad_wspolrzednych* biezacy = this;
    while(biezacy->wskaznik_na_poprzedniego != nullptr)
    {
        w = biezacy->przelicz_punkt_do_rodzica(w);
        biezacy = biezacy->wskaznik_na_poprzedniego;
    }
    return w;
}