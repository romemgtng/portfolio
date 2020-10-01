from cs50 import get_string
import re

text = get_string('Text: ')

i = 0
letters = 0
sentences = 0

for i in text:
    if i.isalnum():
        letters += 1
    if i == '.' or i == '?' or i == '!':
        sentences += 1

words = len(text.split())

print(f'Letters: {letters} Words: {words} Sentences: {sentences}')

L = (letters/words) * 100
S = (sentences/words) * 100
index = 0.0588*L - 0.296*S - 15.8
grade = int(round(index))

print(f'L: {L} S: {S} Index: {index} Grade: {grade}')

if grade < 1:
    print('Before Grade 1')
elif grade > 16:
    print('Grade 16+')
else:
    print(f'Grade {grade}')