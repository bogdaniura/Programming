import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

vertices = np.array([
    [0, 0, 0, 1], 
    [1, 0, 0, 1],
    [1, 1, 0, 1],
    [0, 1, 0, 1],
    [0, 0, 1, 1],
    [1, 0, 1, 1],
    [1, 1, 1, 1],
    [0, 1, 1, 1]
])

edges = [  
    (0,1), (1,2), (2,3), (3,0),
    (4,5), (5,6), (6,7), (7,4),
    (0,4), (1,5), (2,6), (3,7)
]

def translation_matrix(tx, ty, tz):
    return np.array([
        [1, 0, 0, tx],
        [0, 1, 0, ty],
        [0, 0, 1, tz],
        [0, 0, 0, 1]
    ])

T = translation_matrix(1.5, 1, 0.5)
translated_vertices = vertices @ T.T 

fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

for edge in edges:
    ax.plot3D(*zip(*vertices[edge, :3]), color='blue', linewidth=2, alpha=0.5, label='Original')

for edge in edges:
    ax.plot3D(*zip(*translated_vertices[edge, :3]), color='red', linestyle='--', linewidth=2, label='Translatat')

ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_xlim([-1, 3])
ax.set_ylim([-1, 3])
ax.set_zlim([-1, 3])
ax.set_title('Translatie 3D: (tx=1.5, ty=1, tz=0.5)')

handles, labels = ax.get_legend_handles_labels()
unique = [(h, l) for i, (h, l) in enumerate(zip(handles, labels)) if l not in labels[:i]]
ax.legend(*zip(*unique))

ax.view_init(elev=25, azim=-45)
plt.show()