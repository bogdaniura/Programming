def cautare_binara(numar_cautat):
    lista.sort()
    print(lista)
    gasit = False
    st = 0
    dr = len(lista)
    while not gasit and dr - st > 1:
        mij = (st + dr) // 2
        if lista[mij] == numar_cautat:
            gasit = True
        else:
            if lista[mij] < numar_cautat:
                st = mij
            else:
                dr = mij
    if gasit:
        print(mij)
    else:
        print("Elementul nu apartine listei")
    
    
def cautare_binara_rec(numar_cautat, st, dr, gasit = False):
    if not gasit and dr - st > 1:
        mij = (st + dr) // 2
        if lista[mij] == numar_cautat:
            return mij
        else:
            if lista[mij] < numar_cautat:
                return cautare_binara_rec(numar_cautat, mij, dr)
            else:
                return cautare_binara_rec(numar_cautat, st, mij)
    else:
        return -1


if __name__ == "__main__":
    lista = [12 ,235, 2345 ,568 ,213, 875, 356 ,234 ,7890, 354, 87]
    dr = len(lista)
    n = int(input())
    lista.sort()
    print(lista)
    # cautare_binara(n)
    print(cautare_binara_rec(n, 0, len(lista)))