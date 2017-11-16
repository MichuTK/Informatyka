# -*- coding: utf-8 -*-

from peewee import *

baza_plik = "szkola.db"

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

class Uczen(BazaModel):
    imie = CharField(null=False)
    nazwisko = CharField(null=False)
    plec = IntegerField(null=False)
    klasa_id = ForeignKeyField(Klasa, related_name='klasa_id')
    egzhum = DecimalField(decimal_places=2, default=0, null=False)
    egzmat = DecimalField(decimal_places=2, default=0, null=False)
    egzjez = DecimalField(decimal_places=2, default=0, null=False)

class Ocena(BazaModel):
    datad = DateField()
    uczen_id = ForeignKeyField(Uczen, related_name='uczen_id')
    przedmiot_id = ForeignKeyField(Przedmiot, related_name='przedmiot_id')
    ocena = DecimalField(null=False)

baza.connect()  # nawiązujemy połączenie z bazą

def kwerenda_a():
    query = (Uczen
             .select(Uczen.imie, Uczen.nazwisko, Klasa.nazwa)
             .join(Klasa)
             .where(Klasa.nazwa=='1A')
             )

    for obj in query:
        print(obj.imie, obj.nazwisko, obj.nazwa)


