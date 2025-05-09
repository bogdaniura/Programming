from ortools.linear_solver import pywraplp

def optimize():

    solver = pywraplp.Solver.CreateSolver("SAT")
    if not solver:
        return

    # Definire variabile întregi
    x = solver.IntVar(0, solver.infinity(), "Internationali") 
    y = solver.IntVar(0, solver.infinity(), "Locali") 

    solver.Add(1200 * x + 400 * y <= 10000) #costuri
    
    solver.Add(1.5 * x + y <= 12) #ore

    solver.Add(x + y <= 15) # numar de speakeri

    solver.Add(x <= 5) #numar de speakeri internationali

    solver.Maximize(500 * x + 200 * y) #funtia pe care trebuie sa o maximizam

    status = solver.Solve()

    if status == pywraplp.Solver.OPTIMAL:
        print("Solutie optima:")
        print(f"Internationali: {int(x.solution_value())}")
        print(f"Locali: {int(y.solution_value())}")
        print(f"Participanti: {solver.Objective().Value()}")
        
        # Verificare resurse utilizate
        print("\nStatistici:")
        print(f"Cheltuieli: {1200*x.solution_value() + 400*y.solution_value():.1f} u.m. (din 10000)")
        print(f"Durata: {1.5*x.solution_value() + y.solution_value():.1f} ore (din 12)")
    else:
        print("Nu există soluție fezabila.")

if __name__ == "__main__":
    optimize()