num = input("Enter an integer: ")
digits = set(num)

digit_names = {
    '0': 'ZERO', '1': 'ONE', '2': 'TWO', '3': 'THREE',
    '4': 'FOUR', '5': 'FIVE', '6': 'SIX', '7': 'SEVEN',
    '8': 'EIGHT', '9': 'NINE'
}

output = [digit_names[d] for d in sorted(digits)]
print("Digits that appeared:", " ".join(output))
