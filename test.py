import numpy as np
from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt

x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)
X, Y = np.meshgrid(x, y)

fig = plt.figure()
ax = plt.axes(projection='3d')
ax.plot_surface(X, Y, Z=3 - X - Y, color='blue', alpha=0.6)

x = np.linspace(0, 2 * np.pi, 100)
y = np.linspace(0, np.pi, 100)
X = 3 * np.outer(np.cos(x), np.sin(y))
Y = 3 * np.outer(np.sin(x), np.sin(y))
z = 3 * np.outer(np.ones(np.size(x)), np.cos(y))
# fig = plt.figure()
# ax = plt.axes(projection='3d')
ax.plot_surface(X, Y, z, color='red', alpha=0.6)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.view_init(
    elev=15,  # 仰角
    azim=60  # 方位角
)
plt.show()