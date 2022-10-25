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

def capetesipicioare():
    print("Introduceti numarul de gaini: ")
    G = int(input())
    print("Introduceti numarul de oi: ")
    O = int(input())
    nrcapete = G + O
    nrpicioare = G * 2 + O * 4
    print("Numarul de picioare este: ", nrpicioare)
    print("Numarul de capete este: ", nrcapete)


if __name__ == "__main__":
    # adunare2()
    # adunare3()
    capetesipicioare()
