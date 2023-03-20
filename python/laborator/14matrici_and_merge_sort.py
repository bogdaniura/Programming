# se dea o mat patratica
# det elementul min si max

# mat patratica
# generati elementele matricii dupa urmatoarele reguli:
# elementele pt care produsul indicilor este un nr par vor avea valoarea 1
# produs indicilor impar -> val 0
# elem de pe diagonala princ vor avea val 2


def min_max():
    minim = maxim = mat[0][0]

    for i in range(nl):
        for j in range(nc):
            mat[i][j] = int(input())
            if mat[i][j] > maxim:
                maxim = mat[i][j]
            if mat[i][j] < minim:
                minim = mat[i][j]
    print(maxim, minim)


def gen_mat(mat1):
    for i in range(len(mat1)):
        for j in range(len(mat1)):
            if i == j:
                mat1[i][j] = 2
            else:
                if (i * j) % 2 == 0:
                    mat1[i][j] = 1
                else:
                    mat1[i][j] = 0
    print(mat1)


def unire(listas, listad):
    rezultat = []
    i = j = 0
    while i < len(listas) and j < len(listad):
        if listas[i] < listad[j]:
            rezultat.append(listas[i])
            i += 1
        else:
            rezultat.append(listad[j])
            j += 1
    while i < len(listas):
        rezultat.append(listas[i])
        i += 1
    while j < len(listad):
        rezultat.append(listad[j])
        j += 1
    return rezultat


def m_sort(lista):
    if len(lista) <= 1:
        return lista
    else:
        mij = len(lista) // 2
        stanga = m_sort(lista[:mij])
        dreapta = m_sort(lista[mij:])

        return unire(stanga, dreapta)


def oglindit(n):
    ogl = 0
    while n >= 1:
        u = n % 10
        ogl = ogl * 10 + u
        n //= 10

    print(ogl)


if __name__ == "__main__":
    # nc = nl = int(input())
    # mat = [[0] * nc for _ in range(nl)]
    # mat1 = [[0] * nc for _ in range(nl)]
    lista = [9, 1, 2]

    # min_max()
    # print(max(max(mat)), min(min(mat)))    #metoda neortodoxa
    # gen_mat(mat1)

    print(lista, "\n", m_sort(lista))
    # oglindit(3246)
