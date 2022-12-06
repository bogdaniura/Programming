import math

def cautare_salt(lista, val):
    lista.sort()
    st = 0
    l = len(lista)
    salt = int(math.sqrt(len(lista)))
    for i in range(0, l, salt):
        if lista[i] < val:
            st = i
        elif lista[i] == val:
            return 1
        else:
            break
    for i in range(st, st + salt):
        if lista[i] == val:
            return 1
    return -1

#tema: split dupa index specificat


if __name__ == "__main__":
    lista = [10, 353, 345, 46 ,123, 679, 345]
    print(cautare_salt(lista, 9))