import csv
import sys
from cs50 import SQL

# CHECK FOR VALID INPUT
if len(sys.argv) != 2:
    print('Usage: python import.py file.csv')
    sys.exit(1)

db = SQL('sqlite:///students.db')

# READ CSV FILE
csvFile = open(sys.argv[1], 'r')
reader = list(csv.reader(csvFile))

for i in range(1, len(reader)):
    fullName = reader[i][0].split()

    # CHECK IF THERE IS MIDDLE NAME
    if len(fullName) == 2:
        firstName = fullName[0]
        midName = None
        lastName = fullName[1]
    else:
        firstName = fullName[0]
        midName = fullName[1]
        lastName = fullName[2]

    house = reader[i][1]
    birth = reader[i][2]

    # INSERT VALUES INTO DB FILE
    db.execute('INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)', firstName, midName, lastName, house, birth)