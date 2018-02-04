# Selection Sort

print("Selection Sort")

numbers = [8, 1, 7, 2, 9, 6, 3, 0, 5, 4]

def SelectionSort(a):
	for i in range(len(a)):
		minpos = i
		for j in range(i+1, len(a)):
			if (a[j] < a[minpos]):
				minpos = j

		if (a[i] > a[minpos]):
			a[i], a[minpos] = a[minpos], a[i]

SelectionSort(numbers)

print(numbers)