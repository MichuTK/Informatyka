#include <SFML/Graphics.hpp>
#include <cmath>

class Paletka
{
private:
	sf::Vector2f poz, roz;
	sf::Vector2i pozMysz;
	sf::Vector2f pozPilka;
	sf::RectangleShape pal;

	float V;

public:
	Paletka(sf::Vector2f rozPal, sf::Vector2f pozPal, float predkosc, sf::Color kolor = sf::Color::Red);
	~Paletka();

	sf::RectangleShape zwPal();

	void wys(sf::RenderWindow & okno);
	void sterowanie(sf::RenderWindow & okno, float czas);
	void sterowanieAI(sf::RenderWindow & okno, float czas, sf::Vector2f pilka);

};
