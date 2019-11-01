from math import pi, sqrt, atan, degrees

R = 1.0 * 10**3
L = 10 * 10**(-3)
C = 0.01 * 10**(-6)

f = int(input("周波数[kHz]を入力してください: ")) * 10**3
omega = 2 * pi * f

Z = sqrt(R**2 + ((X_L := omega*L) - 1 / ((X_C := omega*C)))**2)
phi = atan((X_L - 1/X_C) / R)

print(f"インピーダンス|Z| : {Z} [Ω]")
print(f"位相φ : {degrees(phi)} °(度)")
