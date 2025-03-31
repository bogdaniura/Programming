from ortools.linear_solver import pywraplp

def FurnitureProduction():
    # Inițializare solver
    solver = pywraplp.Solver.CreateSolver("GLOP")
    if not solver:
        return

    # Variabile de decizie: x = număr scaune, y = număr mese
    x = solver.NumVar(0, solver.infinity(), "Scaune")
    y = solver.NumVar(0, solver.infinity(), "Mese")

    # Constrângeri
    # 1. Lemn disponibil: 4x + 20y <= 120
    solver.Add(4 * x + 20 * y <= 120.0)
    # 2. Ore de muncă: 2x + 5y <= 40
    solver.Add(2 * x + 5 * y <= 40.0)
    # 3. Spațiu de depozitare: x + y <= 15 (exemplu suplimentar)
    solver.Add(x + y <= 15.0)

    # Funcția obiectiv: Maximizare profit (3x + 10y)
    solver.Maximize(3 * x + 10 * y)

    # Rezolvare
    status = solver.Solve()

    # Afișare rezultate
    if status == pywraplp.Solver.OPTIMAL:
        print("Soluția optimă:")
        print(f"Profit total = {solver.Objective().Value():.1f} $")
        print(f"Scaune produse = {x.solution_value():.0f}")
        print(f"Mese produse = {y.solution_value():.0f}")
    else:
        print("Problema nu are soluție optimă.")

FurnitureProduction()