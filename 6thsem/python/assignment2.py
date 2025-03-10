def power(base, exponent):
    if exponent == 0:
        return 1
    if exponent < 0:
        return 1 / power(base, -exponent)
    return base * power(base, exponent - 1)

def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)

# write a recursive function that takes a number n as an input parameters and printes n digit strictl yincreaseing numbers
def print_numbers(n):
    if n == 1:
        print(0)
    else:
        print_numbers(n - 1)
        for i in range(10 ** (n - 1), 10 ** n):
            print(i)

def nth_fibonacci(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return nth_fibonacci(n - 1) + nth_fibonacci(n - 2)
    
def kth_largest(arr, k):
    """
    Find Kth largest in O(n) using recursion"
    """
    pass



# My name Bapi I have copy two or three
# I insert floppy in my pocket and I go
#
