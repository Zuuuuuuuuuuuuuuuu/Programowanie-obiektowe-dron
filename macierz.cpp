template<int ROZMIAR>
Macierz_obrotu<ROZMIAR>::Macierz_obrotu()          // macierz jednostkowa
{
    for (int i = 0; i < ROZMIAR; ++i)
    {
        Wektor<ROZMIAR> wektor;             // wektor np 2 lub 3 wymiarowy odpowiada wierszowi macierzy
        for (int j = 0; j < ROZMIAR; ++j)
        {
            if (j == i) wektor[j] = 1;      // czyli kiedy wspolczynniki macierzy te same - wpisujemy 1
            else wektor[j] = 0;
        }
        wiersze[i] = wektor;
    }
}

//TODO: osobne specjalizacje
//lub pomyslec nad petlami jakimis sprytnymi
template<int ROZMIAR>
Macierz_obrotu<ROZMIAR>::Macierz_obrotu(double kat_stopnie, std::string os)           //konstruktor
{
    double rad = kat_stopnie * M_PI / 180;        // przeliczenie stopni na radiany
    switch (ROZMIAR)
    {
        case 2:
            wiersze[0][0] = cos(rad);
            wiersze[0][1] = -sin(rad);
            wiersze[1][0] = sin(rad);
            wiersze[1][1] = cos(rad);
        break;
        case 3:                         
        if (os == "x")          // obrot wzgledem roznych osi
        {
            wiersze[0][0] = 1;
            wiersze[0][1] = 0;
            wiersze[0][2] = 0;
            wiersze[1][0] = 0;
            wiersze[1][1] = cos(rad);
            wiersze[1][2] = -sin(rad);
            wiersze[2][0] = 0;
            wiersze[2][1] = sin(rad);
            wiersze[2][2] = cos(rad);
        }
        else if (os == "y")
        {
            wiersze[0][0] = cos(rad);
            wiersze[0][1] = 0;
            wiersze[0][2] = sin(rad);
            wiersze[1][0] = 0;
            wiersze[1][1] = 1;
            wiersze[1][2] = 0;
            wiersze[2][0] = -sin(rad);
            wiersze[2][1] = 0;
            wiersze[2][2] = cos(rad);
        }
        else if (os == "z")
        {        
            wiersze[0][0] = cos(rad);
            wiersze[0][1] = -sin(rad);
            wiersze[0][2] = 0;
            wiersze[1][0] = sin(rad);
            wiersze[1][1] = cos(rad);
            wiersze[1][2] = 0;
            wiersze[2][0] = 0;
            wiersze[2][1] = 0;
            wiersze[2][2] = 1;
        }
    }
}

template<int ROZMIAR>
const Wektor<ROZMIAR> &Macierz_obrotu<ROZMIAR>::operator [] (int indeks) const
{
    if (indeks < 0 || indeks >= ROZMIAR)
    {
        std::cerr << "Odwolanie poza pamiec" << std::endl;
        // return 0;
    }
    return wiersze[indeks];
}

template <int ROZMIAR>
Wektor<ROZMIAR> Macierz_obrotu<ROZMIAR>::operator * (const Wektor<ROZMIAR> &arg2) const         // mnozenie macierz razy wektor
{
    Wektor<ROZMIAR> wynik;
    double suma;
    for (int i = 0; i < ROZMIAR; ++i)
    {
        suma = 0;
        for (int j = 0; j < ROZMIAR; ++j)
        {
            suma += wiersze[i][j] * arg2[j];
        }
        wynik[i] = suma;
    }
    return wynik;
}

template <int ROZMIAR>
Macierz_obrotu<ROZMIAR> Macierz_obrotu<ROZMIAR>::operator * (const Macierz_obrotu<ROZMIAR> &arg2) const       // mnozenie macierz * macierz
{
    Macierz_obrotu<ROZMIAR> wynik;
    double suma;
    for (int i = 0; i < ROZMIAR; ++i)
    {
        for (int j = 0; j < ROZMIAR; ++j)
        {
            suma = 0;
            for (int k = 0; k < ROZMIAR; ++k)
            {
                suma += wiersze[i][k] * arg2.wiersze[k][j];
            }
            wynik.wiersze[i][j] = suma;                                         // wiersze to pole prywatne klasy
        }
    }
    return wynik;
}

template <int ROZMIAR>
std::ostream &operator << (std::ostream & strm_wy, const Macierz_obrotu<ROZMIAR> &M)
{
    for (int k=0; k<ROZMIAR; k++)
    {
        for (int j=0; j<ROZMIAR; j++)
        {
            strm_wy << M[k][j] << " ";
        }
        strm_wy << "\n" ;
    }
    return strm_wy;
}