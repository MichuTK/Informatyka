#!/usr/bin/env python
# -*- coding: utf-8 -*-


def szyfrVigenere(tekst, klucz):
    szyfrogram = ""

    for i in range(len(tekst)):
        szyfrogram += chr((((ord(tekst[i]) - 65)) + (ord(klucz[i % len(klucz)]) - 65)) % 26 + 65)

    print szyfrogram


def main(args):
    tekst = raw_input("Tekst do zaszyfrowania: ")
    klucz = raw_input("Podaj klucz: ")

    tekst = tekst.upper().replace(' ', '')
    klucz = klucz.upper().replace(' ', '')

    print tekst

    szyfrVigenere(tekst, klucz)
    return 0


if __name__ == '__main__':
    import sys
sys.exit(main(sys.argv))
