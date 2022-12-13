def find_substr(cuv, subcuv):
    gasit = False
    i = 0
    nr_pasi = len(cuv) - len(subcuv)
    while not gasit and i < nr_pasi:
        j = 0
        while j < len(subcuv):
            if cuv[i + j] != subcuv[j]:
                j += 1
                break
            else:
                j += 1
        if j == len(subcuv):
            return i
        i += j
    return -1


def adunare_n(n):
    suma = 0
    for i in range(1, n + 1):
        suma += i
    print(suma)


def rec_adunare_n(n):
    if n == 1:
        return 1
    return n + rec_adunare_n(n - 1)


def rec_factorial_n(n):
    if n == 2:
        return 2
    return n * rec_factorial_n(n - 1)


def rec_fobonacci_n(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    return rec_fobonacci_n(n - 1) + rec_fobonacci_n(n - 2)


def fibonacci(n):
    f = 0
    t1 = 0
    t2 = 1
    for i in range(2, n + 1):
        f = t1 + t2
        t1 = t2
        t2 = f
    return f


def nr_aparitii(n):

    if n == 0:
        return 0
    else:
        return (n % 10 == 0) + nr_aparitii(n // 10)


def inv_nr_test(n):
    sirnou = ""
    if int(n) < 10:
        # sirnou += str(n)
        return str(n)
    else:
        # sirnou += str(n % 10) + " "
        return sirnou + inv_nr(int(n) // 10)


def inv_nr_prof(n):
    sir = str(n)
    c = sir[len(sir) - 1]
    if len(sir) - 1 <= 0:
        return c
    return c + " " + inv_nr_prof(int(sir[:len(sir)-1]))



if __name__ == "__main__":
    cuv = "teleenciclopedie"
    subcuv = "edie"
    # print(find_substr(cuv, subcuv))
    # adunare_n(10)
    # print(rec_adunare_n(5))
    # print(rec_factorial_n(5))
    # print(fibonacci(15))
    # print(rec_fobonacci_n(15))
    # print(nr_aparitii(1020304050))
    # scrieti un nr invers cu spatii intre cifre    
    # 2453 -> 3 5 4 2
    print(inv_nr_prof("2345"))