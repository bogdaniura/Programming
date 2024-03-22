# se da un sir de nr naturale - sa se calculeze numarul de aparitii ale cifrei 5


def adunare():
    a = int(input("introduceti primul numar: "))
    b = int(input("introduceti al doilea numar: "))
    print("a + b = ", a + b)


def scadere():
    a = int(input("introduceti primul numar: "))
    b = int(input("introduceti al doilea numar: "))
    print("a - b = ", a - b)


def inmultire():
    a = int(input("introduceti primul numar: "))
    b = int(input("introduceti al doilea numar: "))
    print("a * b = ", a * b)


def impartire():
    a = int(input("introduceti primul numar: "))
    b = int(input("introduceti al doilea numar: "))
    print("a / b = ", a / b)


def meniu():
    print(
        "apasati 1 pt adunare, 2 pt scadere, 3 pt inmultire, 4 pt impartire, 5 pt incadrare, 6 pt sir5, 7 pt lista5"
    )
    opt = (
        input().strip()
    )  # elimina spatiile de la inceput si de la sfasit, daca ele exista
    if opt == "1":
        print("adunare")
        adunare()
    else:
        if opt == "2":
            print("scadere")
            scadere()
        else:
            if opt == "3":
                print("inmultire")
                inmultire()
            else:
                if opt == "4":
                    print("impartire")
                    impartire()
                else:
                    if opt == "5":
                        print(incadrare)
                        incadrare()
                    else:
                        if opt == "6":
                            print("sir5")
                            sir5()
                        else:
                            if opt == "7":
                                print("lista5")
                                lista5()
                            else:
                                print("optiunile disponibile sunt 1, 2, 3, 4, 5, 6, 7")


def meniuloop():
    exit_ = ""
    while exit_ != "0":
        meniu()
        print("pentru iesire tastati '0'")
        exit_ = input().strip()


def incadrare():
    print("introduceti un numar pentru incadrare in domeniu: ")
    nr = int(input())
    if nr < 4000:
        print("mic")
    else:
        if nr < 8000:
            print("mediu")
        else:
            if nr > 8000:
                print("mare")


def sir5():
    count = 0
    print("introduceti sirul de numere naturale")
    sir = input()
    for index in range(0, len(sir), 1):
        if sir[index] == "5":
            count += 1
            print(sir[index])
    print("numarul de aparitii a cifrei 5 este: ", count)
    # print(sir.count("5"))


def lista5():
    count = 0
    print("introduceti sirul de numere naturale despartit prin virgula")
    l = input().split(",")
    for index in range(0, len(l), 1):
        if l[index] == "5":
            count += 1
            print(l[index])
    print("numarul de aparitii al lui 5 este: ", count)
    # print(sir.count("5"))


def fibonacci():
    i = int(input())
    f1, f2 = 0, 1
    print(0, 1, sep="\n")
    for index in range(3, i + 1):
        f3 = f1 + f2
        f1 = f2
        f2 = f3
        print(f3)


if __name__ == "__main__":
    # meniuloop()
    fibonacci()
