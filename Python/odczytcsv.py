#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  odczytcsv.py
#  

import csv

def main(args):
    plik = open("samochody.txt")
    tekst = plik.read()
    plik.close()
    print(tekst)
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
