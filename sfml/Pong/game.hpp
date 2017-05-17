#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cmath>
#include "paletka.hpp"
#include "pilka.hpp"

class Game
{
private:
    sf::Clock zegar;
    sf::RenderWindow okno;
    sf::Event event;

    float deltaT;

public:
    Game(int, int); //konstruktor
    ~Game(); //dekonstruktor
};
