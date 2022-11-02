def inlocuire():
    sir = input()
    sirnou = ""
    for caracter in sir:
        if caracter in "aeiou":
            print(caracter.upper())
            sirnou += caracter.upper()
        else:
            print(caracter)
            sirnou += caracter
    print(sirnou)


def transformare():
    cuvant = input()
    cuvantnou = ""
    index = 0
    for caracter in cuvant:
        if index == 0 or index == len(cuvant) - 1:
            print(caracter.upper())
            cuvantnou += caracter.upper()
        else:
            print(caracter)
            cuvantnou += caracter
        index += 1
    print(cuvantnou)


def half_sort():
    lista = [34, 0, 2, 5, 3, 300, 56]
    jumatate = len(lista) // 2
    list1 = lista[:jumatate:]
    print(list1)
    list2 = lista[jumatate::]
    print(list2)
    list1.sort()
    print(list1)
    list2.sort(reverse=True)
    print(list2)
    lista = list1 + list2
    print(lista)
    lista.append(33)
    print(lista)
    lista.pop()
    print(lista)


if __name__ == "__main__":
    # inlocuire()
    # transformare()
    half_sort()
