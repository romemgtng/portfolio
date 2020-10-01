import csv
import sys
from cs50 import SQL

if len(sys.argv) != 2:
    print('Usage: python roster.py houseName')
    sys.exit(1)

db = SQL('sqlite:///students.db')

# FILTER BY HOUSE
output = db.execute('SELECT * FROM students WHERE house = ? ORDER BY last, first', sys.argv[1])

# PRINT EACH STUDENT, CHECK IF MIDDLE NAME PRESENT
for row in output:
    if row['middle'] == None:
        print(f'{row["first"]} {row["last"]}, born {row["birth"]}')
    else:
        print(f'{row["first"]} {row["middle"]} {row["last"]}, born {row["birth"]}')