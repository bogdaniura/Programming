def bresenham_line(x0, y0, x1, y1):
    points = []
    dx = abs(x1 - x0)
    dy = abs(y1 - y0)
    sx = 1 if x0 < x1 else -1
    sy = 1 if y0 < y1 else -1
    err = dx - dy
    
    x, y = x0, y0
    points.append((x, y))
    
    while x != x1 or y != y1:
        e2 = 2 * err
        if e2 > -dy:
            err -= dy
            x += sx
        if e2 < dx:
            err += dx
            y += sy
        points.append((x, y))
    
    return points

if __name__ == "__main__":
    test_cases = [
        ((0, 0, 5, 3), "Linia cu panta pozitiva"),
        ((3, 3, 8, 1), "Linia cu panta negativa"),
        ((2, 5, 2, 9), "Linie verticala"),
        ((4, 7, 9, 7), "Linie orizontala"),
        ((5, 5, 5, 5), "Punct unic")
    ]
    
    for (x0, y0, x1, y1), descriere in test_cases:
        print(f"\n{descriere} de la ({x0},{y0}) la ({x1},{y1}):")
        puncte = bresenham_line(x0, y0, x1, y1)
        print(" -> ".join(f"({x},{y})" for x, y in puncte))