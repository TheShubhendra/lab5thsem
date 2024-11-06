from random import randrange
count = {i: 0 for i in range(1, 7)}
for i in range(6*10**6):
    x = randrange(1, 7)
    count[x] = count[x] + 1

print(f"Digit{'Frequency':>13}")
for i,j in count.items():
    print(f"{i:>5}{j:>13}")