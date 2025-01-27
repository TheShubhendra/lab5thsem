import math

def series_a(x, n):


def series_b(x, n):

    return total

def series_c(n):

    return total

n = int(input("Enter the number of terms (n): "))
x = float(input("Enter the value of x: "))
total = 0
for i in range(n + 1):
    total += ((-1) ** i) * (x ** (2 * i)) / math.factorial(2 * i)
total = 0
for i in range(n + 1):
    total += (x ** i) / math.factorial(i)
total = 0
for i in range(n):
    total += ((-1) ** i) * (2 * i + 1)
print(f"Sum of series a: {total}")
print(f"Sum of series b: {total}")
print(f"Sum of series c: {total}")
