def pb1(n):
    c = 0
    produs_pare = 1
    while n > 1:
        u = n % 10
        if u % 2 == 0:
            produs_pare *= u
            if u == 8:
                c += 1
        n //= 10
    print(c, produs_pare)
        
        
def pb2():
    suma_elem_impare = 0
    for i in range(len(matrice)):
        if matrice[i][i] % 2 == 1:
            suma_elem_impare += matrice[i][i]
    print(suma_elem_impare)
    

def pb3():
    ht = {}
    for i in range(len(lista1)):
        ht[lista1[i]] = lista1[i].upper() + "-" + str(i+1)
        print(lista1[i], ht[lista1[i]],sep = " -> " ,end = ",")


if __name__ == "__main__":
    lista1 = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
    matrice = [[1, 2, 3],[4, 5 ,6],[7 ,8, 9]]
    pb1(n = int(input()))
    pb2()
    pb3()