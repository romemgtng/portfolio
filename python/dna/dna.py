import csv
import sys
from sys import argv

# CHECK FOR VALID INPUTE
if len(argv) != 3:
    print('Usage: python dna.py data.csv sequence.txt')
    sys.exit(1)

# READ CSV FILE
csvFile = open(argv[1], 'r')
reader = list(csv.reader(csvFile))
i = reader[1]

# READ TEXT FILE
seqFile = open(argv[2], 'r')
dna = seqFile.read()

strValue = []

# FIND LARGEST CONSECUTIVE INSTANCES
for i in range(1, len(reader[0])):
    count = 1
    strCheck = reader[0][i]
    while strCheck * count in dna:
        count += 1
    strValue.append(str(count-1))

# ITERATE THROUGH CSV FILE, FIND A MATCH
for j in range(1, len(reader)):
    if reader[j][1:len(reader[0])] == strValue:
        print(reader[j][0])
        exit(0)
    elif (j == len(reader)-1) and reader[j][1:len(reader[0])] != strValue:
        print('No match.')