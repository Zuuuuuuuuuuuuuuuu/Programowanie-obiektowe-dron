#include "scena.hh"
#include <thread>
#include <chrono>
#include <algorithm>


constexpr int l_klatek = 30;                // stala liczba klatek
void Scena::animacja(drawNS::Draw3DAPI * rysownik, double wysokosc, double odleglosc, double kat)
{
  auto it_drona = drony.find(id_aktualnego);
  if(it_drona == drony.end())
  {
    std::cout << "aktualny dron nie istnieje\n";
    return;
  }
  
  auto it_rys = elem_rysowalne.find(id_aktualnego);
  if(it_rys == elem_rysowalne.end())
  {
    std::cout << "aktualny dron nie istnieje\n";
    return;
  }
  
  auto dron = it_drona->second;
  auto dron_do_rysowania = it_rys->second;
  
  using namespace std::chrono_literals;     // gdyby bez tego to std::this_thread::sleep_for (std::chrono::milliseconds (100))
  
  for (int i=0; i<l_klatek; ++i)
  {
    dron->podnies(wysokosc/l_klatek);        // podniesienie drona na jakas wysokosc
    dron->porusz_wirnikami();
    std::this_thread::sleep_for (100ms);
    dron_do_rysowania->zmaz();                    // zeby nie bylo sladu
    dron_do_rysowania->rysuj();
  }

  for (int i=0; i<l_klatek; ++i)
  {
    dron->obroc(kat/l_klatek);               // obrocenie drona w jakims kierunku
    dron->porusz_wirnikami();
    std::this_thread::sleep_for (100ms);
    dron_do_rysowania->zmaz();
    dron_do_rysowania->rysuj();

  }

  for (int i=0; i<l_klatek; ++i)
  {
    dron->lec_do_przodu(odleglosc/l_klatek);   // przemieszczenie drona na jakas odleglosc
    dron->porusz_wirnikami();
    std::this_thread::sleep_for (100ms);
    dron_do_rysowania->zmaz();
    dron_do_rysowania->rysuj();

  }
  
  for (int i=0; i<l_klatek; ++i)
  {
    dron->podnies(-wysokosc/l_klatek);             // ladowanie dronem
    dron->porusz_wirnikami();
    std::this_thread::sleep_for (100ms);
    dron_do_rysowania->zmaz();
    dron_do_rysowania->rysuj();
  }
}


void Scena::rysuj_wszystko()
{
  for (auto kolekcja : elem_rysowalne)
  {
    kolekcja.second->zmaz();
  }
  for(auto rys : elem_rysowalne)      /* tyle ile: liczba_elem_rys, tyle razy wywolaj funkcje rysuj dla kazdego obiektu */
  {
    rys.second->rysuj();
  }
}


void Scena::dodaj(std::shared_ptr<Dron> dron, std::string id)
{
  drony[id] = dron;                   //dodawanie do dwoch odpowiednich kolekcji
  elem_rysowalne[id] = dron;
}

void Scena::dodaj(std::shared_ptr<Plaskowyz> plaskowyz, std::string id)
{
  elem_kraj[id] = plaskowyz;
  elem_rysowalne[id] = plaskowyz;
}

void Scena::dodaj(std::shared_ptr<Wzgorze> wzgorze, std::string id)
{
  elem_kraj[id] = wzgorze;
  elem_rysowalne[id] = wzgorze;
}

void Scena::dodaj(std::shared_ptr<Plaskowyz_prostopadl> plaskowyz_prostopadl, std::string id)
{
  elem_kraj[id] = plaskowyz_prostopadl;
  elem_rysowalne[id] = plaskowyz_prostopadl;
}


void Scena::usun(std::string id_uzytkownika)
{
  for (auto kolekcja : elem_rysowalne)
  {
    auto element = elem_rysowalne.find(id_uzytkownika);   // znajdujemy obiekt o takim id na liscie
    if (element != elem_rysowalne.end())                  // jezeli jest na liscie
    {
      element->second->zmaz();                            // to zmazujemy
    }
    else
    {
      std::cout << "Nie ma takiego obiektu!\n";
    }
  }
  drony.erase(id_uzytkownika);                            // potem usuwamy z list
  elem_rysowalne.erase(id_uzytkownika);
  elem_kraj.erase(id_uzytkownika);
}


void Scena::pokaz_elem_kraj()
{
  for (auto kolekcja : elem_rysowalne)
  {
    kolekcja.second->zmaz();
  }
  for (auto k : elem_kraj)                                          // przeszukaj po elementach krajobrazu
  {
    auto przeszkody_do_pokazania = elem_rysowalne.find(k.first);    // znajdz elementy krajobrazu w elementach rysowalnych po id (po "key")
    if (przeszkody_do_pokazania != elem_rysowalne.end())            // jesli znajdzie to nie zwroci konca listy
    {
      przeszkody_do_pokazania->second->rysuj();                     // wiec je narysuje
    }
  }
}


void Scena::pokaz_drony()                                           // analogicznie
{
  for (auto kolekcja : elem_rysowalne)
  {
    kolekcja.second->zmaz();
  }
  for (auto d : drony)
  {
    auto dron_rys = elem_rysowalne.find(d.first);
    if(dron_rys != elem_rysowalne.end())
    {
      dron_rys->second->rysuj();
    }
  }
}


void Scena::wybierz_drona(std::string id)                          // do wybrania ktorym dronem bedzie latac uzytkownik
{
  id_aktualnego = id;
}


bool Scena::czy_istnieje_takie_id(std::string id_uzytkownika)
{
  for (auto kolekcja : elem_rysowalne)                            // przejdz po wszystkich elementach rysowalnych
  {
    auto szukane_id = elem_rysowalne.find(id_uzytkownika);        // wyszukaj w nich takie id_uzytkownika
    if (szukane_id != elem_rysowalne.end())                       // jest rozne od 'nie istnieje' czyli istnieje na liscie 
      return true;                                                // jesli znajdzie - zwroci true
  }
  return false;
}


void Scena::dostepne_id()                                             // gdyby uzytkownik zapomnial co ma na scenie
{
  for (auto elementy : elem_rysowalne)
  {
    std::cout << "Dostepne sa obiekty o nastepujacych id: " << elementy.first << std::endl;
  }
}