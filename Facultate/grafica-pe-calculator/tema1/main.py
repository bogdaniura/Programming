import math

def cartezian_la_polar(x, y):
    r = math.sqrt(x**2 + y**2)
    theta_rad = math.atan2(y, x)
    theta_deg = math.degrees(theta_rad)
    return (round(r, 2), round(theta_deg, 2))

def polar_la_cartezian(r, theta_grade):
    theta_rad = math.radians(theta_grade)
    x = r * math.cos(theta_rad)
    y = r * math.sin(theta_rad)
    return (round(x, 2), round(y, 2))

polar = cartezian_la_polar(2, 4)
cartezian = polar_la_cartezian(polar[0], polar[1])
print(f"Polar pentru (2,4): {polar}")
print(f"Inapoi la cartezian: {cartezian}")

##########################################################

def rotatie(x, y, unghi_grade):
    theta = math.radians(unghi_grade)
    x_nou = x * math.cos(theta) - y * math.sin(theta)
    y_nou = x * math.sin(theta) + y * math.cos(theta)
    return (round(x_nou, 2), round(y_nou, 2))

punct_rotit = rotatie(2, 4, 30)
print(f"Punctul rotit: {punct_rotit}")

#############################################################

def simetrie_fata_de(punct, centru):
    x_sim = 2 * centru[0] - punct[0]
    y_sim = 2 * centru[1] - punct[1]
    return (x_sim, y_sim)

simetric = simetrie_fata_de((-3, -2), (5, 5))
print(f"Punct simetric: {simetric}")