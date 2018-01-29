/*
 * uczen.cpp
 * 
 * Copyright 2018  <>
 * 
 */
 
#include <iostream>
#include <string>

using namespace std;
 

 
class Uczen {
    string imie;  
    string nazwisko;
	int liczba; 
public:
    Uczen(string, string);
    void podaj_dane(string, string); 
    
    string get_i(){
        return imie;
        }
    string get_n(){
        return nazwisko;
        }
    void klasa(string k){
	cout << "Podaj klase: " << endl;
	cin >> k;
	}
    void oceny_i_srednia(int);
   
    
};



void Uczen::podaj_dane(string i, string n){
    imie = i;
    nazwisko = n;
    cout << "Podaj imie: " << endl;
    cin >> i;
    cout << "Podaj nazwisko: " << endl;
    cin >> n;
    }
    
    
Uczen::Uczen(string i, string n){
    imie = i;
    nazwisko = n;
    cout << "Podaj imie: " << endl;
    cin >> i;
    cout << "Podaj nazwisko: " << endl;
    cin >> n;
    }
    
void Uczen::oceny_i_srednia(int l){
    liczba = l;
    int tab[l];
    int a = 0;
    int b = 0;
    cout << "Podaj liczbe ocen: " << endl;
    cin >> l;
    cout << "Podaj te oceny: " << endl;
    for(int i = 0; i < l; i++){
    	cin >> a;
    	b = b + a;
    	tab[i] = a;
	}
	cout << "Oceny: " << tab[l] << endl;
	cout << "Srednia ocen: " << endl;
	cout << b/liczba;
    }
    

int main(int argc, char **argv)
{
    
    Uczen u1,u2;
    u1.podaj_dane();
    
    
	
	system("pause");
}
