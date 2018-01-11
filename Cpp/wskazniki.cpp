/*
 * wskazniki.cpp
 * 
 * Copyright 2018  <>
 * 
 */


#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int x = 11;
    
    cout << x << endl; //wartość zmiennej
    cout << &x << endl; // adres zmiennej w pamięci, 0x - wartość szestnastkowa
    cout << * &x << endl; // wartość zmiennej pod adresem
    
    int *px; // definicja wskaźnika do typu całkowitego
    px = &x; // inicjacja wskaźnika
    // wskaźnik zawsze zawera adres w pamięci
    cout << px << endl;
    cout << *px << endl;
    
    int y = 100;
    px = &y;
    cout << px << endl;
    cout << *px << endl;
    
	return 0;
}

