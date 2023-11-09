def find_indexes(caracter):

    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if caracter == mat[i][j]:
                return (i+1)*10+j+1
            
def criptare():
    
    text_clar = input("Introduceti textul clar: ").upper()
    text_intermediar = ""
    text_codat = 0
    for caracter in text_clar:
        if caracter == "J":
            text_intermediar += "I"
        else:
            if caracter == " ":
                text_intermediar += "W"
            else:
                text_intermediar += caracter
    for caracter in text_intermediar:
        text_codat = text_codat * 100 + find_indexes(caracter)
    print(text_codat)
     
def decriptare():
    text_codat = input("Introduceti textul codat: ")
    for i in range(0,len(text_codat),2):
        print(mat1[int(text_codat[i])-1][int(text_codat[i+1])-1], end="")
        


if __name__ == "__main__":
    mat=[["A", "B", "C", "D", "E"],
         ["F", "G", "H", "I", "K"],
         ["L", "M", "N", "O", "P"],
         ["Q", "R", "S", "T", "U"],
         ["V", "W", "X", "Y", "Z"]]
    
    mat1=[["A", "B", "C", "D",  "E"],
          ["F", "G", "H", "I",  "K"],
          ["L", "M", "N", "O",  "P"],
          ["Q", "R", "S", "T",  "U"],
          ["V", "W", "X", "Y",  "Z"]]
    
    criptare()
    decriptare()