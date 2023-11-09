def cod():
    cheie = []
    cheie_decriptare = []
    inceput = 0
    text_codat = ""
    text_intermediar = ""    
    text_clar = input("Introduceti textul clar: ")
    
    for caracter in text_clar:
        if caracter == " ":
            text_intermediar += "q"
        else:
            text_intermediar += caracter
            
    lungime_cheie = int(input("Introduceti lungimea cheii: "))
    print("Alcatuiti cheia:")
    for i in range(int(lungime_cheie)):
        print(i+1, ": ", end="")
        cheie.append(int(input()))

    while len(text_intermediar) % lungime_cheie != 0:
        text_intermediar += "*"
        
    for i in range(len(text_intermediar) // lungime_cheie):
            text1 = text_intermediar[i*lungime_cheie:(i+1)*lungime_cheie:]
            for j in range(lungime_cheie):
                text_codat += text1[cheie[j]-1]
    
    print("Textul codat: ", text_codat, sep="")
    
    for i in range(lungime_cheie):
        cheie_decriptare.append(cheie.index(i+1)+1)
    print("Cheie de decriptare: ",cheie_decriptare, sep="")
    
if __name__ == "__main__":
    cod()