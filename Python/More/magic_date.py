#enter your values
print("Enter a month in two digit form: ")
month = int(input())
print("Enter a day of the month: ")
day = int(input())
print("Enter a year in two digit form: ")
year = int(input())

#the day * month must equal this year to be magic
yearCalc = day * month

#check and output
if year == yearCalc:
    print("The year equals the day times the month.")
    print("This date is magic.")
    exit()

print("The year does not equal the day times the month.")
print("This date is not magic.")
