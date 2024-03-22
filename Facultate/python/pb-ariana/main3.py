x = input() #citim x
a = b = 0 #initializam a, b
while a < len(x): #cat timp a e mai mic decat lungimea lui x ca string
    b = b * 10 + int(x[a]) #adaugam cifra la capatul numarului b ;profitand de conversia intre tipuri de date
    a += 2 #ne intereseaza locurile impare deci crestem selectorul de pozitie cu 2
print(b) #afisam b