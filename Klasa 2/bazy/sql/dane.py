#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  dane.py

import csv

def dane_z_pliku(plik, delimiter='\t'):
    dane = [] #pusta lista
    with open(plik,'r') as plikcsv:
        tresc = csv.reader(plikcsv, delimiter=delimiter)
    
        for rekord in tresc:
            dane.append(rekord)
    return(dane)


def wyczysc_dane(dane, pole):
    for i, rekord in enumerate(dane):
        el = rekord[pole]
        el - el.replace('zł', '')
        el - el.replace('', '')
        el - el.replace(',', '.')
        print(el)
    
    return ''


def main(args):
    dane = dane_z_pliku('pracownicy.txt')
    pracownicy = wyczysc_dane(dane, 5)
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
