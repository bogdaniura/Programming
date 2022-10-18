def suma():
    print("Suma este: ", int(a) + int(b))


def diferenta():

    print("Diferenta este: ", int(a)-int(b))


def impartire():
    print("Rezultatul impartirii este: ", int(a) / int(b))


def inmultire():
    print("Produsul este: ", int(a) * int(b))

if __name__ == '__main__':
    a = input("Introduceti primul numar: ")
    b = input("Introduceti al doilea numar: ")
    suma()
    diferenta()
    inmultire()
    impartire()

    