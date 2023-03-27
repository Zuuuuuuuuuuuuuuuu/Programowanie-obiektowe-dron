#ifndef INTER_DRONA_HH
#define INTER_DRONA_HH


class Inter_drona 
{
    public:
        virtual void podnies (double wysokosc) = 0;
        virtual void lec_do_przodu (double ile) = 0;
        virtual void obroc (double kat /*os Z */) = 0;
        virtual ~Inter_drona()=default;
        virtual void porusz_wirnikami () = 0;
};

#endif