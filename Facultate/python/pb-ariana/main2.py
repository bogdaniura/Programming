x = input() #citirea initiala a lui  x
c = 0 # initializam contorul cerut
while int(x) != 0: #cat timp nu se citeste valoarea 0
    u = int(x) % 10 #cifra unitatilor
    t = (int(x) / 10) % 10 #cifra zecilor
    if int(u) < int(t): #comparam cifrele
        c = c + 1 #marim contorul
#       print(x, ' ', u, ' ', t, ' ',int(u) < int(t) ) #asta e ca sa ma verific
    x = input() #citim iar x
print(c) #afisam numarul cerut