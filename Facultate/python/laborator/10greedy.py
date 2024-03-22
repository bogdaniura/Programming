def spectacol(lista):
    lista = sorted(lista, key=lambda el: el[1])
    print(lista)
    final = [lista[0]]
    orasfarsit = lista[0][1]
    for spec in lista:
        if spec[0] >= orasfarsit:
            final.append(spec)
            orasfarsit = spec[1]
    print(final)
    print(len(final))


def rucsac(bag, gmax, tip_metoda):
    bag = sorted(bag, key=lambda k: k[1] / k[0], reverse=True)
    print(bag)
    r = []  # continutul rucsacului
    g = 0  # greutatea rucsacului
    val = 0  # valoarea rucsacului
    for el in bag:
        if g + el[0] <= gmax:
            r.append(el)
            g += el[0]
            val += el[1]
        else:
            if tip_metoda == 1:
                fract = gmax - g
                if fract + g <= gmax and fract > 0:
                    r.append([fract, fract * el[1] / el[0]])
                    g += fract
                    val += fract * el[1] // el[0]
    print(r, g, val)


def masini(mas, timp_lucru):
    mas = sorted(mas, key=lambda k: k)
    final = []
    tl = 0
    for m in mas:
        if tl + m <= timp_lucru:
            tl += m
            final.append(m)
    print(final, tl)


if __name__ == "__main__":
    spectacole = [
        [1, 8],
        [8, 12],
        [8, 10],
        [14, 16],
        [12, 14],
        [12, 16],
        [16, 20],
        [18, 21],
    ]
    inventory = [
        [10, 200],
        [4, 500],
        [34, 250],
        [1, 10],
        [10, 10],
        [40, 1000],
    ]  # greutate, valoare
    reparatii = [6, 2, 4, 3, 2, 5, 10, 20, 3]

    # spectacol(spectacole)
    # rucsac(inventory, 30, 0)
    masini(reparatii, 24)
