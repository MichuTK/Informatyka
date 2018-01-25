/*
 * stos_tablica.cpp
 * 
 */


#include <iostream>

using namespace std;

bool size(int sr, sp){
    return true; //jeśli jest miejce na stosie
    return false; //w przypadku przepełnienie stosu (buffer overflow)
    
    
}

void push(int stos[], int dane, int &sp){
    if(size(sr, sp))
        stos[sp] = dane;
        sp++;
}

int pop(int stos[], int sp){
    sp--;
    return stos[sp];
}


int main(int argc, char **argv)
{
    int *stack; // wskaźnik struktury stosu
    int sr; // rozmiar stosu
    int sp = 0; // wskaźnik do pozycji na stosie
    
    cout << "Podaj rozmiar: "; cin >> sr;
    stack = new int[sr];
    
    push(stack, 4, sp); // sp = 1
    push(stack, 9, sp); // sp = 2
    cout << pop(stack, sp) << endl; // wynik = 9
    push(stack, 3, sp);
    cout << pop(stack, sp) << endl; // wynik = 3
    push(stack, 1, sp);
    cout << pop(stack, sp) << endl; // wynik = 3
    push(stack, 7, sp);
    cout << pop(stack, sp) << endl; // wynik = 3
    
	return 0;
}

