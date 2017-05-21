def BruteForcePeakFind(numlist):
	prev_pos = 0
	peak = len(numlist) - 1
	for pos in range(len(numlist) - 1):
		if (numlist[pos] > numlist[pos+1]):
			peak = pos
			break
	return peak