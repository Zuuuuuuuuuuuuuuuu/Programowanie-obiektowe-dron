#ifndef INTER_EL_KRAJ_HH
#define INTER_EL_KRAJ_HH
#include "inter_drona.hh"

class Inter_el_kraj
{
    public:
        virtual ~Inter_el_kraj()=default;
        virtual bool czy_nad (Inter_drona *dron) = 0;
        virtual bool czy_ladowac (Inter_drona *dron, double &wysokosc) = 0;
};



#endif