sum_ = 0
cnt = 0
while True:
    n = input()
    if n == "end":
        break
    try:
        sum_ += int(n)
    except ValueError:
        print("整数を入力してください")
        print("入力し終わったら\'end\'を入力してください")
        continue
    except ZeroDivisionError:
        print("整数を1つ以上入力してください")
        continue
    cnt += 1
avg = sum_ // cnt
print("sum: " + str(sum_) + "\navg: " + str(avg))
