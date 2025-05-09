from ortools.linear_solver import pywraplp

def Mobila():
    # Initializare solver
    solver = pywraplp.Solver.CreateSolver("GLOP")
    if not solver:
        return

    x = solver.NumVar(0, solver.infinity(), "Scaune")
    y = solver.NumVar(0, solver.infinity(), "Mese")

    solver.Add(4 * x + 20 * y <= 120.0) #resurse disponibile

    solver.Add(2 * x + 5 * y <= 40.0) #ore

    solver.Add(x + y <= 15.0) #spatiu de stocare

    solver.Maximize(3 * x + 10 * y) #funtia obiectiv

    # Rezolvare
    status = solver.Solve()

    # Afișare rezultate
    if status == pywraplp.Solver.OPTIMAL:
        print("Solutia optima:")
        print(f"Profit total = {solver.Objective().Value():.1f}")
        print(f"Scaune produse = {x.solution_value():.0f}")
        print(f"Mese produse = {y.solution_value():.0f}")
    else:
        print("Problema nu are solutie optima.")

Mobila()