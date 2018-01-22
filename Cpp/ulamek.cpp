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
    void skracaj(int, int); // Metoda drukuje skróconą postać ułamka
};

void Ulamek::skracaj(int l, int m){
    int licznik = l;
    int mianownik = m;
    while (l != m)
	{
	if (l < m)
	m -= l;
	else
	l -= m;
	}
	cout << endl << "Ulamek po skróceniu: " << licznik/l << "/" << mianownik/l << endl;
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
	int licznik, mianownik;
	//~Ulamek u1, u2; // Deklaracja obiektu, czyli instancji klasy
    Ulamek u1(3, 7); // Definicja obiektu
    Ulamek u2(1, 4); // Definicja obiektu
    //~u1.zapisz(3 ,7);
    //~u2.zapisz(1 ,4);
    cout << "Ułamek 1: ";
    u1.wypisz();
    cout << endl << "Ułamek 2: ";
    u2.wypisz();
    
    //~ u1.zapisz(7, 9);
    //~ cout << endl << "Licznik: " << u1.get_l() << endl;
    //~ cout << "Mianownik: " << u1.get_m() << endl;
    
    cout << endl << "Podaj licznik: ";
    cin >> licznik;
    cout << "Podaj mianownik: ";
    cin >> mianownik;
    Ulamek u3(licznik, mianownik);
    u3.wypisz();
    u3.skracaj(licznik, mianownik);
    
    //~ Ulamek u3(u1.get_l(), u1.get_m());
    //~ u3.wypisz();
        
	return 0;
}
