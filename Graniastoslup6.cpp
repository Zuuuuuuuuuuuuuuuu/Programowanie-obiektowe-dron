#include "Graniastoslup6.hh"
#include <math.h>

Graniastoslup6::Graniastoslup6 (double _wysokosc, double _promien, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic)
: uklad_wspolrzednych(_srodek, _orientacja, rodzic),
wysokosc (_wysokosc),
promien (_promien)
{}


void Graniastoslup6::rysuj (drawNS::Draw3DAPI *rysownik)
{
    std::vector<Wektor<3>> wierzcholki;
    // wierzcholki dolnej podstawy;     srodek (0,0,0) i promien od srodka do wierzcholka
    wierzcholki.push_back(Wektor<3>({promien, 0, 0}));
    wierzcholki.push_back(Wektor<3>({0.5*promien, sqrt(3)*0.5*promien, 0}));
    wierzcholki.push_back(Wektor<3>({-0.5*promien, sqrt(3)*0.5*promien, 0}));
    wierzcholki.push_back(Wektor<3>({-promien, 0, 0}));
    wierzcholki.push_back(Wektor<3>({-0.5*promien, -sqrt(3)*0.5*promien, 0}));
    wierzcholki.push_back(Wektor<3>({0.5*promien, -sqrt(3)*0.5*promien, 0}));

    // wierzcholki gornej podstawy
    wierzcholki.push_back(Wektor<3>({promien, 0, wysokosc}));
    wierzcholki.push_back(Wektor<3>({0.5*promien, sqrt(3)*0.5*promien, wysokosc}));
    wierzcholki.push_back(Wektor<3>({-0.5*promien, sqrt(3)*0.5*promien, wysokosc}));
    wierzcholki.push_back(Wektor<3>({-promien, 0, wysokosc}));
    wierzcholki.push_back(Wektor<3>({-0.5*promien, -sqrt(3)*0.5*promien, wysokosc}));
    wierzcholki.push_back(Wektor<3>({0.5*promien, -sqrt(3)*0.5*promien, wysokosc}));

    for (auto & w : wierzcholki)
    {
        w = przelicz_punkt_do_globalnego(w);
    }                                                        // czyli mamy te wspolrzedne wierzcholkow wzgledem ukladu rodzica (drona)                                                     // juz mamy je wzgledem ukladu dziadka (globalnego)

    std::vector<std::vector<drawNS::Point3D>> punkty_rys;

    std::vector<drawNS::Point3D> surface1;
    surface1.push_back(konwertuj(wierzcholki[7]));
    surface1.push_back(konwertuj(wierzcholki[1]));
    surface1.push_back(konwertuj(wierzcholki[0]));
    surface1.push_back(konwertuj(wierzcholki[6]));
    punkty_rys.push_back(surface1);

    std::vector<drawNS::Point3D> surface2;
    surface2.push_back(konwertuj(wierzcholki[6]));
    surface2.push_back(konwertuj(wierzcholki[0]));
    surface2.push_back(konwertuj(wierzcholki[5]));
    surface2.push_back(konwertuj(wierzcholki[11]));
    punkty_rys.push_back(surface2);

    std::vector<drawNS::Point3D> surface3;
    surface3.push_back(konwertuj(wierzcholki[11]));
    surface3.push_back(konwertuj(wierzcholki[5]));
    surface3.push_back(konwertuj(wierzcholki[4]));
    surface3.push_back(konwertuj(wierzcholki[10]));
    punkty_rys.push_back(surface3);

    std::vector<drawNS::Point3D> surface4;
    surface4.push_back(konwertuj(wierzcholki[10]));
    surface4.push_back(konwertuj(wierzcholki[4]));
    surface4.push_back(konwertuj(wierzcholki[3]));
    surface4.push_back(konwertuj(wierzcholki[9]));
    punkty_rys.push_back(surface4);
    
    std::vector<drawNS::Point3D> surface5;
    surface5.push_back(konwertuj(wierzcholki[9]));
    surface5.push_back(konwertuj(wierzcholki[3]));
    surface5.push_back(konwertuj(wierzcholki[2]));
    surface5.push_back(konwertuj(wierzcholki[8]));
    punkty_rys.push_back(surface5);

    std::vector<drawNS::Point3D> surface6;
    surface6.push_back(konwertuj(wierzcholki[8]));
    surface6.push_back(konwertuj(wierzcholki[2]));
    surface6.push_back(konwertuj(wierzcholki[1]));
    surface6.push_back(konwertuj(wierzcholki[7]));
    punkty_rys.push_back(surface6);

    id = rysownik->draw_polyhedron(punkty_rys, "red");
}