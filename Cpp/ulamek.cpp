/*
 * ulamek.cpp
 * 
 * Copyright 2018  <>
 * 
 */


#include <iostream>

using namespace std;

class Ulamek {
private:
    int licznik; // Deklaracja składowej właściwości
    int mianownik;
public:
    Ulamek(int, int); // Deklaracja konstruktora
    void zapisz(int, int); // Deklaracja metody
    void wypisz(){
        cout << licznik << "/" << mianownik;
    }
    int get_l() { return licznik; }
    int get_m() { return mianownik; }
    void skracaj(); // Metoda drukuje skróconą postać ułamka
};

void Ulamek::skracaj(){
    ; //TODO - wykorzystaj algorytm Euklidesa optymalny
}

void Ulamek::zapisz(int l, int m){
    licznik = l;
    if (m != 0) mianownik = m;
    else {
        cout << "Mianownik nie może być zerem!" << endl;
        exit(1);
    }
}

Ulamek::Ulamek(int l, int m){
    licznik = l;
    if (m != 0) mianownik = m;
    else {
        cout << "Mianownik nie może być zerem!" << endl;
        exit(1);
    }
}

int main(int argc, char **argv)
{
	//~Ulamek u1, u2; // Deklaracja obiektu, czyli instancji klasy
    Ulamek u1(3, 7); // Definicja obiektu
    Ulamek u2(1, 4); // Definicja obiektu
    //~u1.zapisz(3 ,7);
    //~u2.zapisz(1 ,4);
    cout << "Ułamek 1: ";
    u1.wypisz();
    cout << endl << "Ułamek 2: ";
    u2.wypisz();
    
    u1.zapisz(7, 9);
    cout << endl << "Licznik: " << u1.get_l() << endl;
    cout << "Mianownik: " << u1.get_m() << endl;
    
    Ulamek u3(u1.get_l(), u1.get_m());
    u3.wypisz();
        
	return 0;
}
