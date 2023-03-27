
template <int ROZMIAR>                                              //szablon
Wektor<ROZMIAR>::Wektor(const std::array<double, ROZMIAR> &arg)     //konstruktor
: xyz {arg}                                                          //lista inicjalizujaca
{

}
        
template <int ROZMIAR>
const double Wektor<ROZMIAR>::operator[] (int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR)                           // >= bo indeksujemy od 0
    {
        std::cerr << "Odwolanie poza pamiec" << std::endl;
        return 0;
    }
    return xyz[indeks];
}

template <int ROZMIAR>
double &Wektor<ROZMIAR>::operator [] (int indeks)
{
    if (indeks < 0 || indeks >= ROZMIAR)
    {
        std::cerr << "Odwolanie poza pamiec" << std::endl;
    }
    return xyz[indeks];
}

template <int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator + (const Wektor &arg2) const
{
    Wektor wynik;
    for (int k=0; k<ROZMIAR; ++k)
    {
        wynik[k] = xyz[k] + arg2[k];                         // dodawanie odpowiednich pol argumentow
    }
    return wynik;
}

template <int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator - (const Wektor &arg2) const
{
    Wektor wynik;
    for (int k=0; k<ROZMIAR; ++k)
    {
        wynik[k] = xyz[k] - arg2[k];                         // odejmowanie odpowiednich pol argumentow
    }
    return wynik;
}

template <int ROZMIAR>
double Wektor<ROZMIAR>::operator * (const Wektor &arg2) const   // skalarnie wektor * wektor
{
    double wynik;
    for (int k=0; k<ROZMIAR; ++k)
    {
        wynik += xyz[k] * arg2[k];                       // mnozenie odpowiednich pol argumentow
    }
    return wynik;
}

template <int ROZMIAR>
Wektor<ROZMIAR> Wektor<ROZMIAR>::operator * (double skalar) const
{
    Wektor<ROZMIAR> wynik = *this;
    for (int k=0; k<ROZMIAR; ++k)
    {
        wynik[k] *= skalar;                       // mnozenie odpowiednich pol argumentow
    }
    return wynik;
}

template <int ROZMIAR>
std::ostream &operator << (std::ostream &strm_wy, const Wektor<ROZMIAR> &W)          
{
    for (int k=0; k<ROZMIAR; ++k)
    {
        strm_wy << W[k] << " ";
    }
    return strm_wy;
}

template <int ROZMIAR>
std::istream &operator >> (std::istream & strm_we, Wektor<ROZMIAR> &W)
{
    for (int k=0; k<ROZMIAR; ++k)
    {
        strm_we >> W[k];
    }
    return strm_we;
}

template <int ROZMIAR>
const double Wektor<ROZMIAR>::dlugosc_wektora () const
{
    double wynik = 0;
    for (int k=0; k<ROZMIAR; ++k)
    {
       wynik += pow( (xyz[k]), 2);;
    }
    wynik = sqrt(wynik);
    return wynik;
}