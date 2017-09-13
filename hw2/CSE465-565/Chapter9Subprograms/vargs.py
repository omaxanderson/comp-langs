import sys

def addem(*list):
	sum = 0
	for i in list:
		sum += i
	return sum

def power(base, *exps):
	result = []
	for E in exps:
		result.append(base**E)
	return result


print(addem(1, 2, 3, 4))
print(power(2, 3, 4, 5, 10))
