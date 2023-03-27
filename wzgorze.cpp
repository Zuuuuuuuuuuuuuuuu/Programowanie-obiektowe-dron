#include "wzgorze.hh"
#include <iostream>


Wzgorze::Wzgorze(drawNS::Draw3DAPI * _rysownik, double _wysokosc, uint _liczba_wierzcholkow_podstawy, double _promien, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic)
: Inter_rys {_rysownik},
uklad_wspolrzednych {_srodek, _orientacja, rodzic},
liczba_wierzcholkow_podstawy { _liczba_wierzcholkow_podstawy},
wysokosc {_wysokosc},
promien (_promien)
{}

Wzgorze::Wzgorze(drawNS::Draw3DAPI * _rysownik, double _wysokosc, double _promien, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic)
: Inter_rys {_rysownik},
uklad_wspolrzednych {_srodek, _orientacja, rodzic},
wysokosc {_wysokosc},
promien (_promien)
{
    std::random_device rd;                                     // tutaj tez losowanie ile wierzcholkow od 3 do 9
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(3,9);
    liczba_wierzcholkow_podstawy = distribution (gen);
}

void Wzgorze::zmaz()
{
    rysownik->erase_shape(this->get_id());
}

void Wzgorze::rysuj()                                          // analogicznie jak w plaskowyzu
{
    std::vector<Wektor<3>> wierzcholki_podstawy;               //we wlasnym ukl wsp 
    const double alfa = 360/liczba_wierzcholkow_podstawy;
    const Wektor<3> r0 {{promien, 0, 0}};
    Wektor<3> wierzcholek_gorny {{0, 0, wysokosc}};
    for (uint i=0; i<liczba_wierzcholkow_podstawy; ++i)
    {
        wierzcholki_podstawy.push_back(Macierz_obrotu<3>(alfa*i, "z")*r0);
    }
    
    for (auto & w : wierzcholki_podstawy)
    {
        w = przelicz_punkt_do_globalnego(w);
    }
    
    wierzcholek_gorny = przelicz_punkt_do_globalnego(wierzcholek_gorny);
    
    std::vector<std::vector<drawNS::Point3D>> punkty_rys;
    for(uint i = 0; i < liczba_wierzcholkow_podstawy; ++i)
    {
        std::vector<drawNS::Point3D> surface;
        surface.push_back(konwertuj(wierzcholki_podstawy[i]));
        surface.push_back(konwertuj(wierzcholki_podstawy[(i+1)%liczba_wierzcholkow_podstawy]));
        surface.push_back(konwertuj(wierzcholek_gorny));
        punkty_rys.push_back(surface);
    }
    id = rysownik->draw_polyhedron(punkty_rys, "green");
}
    