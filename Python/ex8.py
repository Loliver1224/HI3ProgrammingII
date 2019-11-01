def isLeapYear(year):
    flg = False
    if n % 4 == 0:
        if n % 100:
            flg = True
        elif n % 400 == 0:
            flg = True
    return flg

n = int(input())
print(str(n) + "年は" + ("閏" if isLeapYear(n) else "平") + "年である．")
