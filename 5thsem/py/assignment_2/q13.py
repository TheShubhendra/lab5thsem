pos = input("Enter the position (e.g., e4): ")
column = pos[0]
row = int(pos[1])

if column in 'abcdefgh' and 1 <= row <= 8:
    col_index = ord(column) - ord('a') + 1
    color = 'white' if (col_index + row) % 2 == 0 else 'black'
    print(f"The square {pos} is {color}.")
else:
    print("Invalid position.")
