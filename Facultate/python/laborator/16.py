def prod_min_max():
    minim1, minim2, maxim1, maxim2 = 999999, 999999, -999999, -999999
    for elem in lista:
        if elem < minim2:
            minim2 = minim1
            minim1 = elem
        elif elem < minim1:
            minim1 = minim2
            minim2 = elem
        if elem > maxim2:
            maxim2 = maxim1
            maxim1 = elem
        elif elem > maxim1:
            maxim1 = maxim2
            maxim2 = elem
    print(minim1 * minim2, maxim1 * maxim2)


def prod_min_max2():
    lista2 = []
    lista2.extend(lista)
    minim1 = min(lista2)
    maxim1 = max(lista2)
    lista2.remove(minim1)
    lista2.remove(maxim1)
    print(lista, lista2)
    minim2 = min(lista2)
    maxim2 = max(lista2)
    print(minim1 * minim2, maxim1 * maxim2)


def prod_min_max3():
    lista.sort()
    print(lista[0] * lista[1], lista[-1] * lista[-2])


def tiparire():

    for i in range(len(mat)):
        for j in range(len(mat[0])):
            if mat[i][j] == 1:
                print(altalista[i], end="")
                print(altalista[j])
            else:
                print("-")


if __name__ == "__main__":
    lista = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    altalista = ["a", "b", "c", "d"]
    nc = nl = 4
    mat = [[0, 1, 1, 0], [1, 0, 1, 0], [1, 1, 1, 1], [0, 0, 1, 1]]

    tiparire()
    # prod_min_max()
    # prod_min_max2()
    # prod_min_max3()
