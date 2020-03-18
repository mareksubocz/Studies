from __future__ import division
from math import log2, sin, cos
from matplotlib import pyplot as plt
import numpy as np
# from sympy import *
import sympy as sym
from sympy.interactive import printing
printing.init_printing(use_latex=True)

# 1
x = sym.Symbol("k")
eq = (-x**3 + 3*x**2 + 10*x - 24)
v = np.arange(-5, 5, 0.1)
plt.plot(v, [eq.evalf(subs={x: a}) for a in v])
print(sym.solve(eq))
plt.show()

# 2
x, y = sym.symbols("x y")
eq1 = (x**2 + 3*y - 10)
eq2 = (4*x - y**2 + 2)
solutions = sym.solve((eq1, eq2))
print(solutions)

# 3
print(len(solutions))

# 4
for s in solutions:
    for k, v in s.items():
        print(k, v.evalf())

# 5
eq = (sym.sin(sym.log(x, 2)) * sym.cos(x**2)/x)
print(sym.diff(eq))
