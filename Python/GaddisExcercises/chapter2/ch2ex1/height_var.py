heightInches = input("Input your height in inches: ")
print("Your height is:", heightInches, "inches")

#type conversion from string to number
heightInt = float(heightInches)
heightFeet = heightInt / 12
print("Your height is:", heightFeet, "feet")
