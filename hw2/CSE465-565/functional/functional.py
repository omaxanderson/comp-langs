import functools, operator, math

# lambda
def exp(x, y): return x ** y  # single expression

f = lambda x, y : x ** y
print(f(2, 3), f(3, 2))
print((lambda x, y : x ** y)(2, 3), (lambda x, y : x ** y)(3, 2))
print(exp(2, 3), exp(3, 2))

funcs = { 'sqr' : lambda x : x ** 2, 'cube' : lambda x : x ** 3, 'cos' : lambda x : math.cos(x) }
print(funcs['sqr'](2), funcs['cube'](2), funcs['cos'](2))

# basic list comprehensions
N = 4
L1 = []
for i in range(N):
    L1.append(i)
    
L2 = [i for i in range(N)]
L3 = [i*i for i in range(N)]
L4 = [i for i in range(N) if i % 2 == 0]

print(L1, L2, L3, L4)

zeroMatrix = [[0]*N for i in range(N)]
identityMatrix = [[1 if i==j else 0 for i in range(N)] for j in range(N)]
print(zeroMatrix)
print(identityMatrix)

cards = [(i,j) for i in range(1, 14) for j in range(4)]
print(cards)

#functional stuff
L = [1, 2, 3, 4]
def doubleIt(x) : return 2 * x

def totalItems(items):
    total = 0
    for item in items:
        total += item
    return total

def evens(items):
    L = []
    for item in items:
        if item % 2 == 0: L.append(item)
    return L

def allEven(items):
    for item in items:
        if item % 2 != 0: return False
    return True

def atLeastOneEven(items):
    for item in items:
        if item % 2 == 0: return True
    return False

print(L, list(map(doubleIt, L)), list(map(lambda x : 2 * x, L)), [doubleIt(i) for i in L])
print(list(filter(lambda x : x % 2 == 0, L)), evens(L))
print(sum(L), totalItems(L), functools.reduce(operator.add, L), functools.reduce(lambda x, y: x + y, L))
print(any(map(lambda x : x % 2 == 0, L)), atLeastOneEven(L))
print(all(map(lambda x : x % 2 == 0, L)), allEven(L))

