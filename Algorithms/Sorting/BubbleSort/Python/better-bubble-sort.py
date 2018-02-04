# Bubble Sort

print("Better Bubble Sort")

numbers = [8, 1, 7, 2, 9, 6, 3, 0, 5, 4]

def BetterBubbleSort(a, unsorted_len):
	sorted = True
	for i in range(unsorted_len - 1):
		if (a[i] > a[i+1]):
			a[i], a[i+1] = a[i+1], a[i]
			sorted = False

	if (sorted == False):
		BetterBubbleSort(a, unsorted_len - 1)

BetterBubbleSort(numbers, len(numbers))

print(numbers)
