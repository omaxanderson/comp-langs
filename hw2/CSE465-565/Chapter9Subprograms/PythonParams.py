def f1(lst, x):
	lst = [1,2,3]
	x = 3
	
def f2(lst, x):
	lst[0] += 20000
	x += 1

def f3(lst, x):
	lst.append(0);
	x = x + 1

L1 = [100, 200, 300]
x1 = 0
f1(L1, x1)
print(L1, x1)

L2 = [100, 200, 300]
x2 = 0
f2(L2, x2)
print(L2, x2)	
	
L3 = [100, 200, 300]
x3 = 0
f3(L3, x3)
print(L3, x3)	
