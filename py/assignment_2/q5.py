y = int(input())
is_leap = (y % 4 == 0 and y % 100 != 0) or (y % 400 == 0)
print("Leap Year" if is_leap else "Not a Leap Year")
