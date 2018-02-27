#include <iostream>
#include "drzewo.hpp"

Drzewo::Drzewo(){
    korzen = NULL;
}

//~Drzewo::~Drzewo(){
    //~while(Usun()){;}
//~}

Wezel* stworzWezel(int wartosc) {
    Wezel *nowyWezel = new Wezel;
    nowyWezel->wartosc = wartosc;
    nowyWezel->lewy = NULL;
    nowyWezel->prawy = NULL;
    
    return nowyWezel;
}

void Drzewo::DodajWezel(int korzen, int wartosc) {
    if (korzen == NULL) { // drzewo jest puste!
        korzen = stworzWezel(wartosc); // utworzenie 1. elementu
    } else {
        if (wartosc < wezel->wartosc) { // wstawiamy wartość do lewego poddrzewa
            if(wezel->lewy != NULL) {
                dodajWezel(wezel->lewy, wartosc);  // rekurencyjne wywołanie dodawanie do lewego poddrzewa
            } else {  // lewy potomek nie istnieje
                wezel->lewy = stworzWezel(wartosc);  // tworzymy nowy wezel
            }
        } else { // wstawiamy wartość do prawego poddrzewa
            if(wezel->prawy != NULL) {
                dodajWezel(wezel->prawy, wartosc);  // rekurencyjne wywołanie dodawanie do lewego poddrzewa
            } else {  // prawy potomek nie istnieje
                wezel->prawy = stworzWezel(wartosc);  // tworzymy nowy wezel
            }
        }
    }
}

// funkcja rekurencyjnie przegladajaca drzewo
void Drzewo::WyswietlRosnaco(Wezel *wezel){
    if (wezel != NULL){ // jeżeli węzeł nie jest pusty
        // rekurencyjnie wyświetl lewe poddrzewo
        wyswietlRosnaco(wezel->lewy);   
        // wypisz wartość aktualnego węzła
        std::cout << wezel->wartosc << ", ";
        // rekurencyjnie wyswietl prawe poddrzewo
        wyswietlRosnaco(wezel->prawy    );
    }
}
