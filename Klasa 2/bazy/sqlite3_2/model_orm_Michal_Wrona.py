# -*- coding: utf-8 -*-

from peewee import *

baza_plik = "pracownicy.sqlite3"

baza = SqliteDatabase(baza_plik)  # ':memory:'


class BazaModel(Model):  # klasa bazowa
    class Meta:
        database = baza


class Klasa(BazaModel):
    nazwa = CharField(null=False)
    rok_naboru = IntegerField(null=False)
    rok_matury = IntegerField(null=False)
    
class Przedmiot(BazaModel):
    nazwa = CharField(null=False)
    imien = CharField(null=False)
    nazwiskon = CharField(null=False)
    plecn = IntegerField(null=False)

class Ocena(BazaModel):
    datad = DateField()
    uczen_id = ForeignKeyField(Uczen, related_name='id')
    przedmiot_id = ForeignKeyField(Przedmiot, related_name='id')
    ocena = DecimalField(null=False)

class Uczen(BazaModel):
    imie = CharField(null=False)
    nazwisko = CharField(null=False)
    plec = IntegerField(null=False)
    klasa_id = ForeignKeyField(Klasa, related_name='id')
    egzhum = DecimalField(decimal_places=2, default=0, null=False)
    egzmat = DecimalField(decimal_places=2, default=0, null=False)
    egzjez = DecimalField(decimal_places=2, default=0, null=False)



baza.connect()  # nawiązujemy połączenie z bazą
