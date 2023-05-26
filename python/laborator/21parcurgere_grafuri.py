noduri_parcurse = []


def parcurgere_graf(graf, start, noduri_parcurse):
    if noduri_parcurse.count(start) == 0:
        for elem in graf:
            if elem[0] == start:
                # noduri_parcurse = noduri_parcurse + "," + str(elem[0])
                noduri_parcurse.append(start)
                print(noduri_parcurse, noduri_parcurse.count(start))
                parcurgere_graf(graf, elem[1], noduri_parcurse)
        if noduri_parcurse.count(start) == 0:
            noduri_parcurse.append(start)


if __name__ == "__main__":
    graf = [[0, 1], [0, 2], [1, 2], [1, 3], [2, 4], [2, 6], [4, 5], [5, 7]]
    parcurgere_graf(graf, graf[0][0], noduri_parcurse)
 