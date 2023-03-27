#ifndef GRANIASTOSLUP6_HH
#define GRANIASTOSLUP6_HH
#include "uklad_wsp.hh"
#include "wektor.hh"
#include "macierz.hh"
#include "Dr3D_gnuplot_api.hh"

class Graniastoslup6 : public uklad_wspolrzednych            // foremny szesciokatny, wirniki
{
    private:
        double wysokosc;
        double promien;
        uint id;

    public:
        Graniastoslup6 (double _wysokosc, double _promien, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic);
        const uint get_id()const { return id;}
        void rysuj (drawNS::Draw3DAPI *rysownik);
};


#endif