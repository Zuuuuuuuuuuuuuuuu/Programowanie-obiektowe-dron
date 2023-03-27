#ifndef INTER_RYS_HH
#define INTER_RYS_HH
#include "Draw3D_api_interface.hh"

class Inter_rys 
{
    protected:
        uint id;
        drawNS::Draw3DAPI *rysownik;
    public:
        Inter_rys(drawNS::Draw3DAPI * _rysownik) : rysownik(_rysownik) {}
        virtual ~Inter_rys()=default;
        virtual void rysuj() = 0;
        virtual void zmaz() = 0;
};


#endif