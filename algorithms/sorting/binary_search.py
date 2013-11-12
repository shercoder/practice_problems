#!/usr/bin/python3

a = [13, 19, 21, 34, 48, 51, 56, 65, 67, 84, 88, 93]

def binary_search(a, low, high, value):
    if high < low:
        return None

    mid = (high+low)//2
    if a[mid] < value:
        return binary_search(a, mid+1, high, value)
    elif a[mid] > value:
        return binary_search(a, low, mid-1, value)
    else:
        return a[mid]

print(binary_search(a, 0, len(a)-1, 67))

def binary_search_iterative(a, value):
    low = 0
    high = len(a)-1
    while low <= high:
        mid = (low+high)//2
        if a[mid] < value:
            low = mid+1
        elif a[mid] > value:
            high = mid-1
        else:
            return a[mid]
    return None

print(binary_search_iterative(a, 34))