y = int(input())
for i in range(2, y + 1):
    flg = True
    for j in range(2, i//2 + 1):
        if i % j == 0:
            flg = False
            break
    if flg:
        print(i)
