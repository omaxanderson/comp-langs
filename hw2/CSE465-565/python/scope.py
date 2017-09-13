x = 0

def f1():
	print('In F1 ', x)
	
def f2():
	x = 2
	print('In F2 ', x)

def f3():
	global x
	x = 3
	print('In F3 ', x)
	
def f4():
	def nested1():
		nonlocal x
		x = 4
	def nested2():
		global x
		x = 5
	x = 6
	nested1()
	print(x)
	nested2()
	print(x)

print('At beginning of main ', x)
f4()
print('At end of main ', x)
