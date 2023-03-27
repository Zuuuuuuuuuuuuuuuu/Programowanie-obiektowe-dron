#ifndef MACIERZ_HH
#define MACIERZ_HH
#include <cmath>
#include <array>
#include <iostream>
#include "wektor.hh"

template<int ROZMIAR>
class Macierz_obrotu
{
    private:
        std::array<Wektor<ROZMIAR>, ROZMIAR> wiersze;                     //tablica wielowymiarowa
    public:
        Macierz_obrotu();                                            // konstruktor
        Macierz_obrotu(double kat_stopnie, std::string os);                    // dla podanego kata
        const Wektor<ROZMIAR> &operator [] (int indeks) const;
        Wektor<ROZMIAR> operator * (const Wektor<ROZMIAR> &arg2) const;         // mnozenie macierz razy wektor
        Macierz_obrotu operator * (const Macierz_obrotu &arg2) const;           // mnozenie macierz razy macierz
};

template<int ROZMIAR>
std::ostream &operator << (std::ostream &strm_wy, const Macierz_obrotu<ROZMIAR> &M);

#include "macierz.cpp"              // lub wszystko w jednym module
#endif