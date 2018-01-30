#!/usr/bin/env python
# -*- coding: utf-8 -*-


def main(args):
    stos = []
    onp = input("Podaj wyrażenie ONP, oddzielając operandy i operatory spacjami: ")

    onp = onp.split(" ")

    for wyraz in onp:
        if wyraz.isdigit():
            stos.append(wyraz)
        else:
            a = stos.pop()
            b = stos.pop()
            stos.append(eval(str(b) + wyraz + str(a)))

    #eval("12 + 13")
    print("Wynik: ", stos.pop())

    return 0


if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
