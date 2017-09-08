#!/usr/bin/env python
# -*- coding: utf-8 -*-

rok = 2017
data_powstania = 1991

def parzyste(zakres):
    ile = list(range(0, zakres+1, 2))
    print("Liczby parzyste: ")
    print(ile)
    return len(ile)
    
    
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
        
    zakres = int(input("Podaj zakres: "))
    print("Ilosc liczb parzystych: ", parzyste(zakres))
    
    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
