#include "plaskowyz.hh"
#include <iostream>


Plaskowyz::Plaskowyz(drawNS::Draw3DAPI * _rysownik, double _wysokosc, uint _liczba_wierzcholkow, double _promien, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic)
: Inter_rys {_rysownik},
uklad_wspolrzednych {_srodek, _orientacja, rodzic},
liczba_wierzcholkow { _liczba_wierzcholkow},
wysokosc {_wysokosc},
promien (_promien)
{}

Plaskowyz::Plaskowyz(drawNS::Draw3DAPI * _rysownik, double _wysokosc, double _promien, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic)
: Inter_rys {_rysownik},
uklad_wspolrzednych {_srodek, _orientacja, rodzic},
liczba_wierzcholkow{0},
wysokosc {_wysokosc},
promien (_promien)
{
    std::random_device rd;                                      //losowanie liczby wierzcholkow od 3 do 9
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(3,9);
    liczba_wierzcholkow = distribution (gen);
}

void Plaskowyz::zmaz()
{
    rysownik->erase_shape(this->get_id());
}

void Plaskowyz::rysuj()
{
    std::vector<Wektor<3>> wierzcholkiA;     //we wlasnym ukl wsp; wierzcholkiA - dolna podstawa
    std::vector<Wektor<3>> wierzcholkiB;     // gorna podstawa
    const double alfa = 360/liczba_wierzcholkow;    //podzial 360 stopni w zaleznosci od liczby wierzcholkow
    const Wektor<3> r0 {{promien, 0, 0}};
    const Wektor<3> r1 {{promien, 0, wysokosc}};
    for (uint i=0; i<liczba_wierzcholkow; ++i)
    {
        wierzcholkiA.push_back(Macierz_obrotu<3>(alfa*i, "z")*r0);
        wierzcholkiB.push_back(Macierz_obrotu<3>(alfa*i, "z")*r1);
    }
    
    for (auto & w : wierzcholkiA)
    {
        w = przelicz_punkt_do_globalnego(w);
    }
    for (auto & w : wierzcholkiB)
    {
        w = przelicz_punkt_do_globalnego(w);
    }

    std::vector<std::vector<drawNS::Point3D>> punkty_rys;
    for(uint i = 0; i < liczba_wierzcholkow; ++i)
    {
        std::vector<drawNS::Point3D> surface;
        surface.push_back(konwertuj(wierzcholkiA[i]));
        surface.push_back(konwertuj(wierzcholkiA[(i+1)%liczba_wierzcholkow]));          // modulo %, zeby nie bylo seg faulta
        surface.push_back(konwertuj(wierzcholkiB[(i+1)%liczba_wierzcholkow]));
        surface.push_back(konwertuj(wierzcholkiB[i]));
        punkty_rys.push_back(surface);

    }
    id = rysownik->draw_polyhedron(punkty_rys, "light-blue");
}