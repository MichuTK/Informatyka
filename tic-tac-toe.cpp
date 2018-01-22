#include <iostream>
#include <iomanip> // setw()
//#include <cstdlib> //srand(), rand()

using namespace std;
		
int check(char **tab, int w, int k, bool player){
	if((tab[1][1] == tab[1][2] && tab[1][1] == tab[1][3] && tab[1][1] != '_') ||
	   (tab[2][1] == tab[2][2] && tab[2][1] == tab[2][3] && tab[2][1] != '_') || 
	   (tab[3][1] == tab[3][2] && tab[3][1] == tab[3][3] && tab[3][1] != '_') ||
	   (tab[1][1] == tab[2][1] && tab[1][1] == tab[3][1] && tab[1][1] != '_') ||
	   (tab[1][2] == tab[2][2] && tab[1][2] == tab[3][2] && tab[1][2] != '_') ||
	   (tab[1][3] == tab[2][3] && tab[1][3] == tab[3][3] && tab[1][3] != '_') ||
	   (tab[1][1] == tab[2][2] && tab[1][1] == tab[3][3] && tab[1][1] != '_') ||
	   (tab[1][3] == tab[2][2] && tab[1][3] == tab[3][1] && tab[1][3] != '_')){
		if(player){
			cout << "Wygrywa X" << endl;
			return 1;
		} else {
			cout << "Wygrywa O" << endl;
			return 1;
		}
	} else if(tab[1][1] != '_' && tab[1][2] != '_' && tab[1][3] != '_' &&
			  tab[2][1] != '_' && tab[2][2] != '_' && tab[2][3] != '_' &&
			  tab[3][1] != '_' && tab[3][2] != '_' && tab[3][3] != '_'){
		cout << "Remis!" << endl;
		return 1;
	} else return 0; 
}

void round(char **tab, int w, int k, bool player){
    int column, line;
    bool good = false;
    srand(time(NULL));
    do{
		if(player){
			cout << "Podaj kolumnę: ";
			cin >> column;
			cout << "Podaj wiersz: ";
			cin >> line;
		} else {
			line = (rand() % 3) + 1;			
			column = (rand() % 3) + 1;			
		}		
		if(column < 1 || column > 3 || line < 1 || line > 3 || tab[line][column] != '_'){
			cout << "Spróbuj jeszcze raz!" << endl;
			good = true;
		} else { good = false; }
	}while(good);
	
    if(player){        
        tab[line][column] = 'X';
    } else {
        tab[line][column] = 'O';
    }
}

void makeBoard(char **tab, int w, int k){
    tab[0][0] = ' ';
    tab[0][1] = '1';
    tab[0][2] = '2';
    tab[0][3] = '3';
    tab[1][0] = '1';
    tab[2][0] = '2';
    tab[3][0] = '3';
    
    for(int i = 1; i < w; i++){
        for(int j = 1; j < k; j++){
            tab[i][j] = '_';
        }
    }
}

void draw(char **tab, int w, int k){
    system("clear");
    cout << endl;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < k; j++){
            cout << setw(4) << tab [i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char **argv)
{
	bool player = false;
    int w, k, i;
    k = w = 4;
    char **tab;

    try {
        tab = new char *[w];
    } catch(bad_alloc) {
        cout << "Not enough memory!" << endl;
        return 1;
    }

    for(i = 0; i < w; i++){
        try {
            tab[i] = new char[k];
        } catch(bad_alloc) {
            cout << "Not enough memory!" << endl;
            return 1;
        }
    }

    makeBoard(tab, w, k);
    draw(tab, w, k);
    do{
		if (player){
			player = false;
			cout << "Tura O" << endl;
		} else {
			player = true;
			cout << "Tura X" << endl;
		}
		round(tab, w, k, player);
		draw(tab, w, k);	
    }while(check(tab, w, k, player) == 0);

	return 0;
}
