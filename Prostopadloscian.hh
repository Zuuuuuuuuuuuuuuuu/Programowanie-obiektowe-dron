#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
#include "uklad_wsp.hh"
#include "wektor.hh"
#include "macierz.hh"
#include "Dr3D_gnuplot_api.hh"
#include "inter_rys.hh"


class Prostopadloscian : public uklad_wspolrzednych, public Inter_rys
{
    protected:
        double dlugosc;
        double szerokosc;
        double wysokosc;

    public:
        Prostopadloscian(drawNS::Draw3DAPI *rysownik, double _dlugosc, double _szerokosc, double _wysokosc, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic);
        const uint get_id()const { return id;}
        void rysuj () override;
        void zmaz () override;
};

#endif