def adunare_elem_lista(lista):
    suma = 0
    for element in lista:
        suma += element
    return suma


def adunare(*argumente):  # **kvargs #argumente este o lista
    suma = 0
    for element in argumente:
        suma += element
    return suma


def produs(*argumente):  # **kvargs #argumente este o lista
    produs = 1
    for element in argumente:
        produs *= element
    return produs


def factorial(n):
    fac = 1
    for i in range(1, n + 1):
        fac *= i
    return fac


def cautare(lista_car, caracter):  # funtia returneaza un index
    for i in range(len(lista_car)):
        if lista_car[i] == caracter:
            return i
    return -1


def criptare(plain_text):  # returneaza textul criptat
    cript_text = ""
    for element in plain_text:
        # if element not in lista1:
        #     cript_text += element
        index_i = cautare(lista1, element)  # am gasit indexul in lista1
        cript_text += lista2[index_i]
    return cript_text


def decriptare(cript_text):
    plain_text = ""
    for element in cript_text:
        if element not in lista1:
            plain_text += element
        index_i = cautare(lista2, element)  # am gasit indexul in lista1
        plain_text += lista1[index_i]
    return plain_text


# def prim(n):
    
    
def cautare_nr_prim(n):
    gasit = False
    while(not gasit):
        if prim(e) == True:
            gasit = True
    return e    


if __name__ == "__main__":
    lista1 = [
        "a",
        "b",
        "c",
        "d",
        "e",
        "f",
        "g",
        "h",
        "i",
        "j",
        "k",
        "l",
        "m",
        "n",
        "o",
        "p",
        "q",
        "r",
        "s",
        "t",
        "u",
        "v",
        "w",
        "x",
        "y",
        "z",
        " ",
    ]
    lista2 = [
        "f",
        "g",
        "h",
        "i",
        "j",
        "k",
        "l",
        "m",
        "n",
        "o",
        "p",
        "q",
        "r",
        "s",
        "t",
        "u",
        "v",
        "w",
        "x",
        "y",
        "z",
        "a",
        "b",
        "c",
        "d",
        "e",
        " ",
    ]
    # print(adunare(a=int(input()), b=int(input())))
    # a = int(input())
    # b = int(input())
    # print(adunare(a, b))
    # print(adunare())
    # print(adunare(1))
    # print(adunare(1, 2, 3, 4, 5, 6, 7, 8, 9))
    # print(adunare_elem_lista(lista))
    # print(produs(a, b))
    # print(produs(1,2,3,4,5,6,7,8,9))
    # print(metoda_suma)
    # print(factorial(10))
    # print("thequickbrownfoxjumpedoveralazydog", "\n", criptare("thequickbrownfoxjumpedoveralazydog"))
    # print(criptare("the quick brown fox jumped over a lazy dog"))
    # print(decriptare(criptare("the quick brown fox jumped over a lazy dog")))
    prim(n)
