"""
Name: Create Phone Number
Kata: 6 kyu
Link: https://www.codewars.com/kata/525f50e3b73515a6db000b83

Description: Write a function that accepts an array of 10 integers (between 0 and 9),
that returns a string of those numbers in the form of a phone number.

Example
create_phone_number(&[1,2,3,4,5,6,7,8,9,0]); // returns "(123) 456-7890"
The returned format must be correct in order to complete this challenge.

Don't forget the space after the closing parentheses!
"""

def create_phone_number(n):
    index = 0
    first = ""
    second = ""
    third = ""
    for digit in n:
        if (index < 3):
            first = first + str(digit)
        elif (index < 6):
            second = second + str(digit)
        else:
            third = third + str(digit)
        index += 1
    return "(" + first + ") " + second + "-" + third
