#include "dron.hh"

namespace                           // zdefiniowanie stalych rozmiarow drona
{
    constexpr double korpus_szerokosc = 50;
    constexpr double korpus_wysokosc = 30;
    constexpr double korpus_dlugosc = 60;
    constexpr double wirniki_promien = 20;
    constexpr double wirniki_wysokosc = 15;
}

//konstruktor z dopasowanymi wymiarami 
Dron::Dron (Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, drawNS::Draw3DAPI *rysownik, uklad_wspolrzednych* rodzic)
: uklad_wspolrzednych(_srodek, _orientacja, rodzic),
Inter_rys(rysownik),
korpus (rysownik, korpus_dlugosc, korpus_szerokosc, korpus_wysokosc, Wektor<3> ({0,0,0}), Macierz_obrotu<3>(), this),
wirniki {Graniastoslup6{wirniki_wysokosc, wirniki_promien, Wektor<3>({-0.5*korpus_dlugosc, -0.5*korpus_szerokosc, 0.5*korpus_wysokosc}), {}, this},
        {Graniastoslup6{wirniki_wysokosc, wirniki_promien, Wektor<3>({-0.5*korpus_dlugosc, 0.5*korpus_szerokosc, 0.5*korpus_wysokosc}), {}, this}},
        {Graniastoslup6{wirniki_wysokosc, wirniki_promien, Wektor<3>({0.5*korpus_dlugosc, 0.5*korpus_szerokosc, 0.5*korpus_wysokosc}), {}, this}},
        {Graniastoslup6{wirniki_wysokosc, wirniki_promien, Wektor<3>({0.5*korpus_dlugosc, -0.5*korpus_szerokosc, 0.5*korpus_wysokosc}), {}, this}}}
{}


void Dron::rysuj()
{
    korpus.rysuj();
    for ( auto & wirnik : wirniki)
    {
        wirnik.rysuj(rysownik);
    }
}


void Dron::zmaz()
{
    rysownik->erase_shape(korpus.get_id());
    for ( auto & wirnik : wirniki)
    {
        rysownik->erase_shape(wirnik.get_id());
    }
}


void Dron::podnies (double wysokosc)
{
    translacja(Wektor<3>({0, 0, wysokosc}));
}


void Dron::lec_do_przodu (double ile)
{
    translacja(orientacja*Wektor<3>({ile, 0, 0}));      //wzdluz swojego ukladu wsp
}


void Dron::obroc (double kat /*os Z */)
{
    rotacja(Macierz_obrotu<3>({kat, "z"}));
}


void Dron::porusz_wirnikami ()
 {
    for (auto & wirnik : wirniki)
    {
        wirnik.rotacja(Macierz_obrotu<3>({30, "z"}));       //kat dobrany do liczby klatek na razie
    }
 }