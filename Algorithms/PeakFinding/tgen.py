import os
import random

def generate_testcase(numfile):
	max = 1000000
	peakpos = random.randint(0, max);
	nums = []

	j = 0
	for i in range(0, peakpos):
		numfile.write(str(i) + "\n")
		j = i + 1 #next position

	for i in range(peakpos, max+1):
		numfile.write(str(j) + "\n")
		j -= 1