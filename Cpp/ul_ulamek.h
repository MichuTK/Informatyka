#ifndef ULAMEK_H
#define ULAMEK_H
/*
 * Plik nagłówkowy klasy Ulamek 
 * 
 */

class Ulamek {
private:
    int licznik; // Deklaracja składowej właściwości
    int mianownik;
public:
    Ulamek(int, int); // Deklaracja konstruktora
    void zapisz(int, int); // Deklaracja metody
    void wypisz();
    int get_l();
    int get_m();
    void skracaj(); // Metoda drukuje skróconą postać ułamka
};
#endif
