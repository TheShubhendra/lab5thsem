while True:
    user_input = input("Enter two numbers and an operator (+, -, *, /) or type 'exit' to quit: ")
    
    if user_input.lower() == "exit":
        break

    num1, num2, operator = user_input.split()
    num1 = float(num1)
    num2 = float(num2)

    if operator == "+":
        result = num1 + num2
    elif operator == "-":
        result = num1 - num2
    elif operator == "*":
        result = num1 * num2
    elif operator == "/":
        result = num1 / num2
    else:
        print("Invalid operator. Please use +, -, *, or /.")
        continue

    print(f"The result is: {result}")
