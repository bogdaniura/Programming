import numpy as np


def lista():
    suma = 0
    l = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    print(l)
    for i in range(len(l)):
        print(l[i], end = " ")
    for element in l[3:7:]:
        print(element, end = " ")
        suma += element
        print(suma)


def lista2():
    l = [100, 982, 532, 54, 46, 123, 536, 567, 235, 879, 343]
    suma = 0
    l.append(543)
    l.append(19)
    l.insert(0, 1110)
    l.extend([123, 234])
    l.pop() #lifo
    l.pop(0) #fifo
    for elem in l:
        if elem > 500:
            suma += elem
    for i in range(len(l)):
        print("l[", i, "] = ", l[i], sep = '')

    print(suma)
    

def ex_deque():
    from collections import deque
    l1 = list()
    l2 = deque()
    l1.append(100)
    l2.append(100)
    l1.append(500)
    l2.append(500)
    l1.append(300)
    l2.append(300)
    l1.append(800)
    l2.append(800)
    l1.append(200)
    l2.append(200)
    print(l1)
    print(l2)
    l1.append(5)
    l2.append(5)
    print(l1)
    print(l2)
    l2.pop()
    print(l2)


def matrice():
    nl = nc = 3
    mat = []
    suma_diag_princ = 0
    lista_sume_coloane = [0] * nc
    lista_sume_linii = [0] * nl
    
    for i in range(nl):
        coloane_mat = []
        for j in range(nc):
            coloane_mat.append(int(input()))
        mat.append(coloane_mat)
        
    for i in range(nl):
        for j in range(nc):
            lista_sume_coloane[j] += mat[i][j]
    print(lista_sume_coloane)
    
    for j in range(nc):
        for i in range(nl):
            lista_sume_linii[i] += mat[i][j]
    print(lista_sume_linii)
    print(np.mat)

if __name__ == "__main__":
    # lista()
    # lista2()
    # ex_deque()
    matrice()