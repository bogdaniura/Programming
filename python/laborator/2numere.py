def adunare2():
    print("Introduceti un numar natural de cel putin doua cifre: ")
    n = int(input())
    unitati = n % 10
    zeci = (n % 100) // 10
    print("Numarul rezultat prin adunarea cifrelor zecilor si unitatilor este: ", zeci + unitati)


def adunare3():
    print("Introduceti un numar natural de 3 cifre: ")
    n = int(input())
    unitati = n % 10
    zeci = (n % 100) // 10
    sute = n // 100
    print("Numarul rezultat prin adunarea cifrelor sutelor, zecilor si unitatilor este: ", sute + zeci + unitati)


def capete_picioare():
    print("Introduceti numarul de gaini: ")
    g = int(input())
    print("Introduceti numarul de oi: ")
    o = int(input())
    nrcapete = g + o
    nrpicioare = o * o + o * 4
    print("Numarul de picioare este: ", nrpicioare)
    print("Numarul de capete este: ", nrcapete)


def arie_volum_cub():
    print("Introduceti lungimea laturii cubului: ")
    latura = int(input())
    aria = 6 * latura ** 2
    volum = latura ** 3
    print("Aria cubului este: ", aria)
    print("Volumul cubului este: ", volum)


def eliminare_cifra():
    print("Introduceti un numar de exact 3 cifre: ")
    n = int(input())
    unitati = n % 10
    sute = n // 100
    nce = sute * 10 + unitati
    print("Numarul generat este: ", nce)


def calcul_timp():
    print("Introduceti ora: ")
    ora = int(input())
    print("Introduceti minutele: ")
    minutele = int(input())
    ora_noua = ora * 60 + minutele
    print("Ora noua este: ", ora_noua//60, ":", ora_noua % 60)


def produs3():
    print("Introduceti un numar natural de 3 cifre: ")
    n = int(input())
    unitati = n % 10
    # zeci = (n % 100) // 10
    sute = n // 100
    print("Produsul cifrelor sutelor si unitatilor este: ", sute * unitati)


def globuri():
    print("Introduceti numarul de globuri rosii: ")
    gla = int(input())
    glr = 2 * gla
    glv = glr - 3
    print("Numerul de globuri este: ", gla + glr + glv)


def gauss():
    print("Introduceti un numar natural: ")
    a = int(input())
    print("Suma lui Gauss este: ", a * (a + 1) // 2)


def nranimale():
    print("Introduceti numarul de caini: ")
    c = int(input())
    p = c * 2
    g = p * 2
    print("Numarul de animale este: ", c + p + g)


if __name__ == "__main__":
    # adunare2()
    # adunare3()
    # capete_picioare()
    # arie_volum_cub()
    # eliminare_cifra()
    # calcul_timp()
    # produs3()
    # globuri()
    # gauss()
    nranimale()
