import math
import numpy as np

def cod():
    # text_clar = input("introduceti textul clar: ").upper()
    # cheie = input("introduceti cheia: ").upper()
    text_clar = "SUPERCALIFRAGILISTICEXPIALIDOCIOUSYS"
    cheie = "bcbdbcbdb"
    #sus citire
    
    vector_text_clar = []
    for caracter in text_clar:
        vector_text_clar.append(ord(caracter)-65)
    print(vector_text_clar)
    #sus alcatuire vector text clar si afisare
    
    lista_auxiliara = []
    for caracter in cheie:
        lista_auxiliara.append(ord(caracter)-65)
    # sus alcatuire vector cheie
    
    lungime_cheie = len(cheie)
    matrice_cheie = [[0] * int(math.sqrt(lungime_cheie)) for _ in range(int(math.sqrt(lungime_cheie)))]
    k = 0
    for i in range(int(math.sqrt(lungime_cheie))):
        for j in range(int(math.sqrt(lungime_cheie))):
            matrice_cheie[i][j] = lista_auxiliara[k]
            k+=1
    print(matrice_cheie)
    #sus alcatuire matrice cheie si afisare
    
    g = len(vector_text_clar) // len(matrice_cheie)
    s = 0
    d = len(vector_text_clar)//g
    vector_text_criptat = []
    for k in range(g):
        #de impartit vectorul in vectori de cate 3 astfel incat sa se poata inmulti cu matriec_cheie
        vector_auxiliar= vector_text_clar[s:d:]
        print(np.matmul(vector_auxiliar,matrice_cheie)%26)
        vector_text_criptat.append(np.matmul(vector_auxiliar,matrice_cheie)%26)
        s = d
        d += len(vector_text_clar)//g
    #sus inmultire vectori cu matrice, alcatuire vector_text_criptat si afisare
    
    for list in vector_text_criptat:
        for element in list:
            print(chr(element+65),end="")        
    #sus afisare text criptat
    
        



if __name__ == "__main__":
    cod();