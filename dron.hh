#ifndef DRON_HH
#define DRON_HH
#include "uklad_wsp.hh"
#include "wektor.hh"
#include "macierz.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include <array>
#include "inter_rys.hh"
#include "inter_drona.hh"
#include "inter_el_kraj.hh"
#include "Draw3D_api_interface.hh"

class Dron : public uklad_wspolrzednych, public Inter_rys, public Inter_drona, public Inter_el_kraj    // caly obiekt
{
    private:
        Prostopadloscian korpus;
        std::array<Graniastoslup6, 4> wirniki;
    
    public:
        Dron (Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, drawNS::Draw3DAPI *rysownik, uklad_wspolrzednych* rodzic);
        void rysuj() override;
        void zmaz() override;
        void podnies (double wysokosc) override;
        void lec_do_przodu (double ile) override;
        void obroc (double kat /*os Z */) override;
        void porusz_wirnikami () override;
        bool czy_nad (Inter_drona *dron) override { return 0; };
        bool czy_ladowac (Inter_drona *dron, double &wysokosc) override { return 0; };
};

#endif