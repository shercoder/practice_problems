#!/usr/bin/python3

# Worst case: O(N log N) (time complexity)
# Worst case: O(n) (space)
A = [56,93,65,34,13,19,88,84,67,48,51,21]
def merge_sort(a):
    if len(a) <= 1:
        return a

    mid_point = len(a)//2
    left = merge_sort(a[:mid_point])
    right = merge_sort(a[mid_point:])

    result = []
    while len(left) > 0 and len(right) > 0:
        if left[0] < right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))
    if len(left) > 0:
        result.extend(left)
        # result.extend(merge_sort(left))
    else:
        result.extend(right)
        # result.extend(merge_sort(right))
    return result

print(merge_sort(A))