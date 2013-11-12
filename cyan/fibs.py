#!/usr/bin/python3

def fib(n):
    if n < 0: return -1
    if n == 0: return 0
    if n == 1: return 1
    a, b = 0, 1
    while n:
        a, b = b, a+b
        n  -= 1
    print(b)

fib(10)


def insertion(a):
    i = 1
    while i < len(a):
        valueToInsert = a[i]
        hole = i
        while hole > 0 and valueToInsert < a[hole-1]:
                a[hole] = a[hole-1]
                hole -=1
        a[hole] = valueToInsert
        i += 1

def selection(a):
    j = 0
    while j < len(a)-1:
        imin = j
        i = j +1
        while i < len(a):
            if a[i] < a[imin]:
                imin = i
            i+=1
        if imin != j:
            a[j] ^= a[imin]
            a[imin] ^= a[j]
            a[j] ^= a[imin]
        j+=1