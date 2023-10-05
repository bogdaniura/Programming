# 1 fibonacci okk
# 2 half sort
# 3 matrice


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


def validare_pb2(n, vec):
    if n % 2 != 0 or n < 1 or n > 100:
        return 0
    else:
        for i in range(n):
            if vec[i] != int(vec[i]) or int(vec[i]) > 1000000000:
                return 0
    return 1


def pb2():
    n = int(input())
    vec, vec3 = [], []
    for i in range(n):
        vec.append(int(input()))
    if validare_pb2(n, vec):
        print("datele introduse corespund cerintei")
        vec1 = sorted(vec[:n//2], reverse = False)  #indicii merg de la 0 la n-1
        vec2 = sorted(vec[n//2:], reverse = True)
        vec3.append(vec1)
        vec3.append(vec2)
        print(vec3)            
        
    else:
        print("datele introduse nu corespund cerintei")


def pb3():
    n = int(input())
    mat = [[0] * n for _ in range(n)]
    for l in range(n):
        mat[l][0] = l + 1
    for c in range(n):
        mat[n-1][c] = n
    for l in range(n-1):
        for c in  range(1,n):
            mat[l][c] = mat[l][c-1] + mat[l+1][c-1]
    for l in range(n):
        for c in range(n):
            print(mat[l][c], " ", end = "")
        print("\n")   
        
    

if __name__ == "__main__":
    # pb1()
    pb2()
    # pb3()
