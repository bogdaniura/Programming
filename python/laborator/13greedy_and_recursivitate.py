def greedy(timp):
    m = []
    lista.sort()
    i = 0
    while i < len(lista) and timp >= lista[i]:
        if lista[i] < timp:
            m.append(lista[i])
            timp -= lista[i]
        i += 1
    print(m)


def suma_rec(lista):
    if len(lista) == 1:
        if lista[0] % 2 == 0:
            return lista[0]
        else:
            return 0
    else:
        mijloc = len(lista) // 2
        return suma_rec(lista[:mijloc:]) + suma_rec(lista[mijloc::])


if __name__ == "__main__":
    lista = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    t = int(input())
    greedy(t)
    print(suma_rec(lista))
