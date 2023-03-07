import random
import math


def simulated_annealing(cities, initial_temperature, cooling_rate, stopping_temperature):
    n = len(cities)  # numarul de orase
    current_solution = random.sample(range(n), n)  # selectarea random a unei solutii de pornire
    best_solution = current_solution.copy()  # initializarea celei mai bune solutii ca solutia curenta
    current_distance = get_distance(cities, current_solution)  # calcularea distantei a solutiei curente
    best_distance = current_distance  # initializarea celei mai bune distante ca distanta curenta
    temperature = initial_temperature  # initializarea temperaturii cu temperatura curenta

    # se repeta urmatoarele pana cand temperatura scade sub temperatura de oprire
    while temperature > stopping_temperature:
        new_solution = get_neighbour(current_solution)  # genereaza o noua solutie prin perturbarea solutiei curente
        new_distance = get_distance(cities, new_solution)  # se calculeaza distanta noii solutii
        delta_distance = new_distance - current_distance  # calcularea modificarii distantei

        # in cazul in care noua solutie este mai buna (adica o distantă mai mica), se accepta
        if delta_distance < 0:
            current_solution = new_solution
            current_distance = new_distance
            if new_distance < best_distance:  # daca noua solutie este cea mai buna solutie de pana acum, se actualizeaza cea mai buna solutie si cea mai buna distanta
                best_solution = new_solution
                best_distance = new_distance
        # daca noua solutie nu este mai bunt, se accepta cu o anumita probabilitate
        else:
            # probabilitatea de a accepta o solutie mai proasta este proportionala cu temperatura si cu modificarea distantei
            # pe masura ce temperatura scade, scade probabilitatea de a accepta o solutie mai proasta
            if random.random() < math.exp(-delta_distance / temperature):
                current_solution = new_solution
                current_distance = new_distance

        temperature *= cooling_rate  # scaderea temperaturii prin rata de racire

    # returneaza cea mai buna solutie si cea mai buna distanta gasita
    return best_solution, best_distance


# genereaza o noua solutie prin inlocuirea a doua orașe selectate aleatoriu in solutia curenta
def get_neighbour(solution):
    n = len(solution)
    a = random.randint(0, n - 1)
    b = random.randint(0, n - 1)
    while a == b:  # ne asiguram ca a și b sunt orase diferite
        b = random.randint(0, n - 1)
    solution[a], solution[b] = solution[b], solution[a]
    return solution


# sa calculeze distanta totala a solutiei, avand in vedere lista de orase si ordinea in care acestea sunt vizitate
def get_distance(cities, solution):
    distance = 0
    n = len(solution)
    for i in range(n - 1):
        distance += dist(cities[solution[i]], cities[solution[i + 1]])
    distance += dist(cities[solution[-1]],
                     cities[solution[0]])  # se adauga distanta de la ultimul oraș la primul oras
    return distance
