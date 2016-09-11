#setup rectangle one
print("Enter the length of Rectangle One:")
length = float(input())
print("Enter the width of Rectangle One:")
width = float(input())
rectangleOne = width * length

#setup rectangle two
print("Enter the length of Rectangle Two:")
length = float(input())
print("Enter the width of Rectangle Two:")
width = float(input())
rectangleTwo = width * length

#compare and print the bigger of the two
if rectangleOne > rectangleTwo:
    print("Rectangle one is larger.\n")
elif rectangleTwo > rectangleOne:
    print("Rectangle two is larger.\n")
else:
    print("The two rectangles are equal.\n")
    exit()
