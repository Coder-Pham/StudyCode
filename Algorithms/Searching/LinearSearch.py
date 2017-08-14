# Linear Search

import random

a = [i for i in range(10)]
random.shuffle(a)
print(a)

search_val = int(input("Search number? "))
found = False

for i in range(10):
    if (a[i] == search_val):
        print("Pos = " + str(i))
        found = True
        break

if (found == False):
    print("Not found!")
