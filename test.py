import numpy as np

x = np.array([[1, 2, 3], [4, 5, 6]])
y = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])
print("z=xy")
print(np.dot(x, y))

a = np.array([2, 3])
b = np.array([4, 5, 6])
c = np.array([7, 8, 9, 10])
print("aT*b")
print(np.dot(a.reshape(2, 1), b.reshape(1, 3)))

x_apo = x + np.dot(a.reshape(2, 1), b.reshape(1, 3))
print("x_apo")
print(x_apo)

y_apo = y + np.dot(b.reshape(3, 1), c.reshape(1, 4))
print("y_apo")
print(y_apo)

z_apo = np.dot(x_apo, y_apo)
print("z_apo")
print(z_apo)

xy = z_apo - np.dot(np.dot(x, b.reshape(3, 1)), c.reshape(1, 4))
xy = xy - np.dot(np.dot(a.reshape(2, 1), b.reshape(1, 3)), y)
xy = xy - np.dot(
    np.dot(np.dot(a.reshape(2, 1), b.reshape(1, 3)), b.reshape(3, 1)),
    c.reshape(1, 4))
print(xy)

xy = x + np.dot(a.reshape(2, 1), b.reshape(1, 3))
xy = np.dot(xy, b.reshape(3, 1))
xy = np.dot(xy, c.reshape(1, 4))
xy = xy + np.dot(a.reshape(2, 1), np.dot(b.reshape(1, 3), y))
xy = z_apo - xy
print(xy)
