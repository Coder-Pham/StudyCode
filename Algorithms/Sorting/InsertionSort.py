# Insertion Sort

print("Insertion Sort")

numbers = [8, 1, 7, 2, 9, 6, 3, 0, 5, 4]

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