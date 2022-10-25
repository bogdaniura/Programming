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
    G = int(input())
    print("Introduceti numarul de oi: ")
    O = int(input())
    nrcapete = G + O
    nrpicioare = G * 2 + O * 4
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


if __name__ == "__main__":
    # adunare2()
    # adunare3()
    # capete_picioare()
    # arie_volum_cub()
    eliminare_cifra()