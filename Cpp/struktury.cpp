/*
 * struktury.cpp
 */


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct osoba {
    char imie[20];
    char nazwisko[30];
    int wiek;
};

struct samochod {
    char marka[40];
    char model[40];
    int rok;
};

/*void wyswietlDane(osoba o){
    cout << setw(20) << "Imie: " << o.imie << endl;
    cout << setw(20) << "Nazwisko: " << o.nazwisko << endl;
    cout << setw(20) << "Wiek: " << o.wiek << endl;
}*/

void wyswietlDane(samochod o){
    cout << setw(25) << left << "Marka: " << setfill('.') << o.marka << endl;
    cout << setw(25) << left << "Model: " << setfill('.') << o.model << endl;
    cout << setw(25) << left <<  "Rok produkcji: " << setfill('.') << o.rok << endl;
}

void getSamochody(samochod t[], int n){
    for(int i=0; i < n; i++){
        cout << endl;
        cout << "Podaj marke: ";
        cin >> t[i].marka;
        cout << "Podaj model: ";
        cin >> t[i].model;
        cout << "Podaj rok produkcji: ";
        cin >> t[i].rok;
    }
}

void drukujSamochody(samochod t[], int n){
    for(int i=0; i < n; i++){
		cout << endl;
        cout << setw(25) << setfill('.') << left << "Marka: " << t[i].marka << endl;
        cout << setw(25) << setfill('.') << left << "Model: " << t[i].model << endl;
        cout << setw(25) << setfill('.') << left << "Rok produkcji: " << t[i].rok << endl;
    }
}

void zapiszDane(samochod t[], int n){
    ofstream plik("samochody.txt", ios::app);
    if(!plik.is_open()){
        cout << "Błąd otwarcia pliku!" << endl;
    } else {
        for(int i=0; i < n; i++){
            cout << t[i].marka << ", " << t[i].model << ", " << t[i].rok << endl;
            plik << t[i].marka << ", " << t[i].model << ", " << t[i].rok << endl;
        }
    }
}

int czytajDane(samochod t[]){
    string linia;
    ifstream plik("samochody.txt");
    int i = 0;
    if(plik.is_open()){
        while(getline(plik, linia)){
            cout << linia << endl;
            i++;
        }
    } else {
        cout << "Błąd otwarcia pliku!" << endl;
    }
    return i;
}

int main(int argc, char **argv)
{

    //~osoba uczen1;
    //~cout << "Podaj imie: ";
    //~cin >> uczen1.imie;
    //~cout << "Podaj nazwosko: ";
    //~cin >> uczen1.nazwisko;
    //~cout << "Podaj wiek: ";
    //~cin >> uczen1.wiek;

    //~samochod auto1;
    //~cout << "Podaj marke: ";
    //~cin >> auto1.marka;
    //~cout << "Podaj model: ";
    //~cin >> auto1.model;
    //~cout << "Podaj rok produkcji: ";
    //~cin >> auto1.rok;
    //~cout << "Podaj przebieg: ";
    //~cin >> auto1.przebieg;

    int n;
    cout << "Ile samochodow chcesz wprowadzic? "; cin >> n;
    samochod tb[n];
    //getSamochody(tb, n);
    //zapiszDane(tb, n);
    cout << czytajDane(tb) << endl;
    //drukujSamochody(tb, n);

	return 0;
}

