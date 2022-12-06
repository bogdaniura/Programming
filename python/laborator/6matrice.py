import numpy as np


def sum_matrice():
    
    nl = nc = int(input())
    mat = [[0] * nc for _ in range(nl)]
    sum_superior_diag_princ = sum_superior_diag_sec = 0

    for i in range(nl):
        for j in range(nc):
            mat[i][j] = int(input())
        
    for i in range(nl):
        for j in range(nc):
            if(j > i):
                sum_superior_diag_princ += mat[i][j]
            if(i + j < nl-1):
                sum_superior_diag_sec += mat[i][j]
                
    print(sum_superior_diag_princ, sum_superior_diag_sec)
    print(mat)
   
   
def patrat_mat():
    nl = int(input())
    nc = int(input())
    mat = [[0] * nc for _ in range(nl)]
    
    for i in range(nl):
        for j in range(nc):
            mat[i][j] = int(input()) ** 2
    
    print(mat)
    
    
def zece_plus_mat():
    nl = int(input())
    nc = int(input())
    mat = [[0] * nc for _ in range(nl)]
    
    for i in range(nl):
        for j in range(nc):
            mat[i][j] = int(input()) + 10
    
    print(mat)
  
  
def apartine_la_lista():
    nl = int(input())
    nc = int(input())
    mat = [[0] * nc for _ in range(nl)]
    
    for i in range(nl):
        for j in range(nc):
            mat[i][j] = int(input())
            
    # if 100 in mat:
    #     print(True, mat.index(100))
    for i in range(nl):
        for j in range(nc):
            if mat[i][j] == 100:
                print(True, i, j)

    
def suma_pare_mat():
    nl = int(input())
    nc = int(input())
    mat = [[0] * nc for _ in range(nl)]
    suma_pare = suma_impare = 0
    
    for i in range(nl):
        for j in range(nc):
            mat[i][j] = int(input())
    
    for i in range(nl):
        for j in range(nc):
            if mat[i][j] % 2 == 0 and mat[i][j] > 10:
                suma_pare += mat[i][j]
            else:
                suma_impare += mat[i][j]
    print(suma_pare, suma_impare)
    
    
if __name__ == "__main__":
    suma_pare_mat()