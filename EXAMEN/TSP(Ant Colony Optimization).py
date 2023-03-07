import random
import numpy as np

def ant_colony_optimization(cities, num_ants, num_iterations, alpha, beta, rho):
    n = len(cities)
    tau = np.full((n, n), 1.0 / n)
    best_distance = float('inf')
    best_tour = []

    # repeta procesul de optimizare pentru un anumit numar de iteratii
    for iteration in range(num_iterations):
        tours = []
        # generare tur pentru fiecare furnica
        for ant in range(num_ants):
            tour = construct_solution(cities, tau, alpha, beta)
            tours.append((tour, get_distance(cities, tour)))

        # sorteaza turul pe baza lungimii lor
        tours.sort(key=lambda x: x[1])
        # updateaza cel mai bun tur gasit departe
        if tours[0][1] < best_distance:
            best_distance = tours[0][1]
            best_tour = tours[0][0]

        # updateaza nivelul de feromoni pe baza lungimii turului
        update_pheromones(tau, tours, n, rho)

    return best_tour, best_distance

def construct_solution(cities, tau, alpha, beta):
    n = len(cities)
    tour = []
    visited = [False] * n
    # alege random un oras de pornire
    current_city = random.randint(0, n - 1)
    tour.append(current_city)
    visited[current_city] = True

    # continua sa construiesti turul pana cand fiecare oras este vizitat
    while len(tour) < n:
        probabilities = [0.0] * n
        total = 0.0
        # calculaeaza probabilitatea vizitarii oricarui oras urmator
        for next_city in range(n):
            if not visited[next_city]:
                probabilities[next_city] = choose_next_city(current_city, next_city, tau, alpha, beta)
                total += probabilities[next_city]

        # normalizarea probabilitatilor daca totalul este mai mare decat zero
        if total > 0:
            for i in range(n):
                if visited[i]:
                    probabilities[i] = 0
                else:
                    probabilities[i] /= total

        # alege urmatorul oras pe baza probabilitatilor
        next_city = np.random.choice(n, p=probabilities)
        tour.append(next_city)
        visited[next_city] = True
        current_city = next_city

    return tour

def choose_next_city(current_city, next_city, tau, alpha, beta):
    pheromone = tau[current_city][next_city]
    distance = dist(cities[current_city], cities[next_city])
    return (pheromone ** alpha) * ((1.0 / distance) ** beta)

def update_pheromones(tau, tours, n, rho):
    # se scade nivelul de feromoni
    for i in range(n):
        for j in range(i + 1, n):
            tau
