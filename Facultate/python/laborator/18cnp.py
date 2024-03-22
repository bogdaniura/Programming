# definiti o fct care cauta intr-o lista si returneaza poz elem sau none
def cautare(lista, e):
    for i in range(len(lista)):
        if lista[i] == e:
            return i
    return -1


def generareC(sir):
    nr = "279146358279"
    suma = 0
    for i in range(len(sir)):
        suma += int(sir[i]) * int(nr[i])
    rest = suma % 11
    if rest < 10:
        return str(rest)
    else:
        return str(1)


def generare_cnp(gen: str, an: int, luna: int, zi: int, judet: int, nnn: int):
    cnp = ""
    if gen == "M" or gen == "m" or gen == "masculin":
        if an < 2000:
            cnp += "1"
        else:
            cnp += "5"
    else:
        if an < 2000:
            cnp += "2"
        else:
            cnp += "6"
    if an < 2000:
        an -= 1900
    else:
        an -= 2000
    if an < 10:
        cnp += "0"
    cnp += str(an)
    if luna < 10:
        cnp += "0"
    cnp += str(luna)
    if zi < 10:
        cnp += "0"
    cnp += str(zi)
    if judet < 10:
        cnp += "0"
    cnp += str(judet)
    if nnn < 10:
        cnp += "00"
    elif nnn < 100:
        cnp += "0"
    else:
        cnp += ""
    cnp += str(nnn)
    cnp += str(generareC(cnp))
    return cnp


if __name__ == "__main__":
    # lista = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    # print(cautare(lista, e=int(input())))

    print(generare_cnp("m", 2003, 10, 19, 24, 1))
