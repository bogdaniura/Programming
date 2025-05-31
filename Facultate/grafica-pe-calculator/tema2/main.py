import math

def aitken_accelerare(secventa):
    accelerata = []
    for i in range(len(secventa) - 2):
        x1 = secventa[i]
        x2 = secventa[i + 1]
        x3 = secventa[i + 2]
        
        numarator = (x2 - x1) ** 2
        numitor = x3 - 2 * x2 + x1
        
        if numitor != 0:
            termen_accelerat = x1 - numarator / numitor
            accelerata.append(round(termen_accelerat, 5))
        else:
            accelerata.append(None)
    
    return accelerata

if __name__ == "__main__":
    original = [1.0, 1.5, 1.75, 1.875, 1.9375, 1.96875]    
    print("Sir original:", original)
    
    accelerat = aitken_accelerare(original)
    print("Sir accelerat (Aitken):", accelerat)