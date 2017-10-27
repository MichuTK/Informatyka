#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sqlite3

def wyniki(cur):
    wyniki = cur.fetchall() #pobierz wszystkie wiersze
    for row in wyniki:
        print(tuple(row))

def kw_a(cur):
    cur.execute("""
        SELECT Imie, Nazwisko, tbKlasy.Klasa
        FROM tbUczniowie, tbKlasy
        WHERE tbUczniowie.KlasaID = tbKlasy.IDKlasy
        AND tbKlasy.Klasa = '1A'
    """)
    wyniki(cur)
        
def kw_b(cur):
    cur.execute("""
        SELECT MAX(EgzHum)
        FROM tbUczniowie
    """)
    wyniki(cur)
    
def kw_c(cur):
    cur.execute("""
        SELECT AVG(EgzMat)
        FROM tbUczniowie, tbKlasy
        WHERE tbUczniowie.KlasaID = tbKlasy.IDKlasy
        AND tbKlasy.Klasa = '1A'
    """)
    wyniki(cur)
    
def kw_d(cur):
    cur.execute("""
        SELECT Imie, Nazwisko, Ocena
        FROM tbUczniowie, tbOceny
        WHERE tbOceny.UczenID = tbUczniowie.IDUcznia
        AND tbUczniowie.Nazwisko = 'Nowak'
    """)
    wyniki(cur)
    
def kw_e(cur):
    cur.execute("""
<<<<<<< HEAD
        SELECT AVG(Ocena)
        FROM tbOceny
        WHERE PrzedmiotID = 6
        AND strftime('%m', Datad) LIKE '10'
        """)
        ##AND Datad > '2012-10-01'
        ##AND Datad < '2012-10-31'
    wyniki(cur)

def kw_f(cur):
    cur.execute("""
        UPDATE tbUczniowie
        SET EgzJez = ?
        WHERE Imie = 'Paulina'
        AND Nazwisko = 'Dziedzic'
    """, [35])
    
def kw_g(cur):
    cur.execute("""
        
    """)
    
def dodaj(cur):
    cur.execute("""
        INSERT INTO tbKlasy
        VALUES (?, ?, ?, ?)
    """, [None, '3C', 2015, 2017])

def aktualizuj(cur):
    cur.execute("""
        UPDATE tbKlasy
        SET klasa = ?
        WHERE idKlasy = ?
    """, ['3D', 13])
    

def usun(cur):
    cur.execute('DELETE FROM tbKlasy WHERE klasa = ? AND roknaboru = ?', ['3B', 2015])
=======
        SELECT AVG(tbOceny.Ocena)
        FROM tbOceny, tbPrzedmioty
        WHERE tbOceny.PrzedmiotID = tbPrzedmioty.IDPrzedmiotu
        AND tbPrzedmioty.Przedmiot = 'fizyka'
        AND tbOceny.Datad > '2012-10-01'
        AND tbOceny.Datad < '2012-10-31'
    """)
    wyniki(cur)
>>>>>>> 692b0129102215b3c696b02c6795707ab6fbcf07

def dodaj(cur):
    cur.execute("""
        INSERT INTO tbklasy
        VALUES (?, ?, ?, ?)
    """, [None, '3C', 2015, 2017])
    
def aktu(cur):
    cur.execute("""
        UPDATE tbklasy
        SET klasa = ?
        WHERE idklasy = ?
    """, ['3D', 13])
    
def usun(cur):
    cur.execute('DELETE FROM tbklasy WHERE klasa = ? AND roknaboru = ?', ['3B', 2015])

def main(args):
    con = sqlite3.connect('szkola.db')
    cur = con.cursor() #utworzenie kursora
    con.row_factory = sqlite3.Row
    
    #dodaj(cur)
<<<<<<< HEAD
    #aktualizuj(cur)
    #usun(cur)
    kw_f(cur)
    con.commit()
    #wyniki(cur.execute('SELECT * FROM tbKlasy'))
    wyniki(cur.execute("""SELECT * FROM tbUczniowie WHERE Imie = 'Paulina' AND Nazwisko = 'Dziedzic'"""))
    
=======
    #aktu(cur)
    usun(cur)
    con.commit()
    wyniki(cur.execute('SELECT * FROM tbklasy'))
>>>>>>> 692b0129102215b3c696b02c6795707ab6fbcf07
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
