import math


def pb1():
    n = int(input())
    for i in lista:
        if i == n:
            print(n * math.pi**2)


def pb2():
    produs = 1
    for i in range(len(lista)):
        if i < 10:
            produs *= lista[i]
    print(produs)


def pb3():
    for i in lista[:10]:
        print(i, i in lista2)


def pb4():
    for i in range(len(mat) - 1):
        print(mat[i][i + 1])
    for i in range(len(mat) - 1):
        print(mat[i + 1][i])


def pb5():
    for i in range(1, len(mat)):
        for j in range(1, len(mat)):
            if i - j == 1 or i - j == -1:
                print(mat[i][j])


if __name__ == "__main__":
    lista = [1, 2, 3, 4, 5, 6, 312, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19]
    lista2 = [2, 4, 5, 9, 8, 111, 312, 345]
    mat = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], [13, 14, 15, 16]]
    # pb1()
    # pb2()
    # pb3()
    # pb4()
    pb5()
