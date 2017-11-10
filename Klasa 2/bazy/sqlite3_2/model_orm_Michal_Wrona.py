# -*- coding: utf-8 -*-

from peewee import *

baza_plik = "pracownicy.sqlite3"

baza = SqliteDatabase(baza_plik)  # ':memory:'


class BazaModel(Model):  # klasa bazowa
    class Meta:
        database = baza


class Klasa(BazaModel):
    id = IntegerField(primary_key=True)
    klasa = CharField(null=False)
    rok_naboru = IntegerField(null=False)
    rok_matury = IntegerField(null=False)

class Ocena(BazaModel):
    id = IntegerField(primary_key=True)
    data = DateField()
    uczen_id = ForeignKeyField(Uczen, related_name='Ocena')
    przedmiot_id = IntegerField(null=False)
    ocena = DecimalField(null=False)

class Uczen(BazaModel):
    id = IntegerField(primary_key=True)
    imie = CharField(null=False)
    nazwisko = CharField(null=False)
    plec = IntegerField(null=False)
    klasa_id = IntegerField(null=False)
    egz_hum = DecimalField(null=False)
    egz_mat = DecimalField(null=False)
    egz_jez = DecimalField(null=False)

class Przedmiot(BazaModel):
    id = IntegerField(primary_key=True)
    przedmiot = CharField(null=False)
    naucz = CharField(null=False)
    imienaucz = CharField(null=False)
    plec = IntegerField(null=False)

baza.connect()  # nawiązujemy połączenie z bazą
