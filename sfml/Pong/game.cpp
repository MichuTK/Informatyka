#include "game.hpp"

Game::Game(int szer, int wys)
{
    okno.create(sf::VideoMode(abs(szer), abs(wys), 32), "Pong", sf::Style::Close);
    okno.setFramerateLimit(60);


    sf::Vector2f rozPal(150, 30);
    sf::Vector2f rozPalPion(30, 150);

    Paletka gracz(rozPal, sf::Vector2f(okno.getSize().x / 2, okno.getSize().y - (okno.getSize().y / 10)), 2000.f, sf::Color(132, 255, 38));
    Paletka gracz1(rozPalPion, sf::Vector2f(okno.getSize().x - (okno.getSize().x / 10), okno.getSize().y / 2), 2000.f, sf::Color(132, 255, 38));
    Paletka wrog(rozPal, sf::Vector2f(okno.getSize().x / 2, (okno.getSize().y / 10)), 2000.f, sf::Color(253, 28, 43));
    Pilka pilka(okno);
    //Pilka pilka2(okno);
    //Pilka pilka3(okno);


    while (okno.isOpen())
    {
        deltaT = zegar.restart().asSeconds();

        while (okno.pollEvent(event)) // nasłuchiwanie wydarzeń
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                okno.close();

            if (event.type == event.Closed)
                okno.close();
        }

        gracz.sterowanie(okno, deltaT);
        wrog.sterowanieAI(okno, deltaT, pilka.zwPoz());

        pilka.poruszanie(deltaT);
        pilka.kolizjaPaletka(gracz.zwPal());
        pilka.kolizjaPaletka(wrog.zwPal());
        pilka.kolizjaSciana(okno);
        pilka.Punkt(gracz.zwPal(), wrog.zwPal());

        /*pilka2.poruszanie(deltaT);
        pilka2.kolizjaPaletka(gracz.zwPal());
        pilka2.kolizjaPaletka(wrog.zwPal());
        pilka2.kolizjaSciana(okno);
        pilka2.Punkt(gracz.zwPal(), wrog.zwPal());

        pilka3.poruszanie(deltaT);
        pilka3.kolizjaPaletka(gracz.zwPal());
        pilka3.kolizjaPaletka(wrog.zwPal());
        pilka3.kolizjaSciana(okno);
        pilka3.Punkt(gracz.zwPal(), wrog.zwPal());*/

        okno.clear(sf::Color( 109, 163, 152));
        pilka.wysPilka(okno);
        //pilka2.wysPilka(okno);
        //pilka3.wysPilka(okno);
        gracz.wys(okno);
        gracz1.wys(okno);
        wrog.wys(okno);
        okno.display();
    }
}

Game::~Game()
{}
