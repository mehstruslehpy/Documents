#input
print("Enter an amount of seconds: ")
seconds = int(input())

#outputs in seconds minutes hours or days depending on this conditional
if seconds >= 86400:
    output = seconds / 86400
    print("There are " + str(output) + " days in " + str(seconds) + " seconds.")
elif seconds >= 3600:
    output = seconds / 3600
    print("There are " + str(output) + " hours in " + str(seconds) + " seconds.")
elif seconds >= 60:
    output = seconds / 60
    print("There are " + str(output) + " minutes in " + str(seconds) + " seconds.")
else:
    print("You entered " + str(seconds) + " seconds.")
