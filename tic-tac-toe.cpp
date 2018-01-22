#include <iostream>
#include <iomanip> // setw()
#include <cstdlib> //srand(), rand()

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
			cout << "Naciśnij ENTER aby kontynuować" << endl;
			getchar(); getchar();
			return 1;
		} else {
			cout << "Wygrywa O" << endl;
			cout << "Naciśnij ENTER aby kontynuować" << endl;
			getchar(); getchar();
			return 1;
		}
	} else if(tab[1][1] != '_' && tab[1][2] != '_' && tab[1][3] != '_' &&
			  tab[2][1] != '_' && tab[2][2] != '_' && tab[2][3] != '_' &&
			  tab[3][1] != '_' && tab[3][2] != '_' && tab[3][3] != '_'){
		cout << "Remis!" << endl;
		getchar(); getchar();
		return 1;
	} else return 0; 
}

void round(char **tab, int w, int k, bool player){
    int column, line, field;
    bool good = false;
    srand(time(NULL));
    do{
		if(player){
			cout << "Pole: ";
			cin >> field;
			switch(field){
				case 1: 
					line = 3;
					column = 1;
					break;
				case 2: 
					line = 3;
					column = 2;
					break;
				case 3: 
					line = 3;
					column = 3;
					break;
				case 4: 
					line = 2;
					column = 1;
					break;
				case 5: 
					line = 2;
					column = 2;
					break;
				case 6: 
					line = 2;
					column = 3;
					break;
				case 7: 
					line = 1;
					column = 1;
					break;
				case 8: 
					line = 1;
					column = 2;
					break;
				case 9: 
					line = 1;
					column = 3;
					break;
			}
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

void description(){
	cout << "Instrukcja" << endl;
	//~ TODO
	cout << "Naciśnij ENTER aby kontynuować" << endl;
	getchar(); getchar();
}

int main(int argc, char **argv)
{
	bool player = false;
	char choose;
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

	while(true){
		system("clear");
		cout << "|-----------------------------------|" << endl;
		cout << "|           Tic-Tac-Toe             |" << endl;
		cout << "|-----------------------------------|" << endl;
		cout << "|           Menu glowne             |" << endl;
		cout << "|[1] Graj.                          |" << endl;
		//cout << "|[2] Instrukcja.                    |" << endl;
		cout << "|[0] Wyjdz.                         |" << endl;
		cout << "|-----------------------------------|" << endl;
		choose=getchar();
		switch(choose){
			case '1':
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
				break;
			//~ case '2':
				//~ description();
				//~ break;
			case '0': exit(0);
			default: 
				cout << "Nie ma takiej opcji!" << endl << "Naciśnij ENTER aby kontynuować" << endl;
				getchar(); getchar();
				break;
		}
	}

	return 0;
}
