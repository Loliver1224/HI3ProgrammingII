import math

R = 1.0 * 10**3
L = 10 * 10**(-3)
C = 0.01 * 10**(-6)

f = float(input("周波数[kHz]を入力してください: ")) * 10**3
omega = 2 * math.pi * f

Z = math.sqrt(R**2 + (omega*L - 1 / (omega*C))**2)
phi = math.atan((omega*L - 1 / (omega*C)) / R)

print(f"インピーダンス|Z| : {Z} [Ω]")
print(f"位相φ : {math.degrees(phi)} °(度)")
