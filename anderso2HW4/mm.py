import sys
import re

inputTsv = None
inputTmp = None

if len(sys.argv) == 3:
	inputTsv = open(sys.argv[1], "r")

# set up the records list, attribute/index dict, and template list
records = []
for line in inputTsv:
	records.append(re.split('\t', line))

attributes = {}
for i in range(len(records[0])):
	attributes[records[0][i].strip()] = i


# iterates through each record, matching the appropriate values 
# to the tags in the template
# as a note, by splitting along spaces and tabs, I lose the tabs
# when I put it back together. I could have done this without splitting
# but I got lazy
for i in range(1, len(records)):
	# output file creation
	out = open(records[i][attributes["ID"]] + ".txt", "w")

	#open up the template and put it in a list
	inputTmp = open(sys.argv[2], "r")
	template = []
	for line in inputTmp:
		template.append(re.split(' |\t', line))
	
	for line in template:
		for j in range(len(line)):
			if "<<" in line[j]:
				# obtain the start and end index of the tag and replace
				# the tag with the attribute in the records
				startIdx = line[j].index("<<")
				endIdx = line[j].index(">>")
				tag = line[j][startIdx+2:endIdx]
				before = line[j][0:startIdx]
				after = line[j][endIdx + 2:len(line[j])].strip()
				line[j] = before + records[i][attributes[tag]].strip() + after 

		# actual file io
		for tok in line:
			if tok != '\n':
				#print(tok + " ", end='')
				out.write(tok + " ")
		#print()
		out.write("\n")
	print(out.name + " written (" + str(i) + "/" + str(len(records) - 1) + ").")
	out.close()

print("Done.")	
