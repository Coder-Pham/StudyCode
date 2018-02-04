# Bubble Sort

print("Bubble Sort")

numbers = [8, 1, 7, 2, 9, 6, 3, 0, 5, 4]

def BubbleSort(a):
	sorted = True
	for i in range(len(a) - 1):
		if (a[i] > a[i+1]):
			a[i], a[i+1] = a[i+1], a[i]
			sorted = False

	if (sorted == False):
		BubbleSort(a)

BubbleSort(numbers)

print(numbers)