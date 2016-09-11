print("Enter the amount of your purchase:")
purAmt = float(input())
stateTax = purAmt * 0.04
countyTax = purAmt * 0.02
totalTax = stateTax + countyTax
totalAmt = purAmt + totalTax

print("State tax:", stateTax)
print("County tax:", countyTax)
print("Total tax:", totalTax)
print("Total amount:", totalAmt)