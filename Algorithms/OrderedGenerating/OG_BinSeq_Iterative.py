bs_len = 4

# first sequence
bs = [0 for i in range(bs_len)]

def writeseq(a):
	seq_str = ""
	for i in range(len(a)):
		seq_str += str(a[i])
	print(seq_str)

def filltoend(a, start, num):
	for i in range(start, len(a)):
		a[i] = num

finished = False
while (finished == False):
	writeseq(bs)
	finished = True
	for i in range(bs_len-1, -1, -1):
		if (bs[i] == 0):
			bs[i] = 1
			filltoend(bs, i+1, 0)
			finished = False
			break