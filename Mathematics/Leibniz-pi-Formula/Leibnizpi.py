n = input("denominator = ")

denom = float(1)
pion4 = float(1)

while (denom < n):
	if (denom > 0):
		denom += 2
	else:
		denom -= 2
	
	denom = -denom
	print "denom = %d" %(denom)
		
	pion4 += 1/denom
	
	pi = pion4 * 4

	print(pi)