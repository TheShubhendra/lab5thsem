u = int(input("Enter a number: "))
total = 0

for num in range(2, u):
    is_prime = True
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            is_prime = False
            break
    if is_prime:
        total += num

print(f"Sum of all prime numbers less than {u} is {total}.")
