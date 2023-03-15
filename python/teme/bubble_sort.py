def bbs():
    schimbare = True
    c = 0
    while schimbare:
        schimbare = False
        c += 1
        for i in range(len(lista) - c):
            if lista[i] > lista[i + 1]:
                schimbare = True
                aux = lista[i]
                lista[i] = lista[i + 1]
                lista[i + 1] = aux
            print(lista, c)

    print(lista)


if __name__ == "__main__":
    lista = [2, 5, 3, 9, 6, 4, 2, 1]
    bbs()
