#! /usr/bin/env python
# -*- coding: utf-8 -*-

import rg


class Robot:
    # typy pól: 'spawn', 'normal', 'obstacle', 'invalid'
    # rg.loc_types() - zwaraca typ pola
        # return ['guard']
        # return ['suicide']
        # return ['move', ()]
        # return ['attack']

    def act(self, game):
        # funkcja zwróci prawdę, jeżeli "poz" wskazuje punkt wejścia
        def czy_wejscie(poz):
            if 'spawn' in rg.loc_types(poz):
                return True
            return False
        lista_wrogow_obok = []

        def czy_wrog(poz):
            if game.robots.get(poz) is not None:
                if game.robots[poz].player_id != self.player_id:
                    return True
            return False

        # funkcja zwróci prawdę,
        # jeżeli w odległości 2 kroków z przodu jest wróg
        def zprzodu(l1, l2):
            if rg.wdist(l1, l2) == 2:
                if abs(l1[0] - l2[0]) == 1:
                    return False
                else:
                    return True
            return False

        # jeżeli obok są przeciwnicy, atakuj
        # wersja z pętlą przeglądającą wszystkie pola zajęte przez roboty
        for poz, robot in game.robots.iteritems():
            if robot.player_id != self.player_id:   # rozpoznanie wroga
                if rg.dist(poz, self.location) <= 1:
                    lista_wrogow_obok.append(poz)
                    # ilu_wrogow += 1
                    # return ['attack', poz]

        print (lista_wrogow_obok)

        # rg.dist() - odległość między dwoma lokalizacjami
        # rg.toward() - najkrótsza droga pomiędzy dwoma lokalizacjami

        if czy_wejscie(self.poz):
            return ['move', rg.toward(self.location, rg.CENTER_POINT)]

        def miedzypole(p1, p2):
            return (int((p1[0] + p2[0]) / 2), int((p1[1] + p2[1]) / 2))

        for poz, robot in game.get('robots').items():
            if czy_wrog(poz):
                if rg.wdist(poz, self.location) == 2:
                    if zprzodu(poz, self.location):
                        return ['attack', miedzypole(poz, self.location)]
                    if rg.wdist(rg.toward(loc, rg.CENTER_POINT), self.location) == 1:
                        return ['attack', rg.toward(poz, rg.CENTER_POINT)]
                    else:
                        return ['attack', (self.location[0], poz[1])]

        if len(lista_wrogow_obok) > 2 and self.hp < 27:
            return ['suicide']
        elif len(lista_wrogow_obok):
            return ['attack', lista_wrogow_obok[0]]

        # idź do środka planszy, ruch domyślny
        dystansCP = rg.wdist(self.location, rg.CENTER_POINT)
        # if czy_wejscie(self.poz):
        if dystansCP > 6:
            return ['move', rg.toward(self.location, rg.CENTER_POINT)]

        # if self.location == rg.CENTER_POINT:
        #     return ['guard']

        return ['guard']
