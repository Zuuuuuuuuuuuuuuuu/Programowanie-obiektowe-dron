#ifndef PLASKOWYZ_HH
#define PLASKOWYZ_HH
#include <random>
#include "inter_el_kraj.hh"
#include "inter_rys.hh"
#include "uklad_wsp.hh"
#include "Draw3D_api_interface.hh"


class Plaskowyz : public Inter_el_kraj, public Inter_rys, public uklad_wspolrzednych
{
    private:
        uint  liczba_wierzcholkow;
        double wysokosc;
        double promien;
    public:
        Plaskowyz(drawNS::Draw3DAPI * _rysownik, double _wysokosc, uint  _liczba_wierzcholkow, double _promien, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic);
        Plaskowyz(drawNS::Draw3DAPI * _rysownik, double _wysokosc, double _promien, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic);
        const uint get_id()const { return id;}
        void rysuj() override;
        void zmaz() override;
        bool czy_nad (Inter_drona *dron) override { return 0; };
        bool czy_ladowac (Inter_drona *dron, double &wysokosc) override { return 0; };
};


#endif