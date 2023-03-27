#include "plaskowyz_prostopadl.hh"

Plaskowyz_prostopadl::Plaskowyz_prostopadl(drawNS::Draw3DAPI *rysownik, double _dlugosc, double _szerokosc, double _wysokosc, Wektor<3> _srodek, Macierz_obrotu<3> _orientacja, uklad_wspolrzednych *rodzic)
: Prostopadloscian (rysownik, _dlugosc, _szerokosc, _wysokosc, _srodek, _orientacja, rodzic)
{}