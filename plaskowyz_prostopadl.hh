#ifndef PLASKOWYZ_PROSTOPADL_HH
#define PLASKOWYZ_PROSTOPADL_HH
#include "inter_el_kraj.hh"
#include "uklad_wsp.hh"
#include "Draw3D_api_interface.hh"
#include "Prostopadloscian.hh"


class Plaskowyz_prostopadl : public Prostopadloscian, public Inter_el_kraj
{
    public:
        Plaskowyz_prostopadl(drawNS::Draw3DAPI *rysownik, double _dlugosc, double _szerokosc, double _wysokosc, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic);
        bool czy_nad (Inter_drona *dron) override { return 0; };
        bool czy_ladowac (Inter_drona *dron, double &wysokosc) override { return 0; };

};


#endif