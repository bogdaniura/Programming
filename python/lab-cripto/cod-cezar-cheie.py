def cod():
    P1 = []
    P = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
    
    textcriptat = ""
    cheie = input("Introduceti cheia: ")
    text = input("Introduceti textul: ").upper()
    
    for i in range(26-int(cheie)):
        P1.append(P[(i+int(cheie))%26])
        
    for i in range(int(cheie)):
        P1.append(P[i])
        
    # alcatuire text criptat    
    for caracter in text:
        if caracter in P:
            textcriptat += P1[P.index(caracter)]
        else:
            textcriptat += caracter
    
    print(P, '\n', P1)
    print(text, '\n',textcriptat)
    

if __name__ == "__main__":
    cod()