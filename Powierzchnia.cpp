#include "Powierzchnia.hh"


Powierzchnia::Powierzchnia (double _wysokosc)
: wysokosc (_wysokosc)
{}

void Powierzchnia::rysuj (drawNS::Draw3DAPI *rysownik)      //siatka 5x5
{
    //linie w jedna strone
    rysownik->draw_line({-200, -200, wysokosc}, {200, -200, wysokosc}, "black");   
    rysownik->draw_line({-200, -100, wysokosc}, {200, -100, wysokosc}, "black");
    rysownik->draw_line({-200, 0, wysokosc}, {200, 0, wysokosc}, "black");
    rysownik->draw_line({-200, 100, wysokosc}, {200, 100, wysokosc}, "black");
    rysownik->draw_line({-200, 200, wysokosc}, {200, 200, wysokosc}, "black");

    //linie prostopadle
    rysownik->draw_line({-200, -200, wysokosc}, {-200, 200, wysokosc}, "black");
    rysownik->draw_line({-100, -200, wysokosc}, {-100, 200, wysokosc}, "black");
    rysownik->draw_line({0, -200, wysokosc}, {0, 200, wysokosc}, "black");
    rysownik->draw_line({100, -200, wysokosc}, {100, 200, wysokosc}, "black");
    rysownik->draw_line({200, -200, wysokosc}, {200, 200, wysokosc}, "black");
}