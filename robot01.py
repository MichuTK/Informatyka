#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg


class Robot:

    def act(self, game):
        # ilu_wrogow = 0
        lista_wrogow = []

        # jeżeli obok są przeciwnicy, atakuj
        # wersja z pętlą przeglądającą wszystkie pola zajęte przez roboty
        for poz, robot in game.robots.iteritems():
            if robot.player_id != self.player_id:
                if rg.dist(poz, self.location) <= 1:
                    lista_wrogow.append(poz)
                    # ilu_wrogow += 1
                    # return ['attack', poz]
        if len(lista_wrogow) > 2:
            return ['suicide']
        elif len(lista_wrogow):
            return ['attack', lista_wrogow[0]]

        # jeżeli jesteś w środku, broń się
        if self.location == rg.CENTER_POINT:
            return ['guard']

        # idź do środka planszy, ruch domyślny
        return ['move', rg.toward(self.location, rg.CENTER_POINT)]
