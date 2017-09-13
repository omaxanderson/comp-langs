with open("items.csv", "rt") as input, open("sorted.txt", "w") as output:
	for line in input:
		strToks = line.strip().split(',')
		intValues = list(map(lambda x : int(x), strToks))
		for v in sorted(intValues):
			output.write(str(v) + " ")
		output.write('\n')
