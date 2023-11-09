def cod():
    P1 = []
    P = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
    
    textcriptat = ""
    parola = input("Introduceti parola: ").upper()
    text = input("Introduceti textul: ").upper()
    
    
    #alcatuire alfabet criptat
    for caracter in parola: #punem parola la inceputul alfabetului criptat
        P1.append(caracter)
        
    for i in range(26):
        if P[i] not in P1:
            P1.append(P[i])
        
    # alcatuire text criptat    
    for caracter in text:
        if caracter in P:
            textcriptat += P1[P.index(caracter)]
        # else:
        #     textcriptat += caracter
    
    print(P, "\n", P1)
    print(text)
    print(textcriptat)
    

if __name__ == "__main__":
    cod()