# properties
# O(1) space
# O(n^2) comparisons
# O(n) swaps
a = [64,25,12,22,11]
print(a)
j = 0
while j < len(a)-1:
  imin = j
  i = j+1
  while i < len(a):
    if a[i] < a[imin]:
      imin = i
    i+=1
  if imin != j:
    a[j] ^= a[imin]
    a[imin] ^= a[j]
    a[j] ^= a[imin]
  j+=1

print(a)
