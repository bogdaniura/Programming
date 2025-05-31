import matplotlib.pyplot as plt
import numpy as np

fig, ax = plt.subplots(figsize=(8, 8))

ax.spines['left'].set_position('zero')
ax.spines['bottom'].set_position('zero')
ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')

ax.set_xlim(-6, 6)
ax.set_ylim(-6, 6)

ax.grid(True, linestyle='--', alpha=0.7)

x_vertical = [3]*100
y_vertical = np.linspace(-5, 5, 100)
ax.plot(x_vertical, y_vertical, color='blue', label='Verticala (x=3)')

y_orizontal = [2]*100 
x_orizontal = np.linspace(-5, 5, 100)
ax.plot(x_orizontal, y_orizontal, color='red', label='Orizontala (y=2)')

x_oblic = np.linspace(-5, 5, 100)
y_oblic = 0.5*x_oblic + 1 
ax.plot(x_oblic, y_oblic, color='green', label='Oblica (y=0.5x+1)')

ax.legend(loc='upper right')
ax.set_title("Sistem de axe OXY cu 3 drepte", pad=20)

plt.show()