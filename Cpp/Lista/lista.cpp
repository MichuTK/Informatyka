#include <iostream>
#include "lista.hpp"


Lista::Lista(){
    head = NULL;
    tail = NULL;
}

Lista::~Lista(){
    while(Usun()){;}
}

void Lista::Dodaj(int wartosc){
    ELEMENT *el = new ELEMENT;
    el->wartosc = wartosc;
    el->nast = NULL;
    if(head == NULL){
        head = el;
        tail = el;
    } else {
        tail->nast = el; // ustawienie wskaźnika nast dotychzasowegoo
        // ostatniego elementu na adres nowego ostatniego elementu
        tail = el; // aktualizujemy wskażnik ogn, abu wskazywał na nowy dodany element
    }
}

void Lista::Wyswietl(){
    ELEMENT *el = head;
    while(el != NULL){
        std::cout << el->wartosc << " ";
        el = el->nast;
    }
    std::cout << std::endl;
}

bool Lista::Usun(){
    if(head != NULL){ // usuniecie ostatniego elementu
        if (head == tail){
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            ELEMENT *el = head;
            while(el->nast != tail){ // szukam przedostatniego elementu
                el = el->nast; // zapis adresu przedostatniego
            }
            delete el->nast;
            el->nast = NULL;
            tail = el;
        }
    return true;
    }
    return false;
}

void Lista::Wstaw(int pozycja, int wartosc){
    if (pozycja < 0)    pozycja *= (-1);	// wartosc bezwzgledna
    if(pozycja != 0){
        if(pozycja > i){
        Dodaj(wartosc);				// definicja powiekdzenia listy
        } else if (pozycja == 1) {		// zmiana na head
            ELEMENT *el = new ELEMENT;
            el -> wartosc = wartosc;
            el -> wskaznik = head;
            head = el;
            i++;
        } else {
            ELEMENT *el = new ELEMENT;
            el -> wartosc = wartosc;	// przypisanie nowej wartosci
            
            ELEMENT *p = head;		// wskaznik pomocniczy

            for (int j = 1; j != pozycja - 1; j++)
                p = p -> wskaznik;	// dotarcie do poprzedniej pozycji

            el -> wskaznik = p -> wskaznik;
            p -> wskaznik = el;
            
            i++;
        }
    }
}
