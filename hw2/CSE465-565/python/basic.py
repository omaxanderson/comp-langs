import math

# Basic logical statements

x = int(input('Enter a number: '))
y = int(input('Enter another number: '))
areEqual = (x == y)
if areEqual:
	print('The numbers are equal')
else:
	print('The numbers are not equal')


if x > y:
	print('The first is bigger')
elif x < y:
	print('The second is bigger')
else:
	print('The numbers are equal')
	print('But we already printed that message')


xIsEven = x % 2 == 0
yIsEven = y % 2 == 0

if xIsEven and yIsEven:
	print('Both numbers are even')

# what is the output of the following code?

if x > 0:
	if y > 0:
		print('A')
else:
	if y > 0:
		print('B')
	elif y < 0:
		print('C')
	else:
		print('D')
