"""mathつかったやつ
from math import floor
x = float(input("INPUT REAL: "))
print(floor(x), x-floor(x), sep='\n')
"""
x = float(input("INPUT REAL: "))
print(f"{int(x)}\n{x-int(x):.4f}")
