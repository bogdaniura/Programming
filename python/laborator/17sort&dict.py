def selection_sort(lista=[5, 4, 3, 2, 1]):
    n = len(lista)
    for i in range(n):
        imin = i

        for j in range(i + 1, n):
            if lista[j] < lista[imin]:
                imin = j
        lista[i], lista[imin] = lista[imin], lista[i]
    return lista


def cautare_id(lista, id_cautat):
    for elem in lista:
        if elem["id"] == id_cautat:
            return elem["position"]
    return {}


if __name__ == "__main__":
    lista = [5, 3, 8, 1, 2]
    # print(selection_sort(lista))
    employee1 = {"id": 1, "name": "John Doe", "age": 31, "position": "Sef"}
    employee2 = {"id": 2, "name": "Ion Pop", "age": 34, "position": "Sef++"}
    employee3 = {"id": 3, "name": "Ioan Popescu", "age": 37, "position": "Sef#"}
    employee4 = {"id": 4, "name": "Mihai Eminovici", "age": 41, "position": "Sef+9"}

    lista2 = [employee1, employee2, employee3, employee4]
    print(cautare_id(lista2, 3))
