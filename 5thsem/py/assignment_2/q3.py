score = float(input("Enter the student's numeric score (0-100): "))

if 90 <= score <= 100:
    print("Letter Grade: A - Excellent")
elif 80 <= score < 90:
    print("Letter Grade: B - Good")
elif 70 <= score < 80:
    print("Letter Grade: C - Average")
elif 60 <= score < 70:
    print("Letter Grade: D - Needs Improvement")
elif score < 60:
    print("Letter Grade: F - Failing")
else:
    print("Invalid score")

a = float(input("Enter the length of side a: "))
b = float(input("Enter the length of side b: "))
c = float(input("Enter the length of side c: "))

if a <= 0 or b <= 0 or c <= 0:
    print("Invalid side lengths. All sides must be positive.")
elif a + b <= c or a + c <= b or b + c <= a:
    print("Not a triangle.")
elif a == b == c:
    print("Equilateral triangle.")
elif a == b or b == c or a == c:
    print("Isosceles triangle.")
else:
    print("Scalene triangle.")
