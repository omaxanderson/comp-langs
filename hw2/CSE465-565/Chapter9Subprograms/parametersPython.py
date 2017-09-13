import sys

def f1(x):
    x = x + "!"

def f2(x):
    x = x + 1
	
def f3(list):
	list = [1,2,3]

def f4(list):
	list[0] = -100

s1 = "hello"
i1 = 34

f1(s1)
f2(i1)
list1 = [0,1,2,3,4,5,6,7,8,9];
list2 = [0,1,2,3,4,5,6,7,8,9];
f3(list1);
f4(list2)

print(s1)
print(i1)
print(list1)
print(list2)
