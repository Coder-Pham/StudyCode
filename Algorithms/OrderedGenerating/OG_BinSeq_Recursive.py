bs_len = 4
""" the length must be <= 9
otherwise will exceed max recursion depth
"""

# first sequence
bs = [0 for i in range(bs_len)]

def writeseq(a):
	seq_str = ""
	for i in range(len(a)):
		seq_str += str(a[i])
	print(seq_str)

def bsgen(seq):
	writeseq(seq)
	
	finished = True
	for i in range(bs_len-1, -1, -1):
		if (bs[i] == 0):
			bs[i] = 1
			finished = False
			break
		
	if (i != bs_len-1):
		for j in range(i+1, bs_len):
			bs[j] = 0

	if (finished):
		return
	else:
		bsgen(seq)

bsgen(bs)