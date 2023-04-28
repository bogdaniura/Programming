def suma_cuvant(cuvant):
    ht = {
        "a": 200,
        "b": 300,
        "c": 1,
        "d": 40,
        "e": 50,
        "f": 60,
        "g": 70,
        "h": 80,
        "i": 1,
        "j": 2,
        "k": 3,
        "l": 4,
        "m": 5,
        "n": 6,
        "o": 7,
        "p": 8,
        "q": 9,
        "r": 10,
        "s": 11,
        "t": 12,
        "u": 13,
        "v": 14,
        "w": 15,
        "x": 16,
        "y": 17,
        "z": 18,
    }
    suma = 0
    # ht[key] = value #adaugare element in hash table

    for elem in cuvant:
        suma += ht[elem]
    return suma


def val_cuvant(cuvant):  # nefunctionala
    ht = {
        "a": 200,
        "b": 300,
        "c": 1,
        "d": 40,
        "e": 50,
        "f": 60,
        "g": 70,
        "h": 80,
        "i": 1,
        "j": 2,
        "k": 3,
        "l": 4,
        "m": 5,
        "n": 6,
        "o": 7,
        "p": 8,
        "q": 9,
        "r": 10,
        "s": 11,
        "t": 12,
        "u": 13,
        "v": 14,
        "w": 15,
        "x": 16,
        "y": 17,
        "z": 18,
    }
    val = 0

    for elem in range(len(cuvant) - 1):
        val = val + ht[elem] - ht[elem + 1]
        print(val, ht[elem], ht[elem + 1])
    return val


def nume_max():
    lista_nume = ["ion", "vasile", "gheorghe", "ioana", "maria", "ana", "laurentiu"]
    val_max = 0
    nume_max = ""
    for nume in lista_nume:
        val_nume = suma_cuvant(nume)
        if val_nume > val_max:
            val_max = val_nume
            nume_max = nume
    return nume_max


def nume_min():  # posibil nefuntioana, vezi val_cuvant()
    lista_nume = ["gheorghe", "ion", "vasile", "ioana", "maria", "ana", "laurentiu"]
    val_min = 999999
    nume_min = ""
    for nume in lista_nume:
        val_nume = val_cuvant(nume)
        # print(nume, val_nume, val_min)
        if val_nume < val_min:
            val_min = val_nume
            nume_min = nume
    return nume_min


def generare_ht(tip=0):
    litere = [
        "a",
        "b",
        "c",
        "d",
        "e",
        "f",
        "g",
        "h",
        "i",
        "j",
        "k",
        "l",
        "m",
        "n",
        "o",
        "p",
        "q",
        "r",
        "s",
        "t",
        "u",
        "v",
        "w",
        "x",
        "y",
        "z",
    ]
    start = 7
    lista_noua = []
    for i in range(start, len(litere)):
        lista_noua.append(litere[i])
    for i in range(0, start):
        lista_noua.append(litere[i])
    for i in range(len(litere)):
        if tip == 1:
            ht[litere[i]] = lista_noua[i]
        else:
            ht[litere[i]] = litere[i]

    print(litere, lista_noua, sep="\n")

    return ht


def criptare(propozitie, tip):
    generare_ht(tip)
    litere = [
        "a",
        "b",
        "c",
        "d",
        "e",
        "f",
        "g",
        "h",
        "i",
        "j",
        "k",
        "l",
        "m",
        "n",
        "o",
        "p",
        "q",
        "r",
        "s",
        "t",
        "u",
        "v",
        "w",
        "x",
        "y",
        "z",
    ]
    propozitie_criptata = ""
    for elem in propozitie:
        if elem in litere:
            propozitie_criptata += ht[elem]
        else:
            propozitie_criptata += elem

    return propozitie_criptata


if __name__ == "__main__":
    ht = {}
    # print(nume_min())
    print(
        criptare("the quick brown fox jumped over a lazy dog;", 1)
    )  # tip = 0 for encryption, tip = 1 for decryption
