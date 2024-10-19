room_type = input("Enter room type (Standard, Deluxe, Suite): ")
nights = int(input("Enter length of stay (in nights): "))
season = input("Enter season (Peak, Off, Regular): ")
loyalty_member = input("Are you a loyalty member? (yes/no): ")

room_prices = {
    "Standard": 100,
    "Deluxe": 150,
    "Suite": 250
}

base_cost = room_prices.get(room_type, 0) * nights

if nights > 7:
    discount = 0.20
elif nights > 3:
    discount = 0.10
else:
    discount = 0.0

base_cost -= base_cost * discount

if season == "Peak":
    base_cost += base_cost * 0.20
elif season == "Off":
    base_cost -= base_cost * 0.15

if loyalty_member.lower() == "yes":
    base_cost -= base_cost * 0.05

print(f"The final booking cost is: ${base_cost:.2f}")
