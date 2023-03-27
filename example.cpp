#include <iostream>
#include <array>
#include "Dr3D_gnuplot_api.hh"
#include <cmath>
#include "uklad_wsp.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "dron.hh"
#include "Powierzchnia.hh"
#include "plaskowyz.hh"
#include "wzgorze.hh"
#include "plaskowyz_prostopadl.hh"
#include "scena.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::cin;
using std::endl;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main()
{
  drawNS::Draw3DAPI *rysownik = new drawNS::APIGnuPlot3D(-200, 200, -200, 200, -200, 200, 0);
  uklad_wspolrzednych globalny{{}, {}, nullptr};
  Scena scena;
  double gdzie_powierzchnia = -150;
  Powierzchnia pow (gdzie_powierzchnia);

  /* definiuje na poczatku jakies 3 elementy */
  std::shared_ptr<Dron> dron0 { new Dron(Wektor<3>({0, 0,(gdzie_powierzchnia+15)}), {}, rysownik, &globalny)};
  scena.dodaj(dron0, "John");
  std::shared_ptr<Wzgorze> wzgorze0 {new Wzgorze(rysownik, 160, 45, {{-100, -100, (gdzie_powierzchnia)}}, {}, &globalny)};
  scena.dodaj(wzgorze0, "Mount Everest");
  std::shared_ptr<Plaskowyz> plaskowyz0 {new Plaskowyz(rysownik, 50, 50, {{100, 100, gdzie_powierzchnia}}, {}, &globalny)};
  scena.dodaj(plaskowyz0, "Panamint");
  pow.rysuj(rysownik);
  scena.rysuj_wszystko();


  std::cout << "\nSYMULATOR LATANIA\nObecnie na scenie znajduja sie dron John, wzgorze Mount Everest i plaskowyz Panamint\n";
  // menu
  char opcja;
  cout << "\nDostepne opcje:\n";
  cout << "d - dodanie elementu do sceny" << endl;
  cout << "u - usuniecie elementu ze sceny" << endl;
  cout << "a - przelaczenie drona" << endl;
  cout << "i - wyswietlenie dostepnych id" << endl;
  cout << "l - przelot dronem" << endl;
  cout << "p - pokazanie przeszkod" << endl;
  cout << "s - pokazanie dronow" << endl;
  cout << "w - pokazanie wszystkiego na scenie" << endl;
  cout << "m - wyswietl menu" << endl;
  cout << "k - koniec dzialania programu" << endl;
  cout << "\n";

  while (opcja != 'k')
  {
    cout << "Prosze wybrac opcje (m - menu): ";
    cin >> opcja;
    switch (opcja)
    {
      case 'd':                                                                        // dodawanie elementu do sceny
      {
        std::cout << "\nJaki element chcesz dodac? Wybierz: \n1. Dron\n2. Wzgorze\n3. Plaskowyz\n4. Plaskowyz prostopadloscienny\n";
        uint numer;
        std::cin >> numer;
        switch (numer)
        {
          case 1:
          {
            std::cout << "\nDodaje drona do sceny. Jak ma sie nazywac ten dron? ";
            std::string id;
            std::cin >> id;
            if (scena.czy_istnieje_takie_id(id))                                        // nie moze byc 2 obiektow o takich samych id
            {
              std::cout << "Obiekt o takiej nazwie juz istnieje. Wybierz inna nazwe.";
              break;
            }
            double wspolrzedna_x;
            double wspolrzedna_y;
            std::cout << "\nSkad ma startowac dron? Podaj wspolrzedne.\nWspolrzedna osi x: ";
            std::cin >> wspolrzedna_x;
            std::cout << "Wspolrzedna osi y: ";
            std::cin >> wspolrzedna_y;
            std::shared_ptr<Dron> dron { new Dron(Wektor<3>({wspolrzedna_x, wspolrzedna_y,(gdzie_powierzchnia+15)}), {}, rysownik, &globalny)};
            scena.dodaj(dron, id);
          }
          break;

          case 2:
          {
            std::cout << "\nDodaje wzgorze do sceny. Jak ma sie nazywac wzgorze? ";
            std::string id;
            std::cin >> id;
            if (scena.czy_istnieje_takie_id(id))
            {
              std::cout << "Obiekt o takiej nazwie juz istnieje. Wybierz inna nazwe.";
              break;
            }
            double wspolrzedna_x;
            double wspolrzedna_y;
            std::cout << "\nGdzie umiejscowic przeszkode? Podaj wspolrzedne.\nWspolrzedna osi x: ";
            std::cin >> wspolrzedna_x;
            std::cout << "Wspolrzedna osi y: ";
            std::cin >> wspolrzedna_y;        // czy dodac wybor promienia i wysokosci?
            std::shared_ptr<Wzgorze> wzgorze {new Wzgorze(rysownik, 100, 70, {{wspolrzedna_x, wspolrzedna_y, (gdzie_powierzchnia)}}, {}, &globalny)};
            scena.dodaj(wzgorze, id);
          }
          break;

          case 3:
          {
            std::cout << "\nDodaje plaskowyz do sceny. Jak ma sie nazywac plaskowyz? ";
            std::string id;
            std::cin >> id;
            if (scena.czy_istnieje_takie_id(id))
            {
              std::cout << "Obiekt o takiej nazwie juz istnieje. Wybierz inna nazwe.";
              break;
            }
            double wspolrzedna_x;
            double wspolrzedna_y;
            std::cout << "\nGdzie umiejscowic przeszkode? Podaj wspolrzedne.\nWspolrzedna osi x: ";
            std::cin >> wspolrzedna_x;
            std::cout << "Wspolrzedna osi y: ";
            std::cin >> wspolrzedna_y;    //czy dodac wybor promienia i wysokosci?
            std::shared_ptr<Plaskowyz> plaskowyz {new Plaskowyz(rysownik, 90, 50, {{wspolrzedna_x, wspolrzedna_y, gdzie_powierzchnia}}, {}, &globalny)};
            scena.dodaj(plaskowyz, id);
          }
          break;

          case 4:
          {
            std::cout << "\nDodaje plaskowyz prostopadloscienny do sceny. Jak ma sie nazywac? ";
            std::string id;
            std::cin >> id;
            if (scena.czy_istnieje_takie_id(id))
            {
              std::cout << "Obiekt o takiej nazwie juz istnieje. Wybierz inna nazwe.";
              break;
            }
            double wspolrzedna_x;
            double wspolrzedna_y;
            std::cout << "\nGdzie umiejscowic przeszkode? Podaj wspolrzedne.\nWspolrzedna osi x: ";
            std::cin >> wspolrzedna_x;
            std::cout << "Wspolrzedna osi y: ";
            std::cin >> wspolrzedna_y;    //czy dodac wybor dlugosci, szerokosci i wysokosci?
            std::shared_ptr<Plaskowyz_prostopadl> plaskowyz_prostopadl {new Plaskowyz_prostopadl(rysownik, 100, 100, 100, {{wspolrzedna_x, wspolrzedna_y, gdzie_powierzchnia+50}}, {}, &globalny)};
            scena.dodaj(plaskowyz_prostopadl, id);
          }
          break;
        }
      }
      break;

      case 'u':                                         // ususwanie elementu ze sceny
      {
        std::string id;
        std::cout << "Ktory element chcesz usunac ze sceny? Podaj nazwe elementu: ";
        std::cin >> id;
        scena.usun(id);
        wait4key();
      }
      break;

      case 'a':                                         // wybor drona
      {
        std::string id;
        std::cout << "\nNa ktorego drona przelaczyc? Podaj id drona, ktorym chcesz teraz sterowac: ";
        std::cin >> id; 
        if (!scena.czy_istnieje_takie_id(id))
        {
          std::cout << "Nie ma takiego obiektu.\n";
          break;
        }
        scena.wybierz_drona(id);
      }
      break;

      case 'i':                                         // co jest obecnie na scenie
      {
        scena.dostepne_id();
      }
      break;

      case 'l':                                         // latanie dronem
      {
        double wysokosc, odleglosc, kat;
        cout << "\nLATANIE DRONEM\n\nTwoj dron jest gotowy do lotu!\n\nPodaj parametry sterowania:\nwysokosc: ";
        cin >> wysokosc;
        cout << "odleglosc: ";
        cin >> odleglosc;
        cout << "kat obrotu: ";
        cin >> kat;
        scena.rysuj_wszystko();
        scena.animacja(rysownik, wysokosc, odleglosc, kat);
        wait4key();
      }
      break;

      case 'p':                           // same przeszkody
      {
        pow.rysuj(rysownik);
        scena.pokaz_elem_kraj();
      }
      break;

      case 's':                          // same drony
      {
        pow.rysuj(rysownik);
        scena.pokaz_drony();
      }
      break;

      case 'w':                           // rysuje wszystko
      {
        pow.rysuj(rysownik);
        scena.rysuj_wszystko();
      }
      break;

      case 'm':                           // wyswietla menu
      {
        cout << "\nDostepne opcje:\n";
        cout << "d - dodanie elementu do sceny" << endl;
        cout << "u - usuniecie elementu ze sceny" << endl;
        cout << "a - przelaczenie drona" << endl;
        cout << "i - wyswietlenie dostepnych id" << endl;
        cout << "l - przelot dronem" << endl;
        cout << "p - pokazanie przeszkod" << endl;
        cout << "s - pokazanie dronow" << endl;
        cout << "w - pokazanie wszystkiego na scenie" << endl;
        cout << "m - wyswietl menu" << endl;
        cout << "k - koniec dzialania programu" << endl;
        cout << "\n";
      }
      break;

      case 'k':                                          // koniec dzialania programu
      cout << "\nKonczymy! Drony schowane do hangaru\n" << endl;
      break;

      default:
      cout << "Blad" << endl;
      break;
    }
  }
  wait4key();
  delete rysownik;         // musimy posprzątać
}