/*
 * tab_dynamiczne.cpp
 * 
 * Copyright 2018  <>
 *  
 */


#include <iostream>
#include <iomanip> // setw()
#include <cstdlib> //srand(), rand()

using namespace std;

void wprowadzDane(int *t, int ile){
    for (int i = 0; i < ile; i++){
        cout << "Adres komórki: " << (t + i) <<endl;
        cout << "Podaj liczbę: ";
        //cin >> t[i];
        cin >> *(t + i);
    }
}

int tab1W(){
    // tworzenie 1-wymiarowej tablicy dynamicznej
    int ile = 0;
    cout << "Ile liczb podasz? ";
    cin >> ile;
    try {
        int *tab;
        tab = new int[ile];
        wprowadzDane(tab, ile);
    } catch(bad_alloc) {
        cout << "Za mało pamięci!" << endl;
        return 1;
    }
    return 0;
}

void wypelnij2W(int **tab, int w, int k){
    srand(time(NULL)); //inicjacja generatora liczb pseudolosowych
    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
            tab[i][j] = (i+1) * (j+1);
            cout << setw(4) << tab [i][j];
        }
        cout << endl;
    }
}

int tab2W(){
    int w, k, i;
    cout << "Ile wierszy i kolumn: ";
    cin >> w >> k;
    int **tab; // deklaracja wskaźnika do wskaźnika
    
    try {
        tab = new int *[w]; // utworzenie tablicy wsakźników
    } catch(bad_alloc) {
        cout << "Za mało pamięci!" << endl;
        return 1;
    }
    
    for(i = 0; i < w; i++){
        try {
            tab[i] = new int[k]; // utworzenie tablicy liczb całkowitych  
        } catch(bad_alloc) {
            cout << "Za mało pamięci!" << endl;
            return 1;
        }
    }
    wypelnij2W(tab, w, k);
    return 0;
}

int main(int argc, char **argv)
{
    
    tab2W();
    //~tab1W();
    
    
	return 0;
}

