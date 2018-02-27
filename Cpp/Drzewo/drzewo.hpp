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
        void DodajWezel(int, int);
        //void WyswietlRosnaco();
};

#endif
