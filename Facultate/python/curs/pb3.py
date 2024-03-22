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
    # pb2()
    pb3()
