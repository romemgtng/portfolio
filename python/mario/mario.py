from cs50 import get_int

height = 0

while height < 1 or height > 8:
    height = get_int('Height: ')

i = 0
for i in range(height):
    print(' '*(height - i - 1) + '#'*(i + 1))
