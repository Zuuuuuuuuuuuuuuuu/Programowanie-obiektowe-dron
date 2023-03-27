#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH
#include "Dr3D_gnuplot_api.hh"
#include "wektor.hh"

class Powierzchnia 
{
    private:
        double wysokosc;

    public:
        Powierzchnia (double _wysokosc);
        void rysuj (drawNS::Draw3DAPI *rysownik);
};

#endif