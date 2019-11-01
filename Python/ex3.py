n = int(input())
flg = True
for i in range(2, n//2 + 1):
    if n % i == 0:
        flg = False
        print(flg)
        break
else:
    if n == 1:
        flg = False
print(str(n) + "は素数で" + ("ある" if flg else "ない") + "．")
