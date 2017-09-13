import random

def caloriesBurned(miles, weight, sport='running'):
	if sport == 'running':
		calories = 0.75 * weight * miles
	elif sport == 'swimming':
		calories = 2.75 * weight * miles
	else:
		calories = 0.5 * weight * miles
	return calories
	
def users(domain, *users):
	for user in users:
		print("%s@%s" % (user, domain))
		
def f(**args):
	for key in args:
		print('%s=%s' % (key, str(args[key])))

def parameterPassing(i, str, A, B, C):
	i += 100
	str += '!'
	A.append(5)
	B[0] += '!'
	C.append(False)
	print('During')
	print(locals())
	print()
	
print(caloriesBurned(5.0, 150))
print(caloriesBurned(5.0, 150, 'running'))
print(caloriesBurned(weight=150, miles=5.0))
print(caloriesBurned(1.0, 175, 'swimming'))
print()

users('miamioh.edu', 'smithj', 'williamsw')
users('miamioh.edu', 'adamsp', 'hinojosar', 'pierceg')
print()

f(first=0, second=1, third=2)
print()

x = 3
s = 'hello'
L1 = [1,2,3,4]
L2 = ['a', 'b', 'c']
L3 = [True] * 3
print('Before')
print(globals())
print()

parameterPassing(x, s, L1, L2, L3[:])
print('After')
print(globals())
print()
