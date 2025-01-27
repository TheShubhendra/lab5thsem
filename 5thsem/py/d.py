# if int(input("Enter marks: ")) >=40:
#     print("Congratulations you have passed the exam.")
# else:
#     print("Sorry! You have failed the exam.")

# print("Congratulations you have passed the exam." if int(input("Enter marks: ")) >=40 else "Sorry! You have failed the exam.")

# print("Even" if int(input("Enter number: ")) %2==0 else "Odd.")

# a,b,c = map(int, input("Enter a, b and c: "))

# if a>b and a>c:
#     print(f"{a} is greater")
# elif b>a and b >c:
#     print(f"{b} is greater")
# else:
#     print(f"{c} is greater")

# print(eval(input("Enter operator1, operand and operator2: ")))


# c = ord(input("Enter a character: "))
# if 65<= c <=90:
#     print("Capital")
# elif 97 <= c <= 12:
#     print("Small")
# elif 48 <= c <=57:
#     print("Number")
# else:
#     print("SPecial")

# print(len("Krish"))

# for idx, ch in enumerate("Krish"):
#     print(f"charcter on {idx} is {ch}")
from random import randrange

for _ in range(10):
    c = randrange(31, 40)
    print(f"\033[{c}mShubhendra")
for _ in range(10, 21):
    c = randrange(31, 40)
    print(f"\033[{c}mShubhendra")
for _ in range(10, 41, 2):
    c = randrange(31, 40)
    print(f"\033[{c}mShubhendra")

# print(*tuple(range(10)), *tuple(range(0, 11, 2)), *tuple(range(10, 0, -1)))


print(sum(map(int, input("Enter list of numbers: ").split())))