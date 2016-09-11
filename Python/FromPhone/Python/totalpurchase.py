print("Enter first item price:")
item1 = float(input())
print("Enter second item price:")
item2 = float(input())
print("Enter third item price:")
item3 = float(input())
print("Enter fourth item price:")
item4 = float(input())
print("Enter fifth item price:")
item5 = float(input())

subtotal = item1 + item2 + item3 + item4 +item5
tax = 0.06 * subtotal
total = subtotal + tax

print("Subtotal:", subtotal, "\nTax:", tax, "\nTotal", total)