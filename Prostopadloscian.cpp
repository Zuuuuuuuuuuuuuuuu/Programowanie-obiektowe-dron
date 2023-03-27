#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian(drawNS::Draw3DAPI *rysownik, double _dlugosc, double _szerokosc, double _wysokosc, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic)
: uklad_wspolrzednych(_srodek, _orientacja, rodzic),
Inter_rys (rysownik),
dlugosc (_dlugosc),
szerokosc (_szerokosc),
wysokosc (_wysokosc)
{}

void Prostopadloscian::zmaz ()
{
    rysownik->erase_shape(this->get_id());
}

void Prostopadloscian::rysuj ()
{
    std::vector<Wektor<3>> wierzcholki;
    wierzcholki.push_back(Wektor<3>({-0.5*dlugosc, -0.5*szerokosc, -0.5* wysokosc}));    
    wierzcholki.push_back(Wektor<3>({-0.5*dlugosc, 0.5*szerokosc, -0.5* wysokosc}));
    wierzcholki.push_back(Wektor<3>({0.5*dlugosc, -0.5*szerokosc, -0.5* wysokosc}));
    wierzcholki.push_back(Wektor<3>({0.5*dlugosc, 0.5*szerokosc, -0.5* wysokosc}));
    wierzcholki.push_back(Wektor<3>({-0.5*dlugosc, -0.5*szerokosc, 0.5* wysokosc}));
    wierzcholki.push_back(Wektor<3>({-0.5*dlugosc, 0.5*szerokosc, 0.5* wysokosc}));
    wierzcholki.push_back(Wektor<3>({0.5*dlugosc, -0.5*szerokosc, 0.5* wysokosc}));
    wierzcholki.push_back(Wektor<3>({0.5*dlugosc, 0.5*szerokosc, 0.5* wysokosc}));

    for (auto & w : wierzcholki)
    {
        w = przelicz_punkt_do_globalnego(w);
    }
    
    std::vector<std::vector<drawNS::Point3D>> punkty_rys;
    std::vector<drawNS::Point3D> surface1;
    surface1.push_back(konwertuj(wierzcholki[0]));
    surface1.push_back(konwertuj(wierzcholki[1]));
    surface1.push_back(konwertuj(wierzcholki[3]));
    surface1.push_back(konwertuj(wierzcholki[2]));
    punkty_rys.push_back(surface1);

    std::vector<drawNS::Point3D> surface2;
    surface2.push_back(konwertuj(wierzcholki[2]));
    surface2.push_back(konwertuj(wierzcholki[3]));
    surface2.push_back(konwertuj(wierzcholki[7]));
    surface2.push_back(konwertuj(wierzcholki[6]));
    punkty_rys.push_back(surface2);

    std::vector<drawNS::Point3D> surface4;
    surface4.push_back(konwertuj(wierzcholki[6]));
    surface4.push_back(konwertuj(wierzcholki[7]));
    surface4.push_back(konwertuj(wierzcholki[5]));
    surface4.push_back(konwertuj(wierzcholki[4]));
    punkty_rys.push_back(surface4);

    std::vector<drawNS::Point3D> surface3;
    surface3.push_back(konwertuj(wierzcholki[4]));
    surface3.push_back(konwertuj(wierzcholki[5]));
    surface3.push_back(konwertuj(wierzcholki[1]));
    surface3.push_back(konwertuj(wierzcholki[0]));
    punkty_rys.push_back(surface3);
    
    id = rysownik->draw_polyhedron(punkty_rys, "red");
}