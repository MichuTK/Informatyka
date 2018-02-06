/*
 * drzewo_bin.cpp.cxx
 * 
 * Copyright 2018  <>
 * 
 */


#include <iostream>

using namespace std;

struct Wezel{
    int wartosc;
    Wezel *lewy;
    Wezel *prawy;
} *korzen = NULL; // definicja struktury i utworzenie wskaźnika korzeń


Wezel* stworzWezel(int wartosc){
    Wezel *nowyWezel = new Wezel;
    nowyWezel -> wartosc = wartosc;
    nowyWezel -> lewy = NULL;
    nowyWezel -> prawy = NULL;
    
    return nowyWezel;
}

void dodajWezel(Wezel *wezel, int wartosc){
    if (korzen == NULL) { // drzewo jest puste
        korzen = stworzWezel(wartosc);
    } else {
        if (wartosc < wezel -> wartosc){ // wstawiamy wartosc mniejsza
            if(wezel -> lewy != NULL) {
                dodajWezel(wezel -> lewy, wartosc); // rekurencyjne wywołanie dodawanie do lewego podrzewa
            } else { // lewy potomek nie istnieje
                wezel->lewy = stworzWezel(wartosc); // tworzymy nowy węzel
            }
        } else { //wstawiamy wartosc wieksza
            if(wezel -> prawy != NULL) {
                dodajWezel(wezel -> prawy, wartosc); // rekurencyjne wywołanie dodawanie do lewego podrzewa
            } else { // lewy potomek nie istnieje
                wezel->prawy = stworzWezel(wartosc); // tworzymy nowy węzel
            }
        }
        
    
    }
    
    
}

int main(int argc, char **argv)
{
	
	return 0;
}

