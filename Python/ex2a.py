N = []
i = 0
while (n := input()) != "end":
    N.append(int(n))
    i += 1
print("sum: " + str(sum(N)) + "\navg: " + str(sum(N)/len(N)))
