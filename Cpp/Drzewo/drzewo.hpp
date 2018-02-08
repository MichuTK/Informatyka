#ifndef DRZEWO_HPP
#define DRZEWO_HPP

#include <iostream>

struct Wezel {
    int wartosc;
    Wezel *lewy;
    Wezel *prawy;
};

class Drzewo{
    private: // hermetyzacja danych
        *korzen = NULL; // definicja struktury i utworzenie wskaźnika korzen;
    public: // interfejs publiczny (API klasy)
        Drzewo(); // konstruktor
        //~Drzewo(); // destruktor, posprzątanie po klasie
        // memory leaks - wycieki pamięci
        void DodajWezel(int);
        void WyswietlRosnaco();
};

#endif
