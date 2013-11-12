#!/usr/bin/python3

# Properties
# O(1) space
# O(n^2) time
# Good for small data set and almost sorted data set

a = [3,7,4,9,5,2,6,1]
print(a)
i = 1
while i < len(a):
  valueToInsert = a[i]
  holePos = i
  while holePos > 0 and valueToInsert < a[holePos-1]:
    a[holePos] = a[holePos-1]
    holePos = holePos-1
  a[holePos] = valueToInsert
  i += 1

print(a)
