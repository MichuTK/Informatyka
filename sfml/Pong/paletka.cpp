#include "paletka.hpp"

Paletka::Paletka(sf::Vector2f rozPal, sf::Vector2f pozPal, float Vel, sf::Color kolor)
{
    roz.x = abs(rozPal.x);
    roz.y = abs(rozPal.y);
    poz.x = abs(pozPal.x);
    poz.y = abs(pozPal.y);
    V = Vel;

    pal.setSize(roz);
    pal.setPosition(poz);
    pal.setOrigin(sf::Vector2f(roz.x / 2, roz.y / 2));
    pal.setFillColor(kolor);
}

Paletka::~Paletka()
{}

sf::RectangleShape Paletka::zwPal()
{
	return pal;
}

void Paletka::wys(sf::RenderWindow & okno)
{
	okno.draw(pal);
}


void Paletka::sterowanie(sf::RenderWindow & okno, float T)
{
    /*pozMysz = sf::Mouse::getPosition(okno);

    if (pozMysz.x != pal.getPosition().x)
    {
        if (pozMysz.x < pal.getPosition().x && pal.getPosition().x - pal.getOrigin().x >= 0)
            pal.move(sf::Vector2f(-V * T, 0.f));
        if (pozMysz.x > pal.getPosition().x && pal.getPosition().x + pal.getOrigin().x <= okno.getSize().x)
            pal.move(sf::Vector2f(V * T, 0.f));
    }*/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        pal.move(sf::Vector2f(-V * T, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        pal.move(sf::Vector2f(V * T, 0.f));
    }
}

void Paletka::sterowanieAI(sf::RenderWindow & okno, float T, sf::Vector2f pilka)
{
    /*if (pilka.x < pal.getPosition().x - pal.getOrigin().x || pilka.x > pal.getPosition().x + pal.getOrigin().x)
    {
        if (pilka.x < pal.getPosition().x && pal.getPosition().x - pal.getOrigin().x >= 0)
            pal.move(sf::Vector2f(-V * T, 0.f));
        if (pilka.x > pal.getPosition().x && pal.getPosition().x + pal.getOrigin().x <= okno.getSize().x)
            pal.move(sf::Vector2f(V * T, 0.f));
    }*/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        pal.move(sf::Vector2f(-V * T, 0.f));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        pal.move(sf::Vector2f(V * T, 0.f));
    }
}
