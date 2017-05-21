def BinaryPeakFind(numlist):
	start = 0
	end = len(numlist) - 1
	peak = -1
	while True:
		pos = (start + end + 1) // 2
		if (pos == 0) or (pos == len(numlist)-1):
			peak = pos
			break
		else:
			if (numlist[pos] > numlist[pos-1]):
				if (numlist[pos] > numlist[pos+1]):
					peak = pos
					break
				else:
					start = pos + 1
			else:
				end = pos - 1
	return peak