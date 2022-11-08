def inlocuire():
    sir = input()
    sirnou = ""
    for caracter in sir:
        if caracter in "aeiou":
            print(caracter.upper())
            sirnou += caracter.upper()
        else:
            print(caracter)
            sirnou += caracter
    print(sirnou)


def transformare():
    cuvant = input()
    cuvantnou = ""
    index = 0
    for caracter in cuvant:
        if index == 0 or index == len(cuvant) - 1:
            print(caracter.upper())
            cuvantnou += caracter.upper()
        else:
            print(caracter)
            cuvantnou += caracter
        index += 1
    print(cuvantnou)


def half_sort():
    lista = [34, 0, 2, 5, 3, 300, 56]
    jumatate = len(lista) // 2
    list1 = lista[:jumatate:]
    print(list1)
    list2 = lista[jumatate::]
    print(list2)
    list1.sort()
    print(list1)
    list2.sort(reverse=True)
    print(list2)
    lista = list1 + list2
    print(lista)
    lista.append(33)
    print(lista)
    lista.pop()
    print(lista)


def interschimbarepvuc():
    pvgasita = False
    cuvant = input()
    for caracter in cuvant:
        if caracter in "aeiou":
            if pvgasita == False:
                prima_vocala = caracter
                pvgasita = True
        else:
            ultima_consoana


def interschimbarepvuc2():
    cuvant = input()
    pvinlocuita = ucinlocuita = False
    cuvantnou = ""
    
    for caracter in cuvant:
        if caracter in "aeiou":
            pv = caracter
            break

    for caracter in cuvant[::-1]:
        if caracter not in "aeiou":
            uc = caracter
            break
    
    for caracter in cuvant:
        if(caracter == pv and not pvinlocuita):
            print(uc)
            cuvantnou += uc
        else:
            if(caracter == uc and not ucinlocuita):
                print(pv)
                cuvantnou += pv
            else:
                print(caracter)
                cuvantnou += caracter
    print(cuvantnou)
    
    
def inserare_asterisc():
    cuvant = input()
    cuvantnou = ""
    for caracter in cuvant:
        print(caracter)
        cuvantnou += caracter
        if caracter in "aeiou":
            print("*")
            cuvantnou += "*"
    print(cuvantnou)


def palindrom():
    nrcuv = int(input())
    for c in range (0, nrcuv):
        cuvant = input()
        if cuvant == cuvant[::-1]:
            print(1)
        else:
            print(0)
        

if __name__ == "__main__":
    # inlocuire()
    # transformare()
    # half_sort()
    # interschimbarepvuc2()
    # inserare_asterisc()
    palindrom()
    
