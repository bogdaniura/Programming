def suma():
    a = input("Introduceti primul numar: ")
    b = input("Introduceti al doilea numar: ")
    print("Suma este: ", int(a) + int(b))


def diferenta():
    a = input("Introduceti primul numar: ")
    b = input("Introduceti al doilea numar: ")
    print("Diferenta este: ", int(a)-int(b))


def impartire():
    a = input("Introduceti primul numar: ")
    b = input("Introduceti al doilea numar: ")
    print("Rezultatul impartirii este: ", int(a) / int(b))


def inmultire():
    a = input("Introduceti primul numar: ")
    b = input("Introduceti al doilea numar: ")
    print("Produsul este: ", int(a) * int(b))


def arie():
    c1 = input("Introduceti primul numar: ")
    c2 = input("Introduceti al doilea numar: ")
    aria = int(c1) * int(c2) / 2
    print("Aria este: ", aria)


def perimetru():
    l1 = input("Introduceti primul numar: ")
    l2 = input("Introduceti al doilea numar: ")
    l3 = input("Introduceti al treilea numar: ")
    perimetru = int(l1) + int(l2) + int(l3)
    print("Perimetrul este: ", perimetru)


def ariedr():
    l1 = input("Introduceti primul numar: ")
    l2 = input("Introduceti al doilea numar: ")
    ariedr = int(l1) * int(l2)
    print("Perimetrul dreptunghiului este: ", ariedr)


if __name__ == '__main__':
    print('10%3 -> ', 10%3)
    # suma()
    # diferenta()
    # inmultire()
    # impartire()
    # arie()
    # perimetru()
    # ariedr()
