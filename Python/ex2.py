sum_ = 0
i = 0
while True:
    n = input()
    if n == "end":
        break
    sum_ += int(n)
    i += 1
avg = sum_ // i
print("sum: " + str(sum_) + "\navg: " + str(avg))
