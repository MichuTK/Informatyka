#include <iostream>

using namespace std;

void konwertuj(int liczba, int podstawa, int reszty[], int n){

    int i = 0;

    do{
        reszty[i] = liczba % podstawa;
        liczba = liczba / podstawa;
        i++;
    }while(liczba != 0);

    for(int j = i-1; j >= 0; j--){
        if(reszty[j] > 9){
            if(reszty[j] == 10) cout << "A";
            else if(reszty[j] == 11) cout << "B";
            else if(reszty[j] == 12) cout << "C";
            else if(reszty[j] == 13) cout << "D";
            else if(reszty[j] == 14) cout << "E";
            else if(reszty[j] == 15) cout << "F";
        }
        else
            cout << reszty[j];
    }
}

int main()
{
    int liczba, podstawa, n = 10;
    int reszty[n] = {0};

    cout << "Podaj liczbe: ";
    cin >> liczba;
    cout << "Podaj podstawe: ";
    cin >> podstawa;

    konwertuj(liczba, podstawa, reszty, n);

    return 0;
}
