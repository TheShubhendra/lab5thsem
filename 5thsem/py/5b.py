x = [4, 4, 5, 2]

res = []

for i in x:
    if x.count(i)>1:
        res.append(i)

print(res)