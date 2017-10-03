#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#baza
#  

import sqlite3

def main(args):
    con = sqlite3.connect('pracownicy.sqlite3')
    cur = con.cursor() #utworzenie kursora
    
    #utworzenie tabel w bazie danych
    with open('pracownicy_z1geany.sql', 'r') as plik:
        skrypt = plik.read()
        cur.executescript(skrypt)
        
    
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
