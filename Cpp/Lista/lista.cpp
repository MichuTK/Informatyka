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
    ; // co dalej?
}
