#!/usr/bin/python3

# makes O(n log n) comparisons on avg
# O(n^2) worst case comparisons (rare)

A = [56,93,65,34,13,19,88,84,67,48,51,21]
def quicksort(a):
    if len(a) <= 1:
        return a

    end = len(a)-1
    pivot = a[end]

    less = []
    more = []
    pivots = []
    for i in a:
        if i < pivot:
            less.append(i)
        elif i > pivot:
            more.append(i)
        else:
            pivots.append(i)
    less = quicksort(less)
    more = quicksort(more)
    return less + pivots + more

print(quicksort(A))