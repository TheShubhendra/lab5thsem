

import math

def sx():
    pass


def cos(x):
    sum = 1
    k = -1
    t = 1
    n = 1
    d = 1
    i = 1
    while abs(t)>0.00001:
        n = n*x*x
        d*= (i*(i+1))
        i+=2
        t = (n/d)*k
        sum+=t
        k*=-1
    return sum

print(cos(math.pi/4))