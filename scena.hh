#ifndef SCENA_HH
#define SCENA_HH
#include <memory>
#include <map>
#include "inter_rys.hh"
#include "inter_el_kraj.hh"
#include "inter_drona.hh"
#include "dron.hh"
#include "Draw3D_api_interface.hh"
#include "Powierzchnia.hh"
#include "plaskowyz.hh"
#include "wzgorze.hh"
#include "plaskowyz_prostopadl.hh"
#include <string>


class Scena
{
    protected:
        std::map<std::string, std::shared_ptr<Inter_drona>> drony;                  //kolekcje: mapy
        std::map<std::string, std::shared_ptr<Inter_el_kraj>> elem_kraj;
        std::map<std::string, std::shared_ptr<Inter_rys>> elem_rysowalne;           //czyli i drony, i elementy krajobrazu
        std::string id_aktualnego;
    public:
        Scena ()= default;
        void animacja (drawNS::Draw3DAPI * rysownik, double wysokosc, double odleglosc, double kat);
        void rysuj_wszystko();
        void sprawdz_kolizje(Inter_drona *D);
        void dodaj(std::shared_ptr<Dron>, std::string id);
        void dodaj(std::shared_ptr<Plaskowyz>, std::string id);
        void dodaj(std::shared_ptr<Wzgorze>, std::string id);
        void dodaj(std::shared_ptr<Plaskowyz_prostopadl>, std::string id);
        void usun(std::string id_uzytkownika);
        void pokaz_elem_kraj();
        void pokaz_drony();
        void wybierz_drona(std::string id);
        bool czy_istnieje_takie_id(std::string id_uzytkownika);
        void dostepne_id();
};


#endif