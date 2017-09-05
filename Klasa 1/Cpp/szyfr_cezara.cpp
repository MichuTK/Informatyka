/*
 * szyfr_cezara.cpp
 *
 */

#include <iostream>

void szyfruj(char tekst[], int klucz){
    klucz = klucz % 26;
    while(tekst[i] != '\0)'{
        if ((int)tekst[i] + klucz > 122)
            tekst[i] = (char)((int)tekst[i] + klucz - 26);
        else
            ;
        i++;
    }
}

int main(int argc, char **argv)
{
    char tekst[100];
    int klucz = 3;
    cout << "Podaj tekst: ";
    cin >> tekst;
    cout << "Podaj klucz: ";
    cin >> klucz;
    szyfruj(tekst, klucz)
    cout << tekst << endl;


	return 0;
}

