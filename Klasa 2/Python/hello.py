#!/usr/bin/env python
# -*- coding: utf-8 -*-

rok = 2017
data_powstania = 1991

def main(args):
    imie = input("Podaj imie: ")
    print ("Witaj", imie)
    wiek = int(input("Ile masz lat? "))
    print ("Urodziłeś się w" , rok-wiek, "roku")
    
    if wiek > (rok-data_powstania):
        print("Jestem młodszy!")
    elif wiek < (rok-data_powstania):
        print("Jestem starszy!")
    else:
        print("Mamy tyle samo lat!")
        
    print ("Liczby parzyste (0-100): ")
    liczba = 0
    while liczba < 101:
        print (liczba)
        liczba += 2
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
