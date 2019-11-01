sum_ = 0
cnt = 0
while True:
    n = input()
    cnt += 1
    if n == "end":
        break
    sum_ += int(n)
avg = sum_ // cnt
print("sum: " + str(sum_) + "\navg: " + str(avg))
