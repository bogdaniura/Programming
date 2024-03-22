def rest(n):
    denominations = [1, 2, 5, 10, 20, 50, 100]
    change = [0] * len(denominations)
    for pos, coin in enumerate(reversed(denominations)):
        while coin <= n:
            n -= coin
            change[pos] += 1
    return change[::-1]


def fib1(n):
    mem = [0] * n
    mem[0] = 1
    mem[1] = 1
    for i in range(2, n):
        mem[i] = mem[i - 1] + mem[i - 2]
    return mem


def fib2(n):
    if n <= 2:
        return 1
    else:
        return fib2(n - 1) + fib2(n - 2)


def fib3(n, mem): #list out of range
    if n in mem:
        return n
    if n <= 2:
        rez = 1
    else:
        rez = fib3(n - 1, mem) + fib3(n - 2, mem)
        mem[n] = rez
    return rez


def f1(lista):
    for i in range(len(lista)):
        lista[i] = 255 - lista[i]
    return lista


if __name__ == "__main__":

    n = int(input())
    # lista = [100, 234, 5]
    # print(rest(n = int(input())))
    # print(fib1(n))
    # print(fib2(n))
    print(fib3(n, [0] * n))
    # lista 3 nr cu valori intre 0 si 255; ex : 100, 234, 5
    # sa se returneze inversa listei obtinute prin scaderea valorilor din lista din numarul 255
    # print(f1(lista))
