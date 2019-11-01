import math

R = 100
L = 20 * 10**(-3)
C = 0.01 * 10**(-6)
f = 1000
omega = 2 * math.pi * f
t = int(input())
v = 5.0*math.sin(omega*t)

Z = math.sqrt(R**2 + (omega*L - omega*C))


print("(1)\ni(t) = " + str())

f0 = 1 / (2 * math.pi * math.sqrt(L * C))
print("(2)\n共振周波数: " + str(f0))
