def pb1():
    #3 minime
    minim1, minim2, minim3 = 9999, 9999, 9999
    n = int(input())
    for i in range(n):
        nr = int(input())
        if nr < minim1:
            minim2, minim3 = minim1, minim2
            minim1 = nr
        else:
            if nr < minim2:
                minim3 = minim2
                minim2 = nr
            else:
                if nr < minim3:
                    minim3 = nr
    print(minim1, minim2, minim3)


def pb2():
    n1, n2 = int(input()), int(input())
    n11, n22 = n1, n2
    while n2:
        n1, n2 = n2, n1%n2
    cmmdc = n1
    print(cmmdc)
    
    print(n11 * n22 // cmmdc)

if __name__ == "__main__":
    # pb1()
    pb2()
