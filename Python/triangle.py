#!/usr/bin/python2
#use at your own risk
#I do not guarantee the correctness of this program
#I mainly made this to try and generate an already known solution

#we will need to do square roots later
#we are using cmath because the normal
#math module gives an error when we it sqrt(-1)
from cmath import sqrt

#We're going to explain the problem to the user:
print("          #                                        ")
print("         ###                                       ")
print("        # # #                                      ")
print("       #  #  #                                     ")
print("      #   #   #                                    ")
print("1 -> #    #    #   <- 2                            ")
print("    #     #     #                                  ")
print("   #      # <- 3 #                                 ")
print("  #       #       #                                ")
print(" #        #        #                               ")
print("#####################                              ")
print("     ^         ^                                   ")
print("     |         |                                   ")
print("     c/2       c/2                                 ")
print("In this program we will return the length of side c")

#now gather user input
print("Enter the length of side one: ")
side1 = float(input())
print("Enter the length of side two: ")
side2 = float(input())
print("Enter the length of the median(side three): ")
median = float(input())

#To solve this problem we need:
#
#the law of cosines:
# c^2 = a^2 + b^2 -2ab cos(theta)
#
#and a system of equations built from the law of cosines:
#for the triangle consisting of side 3, side 2, and side c/2 which we will call E1 (short for equation one)
#E1: side3^2 = side2^2 + (c/2)^2 - 2(side2)(c/2)cos(theta)
#for the triangle consisting of side 1, side 3, and side c which we will call E2
#E2: side1^2 = side2^2 + c^2 - 2(side1)(c)cos(theta)

#########
# FOR E2 (we are using the a b and c variable names from the law of cosines here..)
#########
#c^2
c_2 = side1**2
#a^2
a_2 = side2**2
#the coefficient of b * cos(theta)
coeff = -2.0 * side2

#########
# FOR E1 (same as prev but with _1 to mean equation one)
#########
#c^2
c_1 = median**2
#a^2
a_1 = side2**2
#the coefficient of b * cos(theta)
coeff = -2.0 * side2

#The following will be done to solve our system of equations by elimination
#
#       E2: c^2 = a^2 + b^2 -2ab cos(theta)
#  -2 * E1: c^2 = a^2 + b^2 -2ab cos(theta)
#  -----------------------------------
#           c_3 = a_3 + -2 * a_3
#as shown multiplying E1 by -2 allows us to cancel out cos(theta) and various coefficients of it

############
# -2 * E1
############
#-2 * c^2
c_1 = c_1 * -2
#-2 * a^2
a_1 = a_1 * -2
#coeff of b * cos(theta)
coeff = coeff * -2

######
# Elimination:
######
# E3 = E1 + E2
c_3 = c_1 + c_2
a_3 = a_1 + a_2
c_3 = c_3 + (-1 * a_3)
c_3 = c_3 * 2
c_3 = sqrt(c_3)

print("")
print("Side C is: " +  str(c_3) + " units")
print("Note: j = sqrt(-1)")
