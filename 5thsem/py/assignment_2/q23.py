atm_balance = 1000

amount = int(input("Enter the amount to withdraw: "))

if amount % 10 != 0:
    print("Please enter an amount that is a multiple of 10.")
elif amount > atm_balance:
    print("Insufficient funds in the ATM.")
else:
    atm_balance -= amount
    notes_100 = amount // 100
    amount %= 100
    notes_50 = amount // 50
    amount %= 50
    notes_20 = amount // 20
    amount %= 20
    notes_10 = amount // 10

    print("Dispensed notes:")
    print(f"100s: {notes_100}, 50s: {notes_50}, 20s: {notes_20}, 10s: {notes_10}")
