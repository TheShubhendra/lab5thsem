def factors(n):
    res = []
    for i in range(2, n+1):
        while n%i==0:
            res.append(i)
            n/=i
    return sorted(res)

print(factors(45))