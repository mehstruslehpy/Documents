#program to enter mass and print weight
print("Enter the objects mass in in kilograms:")

#convert and assign
mass = float(input())

#calculate the weight in newtons
weight = mass * 9.8

#determine if the value of weight is in range
#if it is not say so and exit
#if it is print the conversion from mass to weight
if weight > 1000:
    print("Your object is too heavy.")
    exit()
elif weight < 10:
    print("Your object is too light.")
    exit()
else:
    print("Your object weighs: " + str(weight) + " newtons.")
