def divisors(number):
    div_list = [1, number]
    for div in range(2, number // 2 + 1):
        if number % div == 0:
            div_list.extend([div])
    div_list.sort()
    return div_list


def prim(n):
    if [1, n] == divisors(n):
        return True
    return False


def suma_cifre(n):
    suma = 0
    while n >= 1:
        suma += n % 10
        n //= 10
    return suma


def vterminal():
    numarul_de_termeni = int(input())
    for i in range(numarul_de_termeni):
        element = int(input())
        if prim(element):
            lista.append(element)
    
    suma_elem_lista = sum(lista)
    
    while suma_cifre(suma_elem_lista) >= 10:
        suma_elem_lista = suma_cifre(suma_elem_lista)
        print(suma_elem_lista)


if __name__ == "__main__":
    lista = []
    vterminal()
    print(lista, sum(lista), suma_cifre(sum(lista)))
    