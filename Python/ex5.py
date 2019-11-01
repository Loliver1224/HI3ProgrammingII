sum_ = 0
i = 0
while True:
    try:
        n = input()
        if n == "end":
            break
        sum_ += int(n)
        i += 1
    except ValueError:
        print("整数を入力してください")
        continue
avg = sum_ // i
print("sum: " + str(sum_) + "\navg: " + str(avg))
