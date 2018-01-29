#ifndef UCZEN_H
#define UCZEN_H
class Uczen{
private:
	string imie;
	string nazwisko;
	string klasa;
	int ocena;
public:
	Uczen(string, string);
	void srednia(int);
	void ustaw_klase("3A");
};
#endif
