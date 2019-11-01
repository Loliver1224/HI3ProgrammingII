def isPrime(n):
    flg = True
    for i in range(2, n//2 + 1):
        if n % i == 0:
            flg = False
            print(flg)
            break
    else:
        if n == 1:
            flg = False
    return flg

n = int(input())
print(str(n) + "は素数で" + ("ある" if isPrime(n) else "ない") + "．")
