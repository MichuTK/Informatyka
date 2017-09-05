#include "pilka.hpp"

Pilka::Pilka(sf::RenderWindow & okno, float promien, float vel, sf::Color kolor)
{
    r = abs(promien);
    V = vel;
    srodek = sf::Vector2f(okno.getSize().x / 2, okno.getSize().y / 2);

    pilka.setRadius(r);
    pilka.setPointCount(50);
    pilka.setFillColor(kolor);
    pilka.setOrigin(r, r);
    pilka.setPosition(srodek);

    buffer.loadFromFile("resources/ball.wav");
    zderzenie.setBuffer(buffer);

    wyzKat();
}

Pilka::~Pilka()
{}

sf::Vector2f Pilka::zwPoz()
{
	return pilka.getPosition();
}

void Pilka::wysPilka(sf::RenderWindow & okno)
{
	okno.draw(pilka);
}

void Pilka::poruszanie(float T)
{
	pilka.move(sf::Vector2f(sin(kat) * V * T, cos(kat) * V * T));
}


void Pilka::wyzKat()
{
    srand(time(NULL));

    do
    {
        kat = (rand() % 360) * 2 * pi / 360;
    } while (abs(cos(kat)) < 0.7f);
}

void Pilka::kolizjaSciana(sf::RenderWindow & okno)
{
    if (pilka.getPosition().x - pilka.getOrigin().x < 0.f)
    {
        zderzenie.play();
        kat = -kat;
        pilka.setPosition(2*r + 1.f, pilka.getPosition().y);
    }

    if (pilka.getPosition().x + pilka.getOrigin().x > okno.getSize().x)
    {
        zderzenie.play();
        kat = -kat;
        pilka.setPosition(okno.getSize().x - 2*r - 1.f, pilka.getPosition().y);
    }

}

void Pilka::kolizjaPaletka(sf::RectangleShape pal)
{
    if (czyKolizja(pal))
    {
        zderzenie.play();
        if(pilka.getPosition().x > pal.getPosition().x)
            kat = pi - kat + (rand() % 20) * pi / 180;
        else
            kat = pi - kat - (rand() % 20) * pi / 180;
    }

}

void Pilka::Punkt(sf::RectangleShape gracz, sf::RectangleShape wrog)
{
    if (pilka.getPosition().y < wrog.getPosition().y - wrog.getOrigin().y)
        restart();

    if (pilka.getPosition().y > gracz.getPosition().y + gracz.getOrigin().y)
        restart();
}

void Pilka::restart()
{
    wyzKat();
    pilka.setPosition(srodek);

}

bool Pilka::czyKolizja(sf::RectangleShape & pal)
{
	return (pal.getGlobalBounds().intersects(pilka.getGlobalBounds()));
}
