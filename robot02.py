#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg


class Robot:

    def act(self, game):

        # wszystkie pola
        wszystkie = {(x, y) for x in xrange(19) for y in xrange(19)}
        # punkty wejścia
        wejscia = {poz for poz in wszystkie if 'spawn' in rg.loc_types(poz)}
        # pola zablokowane
        zablokowane = {poz for poz in wszystkie if 'obstacle' in rg.loc_types(poz)}
        # pola zajęte przez nasze roboty
        przyjaciele = {poz for poz in game.robots if game.robots[poz].player_id == self.player_id}
        # pola zajęte przez wrogów
        wrogowie = set(game.robots) - przyjaciele
        # pola sąsiednie
        sasiednie = set(rg.locs_around(self.location)) - zablokowane
        # pola sąsiednie zajęte przez wrogów
        wrogowie_obok = sasiednie & wrogowie


        for wrog in wrogowie:
            if rg.wdist(poz, self.location) == 2:
                # ruch = działanie xD



        # działanie domyślne:
        ruch = ['move', rg.toward(self.location, rg.CENTER_POINT)]

        # jeżeli jesteś w punkcie wejścia, opuść go
        if self.location in wejscia:
            ruch = ['move', rg.toward(self.location, rg.CENTER_POINT)]

        # jeżeli jesteś w środku, broń się
        if self.location == rg.CENTER_POINT:
            ruch = ['guard']

        # jeżeli obok są przeciwnicy, atakuj
        if len(wrogowie_obok) > 2 and self.hp < 27:
            ruch = ['suicide']
        else wrogowie_obok:
            ruch = ['attack', wrogowie_obok.pop()]

        return ruch
