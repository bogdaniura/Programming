k = input() #citim k
x = 0
y = 1 #initializam x,y
while int(x) < int(k): #cat timp x este mai mic decat numarul citit
    x = x + y #marim suma (x trb sa ajunga sa depaseasca k)
    y = y + 1 #marim y (y e numarul la care am ajuns)
print(y-1) #afisam y-1 din cauza while-ului
    