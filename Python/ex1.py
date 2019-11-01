n = int(input())
flg = False
if n % 4 == 0:
    if n % 100:
        flg = True
    elif n % 400 == 0:
        flg = True
print(str(n) + "年は" + ("閏" if flg else "平") + "年である．")
