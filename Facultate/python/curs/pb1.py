def validare_pb1(n):
    if n <= 500000000 and n >= 1:
        return 1
    return 0


def pb1():
    fib1 = 0
    fib2 = 1
    fib3 = 0
    n = int(input())
    if validare_pb1(n):
        print("datele introduse corespund cerintei")
        if n == 1:
            print(0)
        else:
            if n == 2:
                print(1)
            else:
                for i in range(n - 2):
                    fib3 = fib1 + fib2
                    fib1, fib2 = fib2, fib3
                print(fib3)
    else:
        print("datele introduse nu corespund cerintei")

if __name__ == "__main__":
    pb1()
    # pb2()
    # pb3()