#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <array>
#include <cmath>
#include "Dr3D_gnuplot_api.hh"

template <int ROZMIAR>                              // szablon
class Wektor
{
    private:
        std::array<double, ROZMIAR> xyz;                     // tablica
    public:
        Wektor() = default;                                 // konstruktory: domyslny
        Wektor(const std::array<double, ROZMIAR>&);         // parametryczny; referencja
        Wektor operator + (const Wektor &arg2) const;      //dodawanie dwoch wektorow
        Wektor operator - (const Wektor &arg2) const;      //odejmowanie dwoch wektorow
        double operator * (const Wektor &arg2) const;      //iloczyn skalarny dwoch wektorow
        Wektor operator * (double skalar) const;      //iloczyn skalarny dwoch wektorow

        //zamiast setterow i getterow przeciazenia nawiasow [] (tablica)
        const double operator [] (int indeks) const;        //staly - do wywolywania miejsc tablicy
        double &operator [] (int indeks);                   //moze zmieniac wartosci w tablicy

        const double dlugosc_wektora () const;    // dlugosci wektorow 
};

template <int ROZMIAR>
std::ostream &operator << (std::ostream & strm_wy, const Wektor<ROZMIAR> &W);    //do wypisywania wartosci na ekran

template <int ROZMIAR>
std::istream &operator >> (std::istream & strm_we, Wektor<ROZMIAR> &W);


inline drawNS::Point3D konwertuj(Wektor<3> wektor) {return drawNS::Point3D(wektor[0], wektor[1], wektor[2]); }

#include "wektor.cpp"                   // lub wszystko w jednym module, lub wektor.tpp (od template)
#endif