import numpy as np
from matplotlib import pyplot as plt
from math import pi

# 1
arr = np.array([[1, 3, 1, 2],
                [1, 2, 5, 8],
                [3, 1, 2, 9],
                [5, 4, 2, 1]])
# 2
arr = arr[1:-1, :-1]
# 3
arr2 = np.array([[2, 3, 1],
                 [5, 1, 3]])
# 4
arr2 = arr2.T
# 5
result = arr.dot(arr2)
# 6
v = np.arange(-pi, pi, pi)
plt.plot(v, np.sin(v))
v = np.arange(-pi, pi, 2*pi/10)
plt.plot(v, np.sin(v))
v = np.arange(-pi, pi, 2*pi/100)
plt.plot(v, np.sin(v))
plt.show()
print(result)
