def divisors(n):
    res = []
    for i in range(1, n):
        if n%i==0:
            res.append(i)

    return res


for i in range(1, 101):
    if i==sum(divisors(i)):
        print(i, end=" ")