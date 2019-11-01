N = []
while (n := input()) != "end":
    N.append(int(n))
print("sum: " + str(sum(N)))
print("avg: " + str(sum(N)/len(N)))  # ここZero除算ありえる
