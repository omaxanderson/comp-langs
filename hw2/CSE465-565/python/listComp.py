print([ x * x for x in range(12) if x % 3 == 0 ])

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
