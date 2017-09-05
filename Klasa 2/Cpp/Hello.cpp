#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    string imie;
    int wiek, rok = 2017;
    const int data_powstania = 1983;
    int wiek_cpp = rok - data_powstania;
    
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Witaj " << imie << "!" << endl;
    
    cout << "Ile masz lat? ";
    cin >> wiek;
    cout << "Urodziłeś się w " << rok-wiek << " roku" << endl; 
    
    if(wiek > wiek_cpp)
        cout << "Jestem młodszy o " << wiek-wiek_cpp << " lat" << endl;
    else if(wiek < wiek_cpp)
        cout << "Jestem starszy o " << wiek_cpp-wiek << " lat" << endl;
    else{
        cout << "Mamy tyle samo lat!" << endl;
    }
        
    for(int )
    
    
    
	return 0;
}

