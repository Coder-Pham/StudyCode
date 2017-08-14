# Insertion Sort

import random

print("Insertion Sort")

numbers = [i for i in range(10)]
random.shuffle(numbers)

def InsertionSort(a):
    for i in range(1, len(a)):
        x = a[i]
        j = i
        while (j > 0) and (x < a[j-1]):
            a[j] = a[j-1]
            j -= 1
    a[j] = x

InsertionSort(numbers)

print(numbers)
