#include <iostream>
#include "drzewo.hpp"

using namespace std;

int main(int argc, char **argv)
{
    Drzewo drzewo;
	DodajWezel(korzen, 10);
	//~DodajWezel(korzen, 8);
	//~DodajWezel(korzen, 4);
	//~DodajWezel(korzen, 9);
	//~DodajWezel(korzen, 20);
	//~DodajWezel(korzen, 16);
	//~DodajWezel(korzen, 30);
    
    cout << "Posortowane drzewo (niemalejąco): ";
    drzewo.WyswietlRosnaco(korzen);
    
    delete korzen; // zwolnienie wykorzystywanej pamięci
    
	return 0;
}

