from BruteForcePeakFind import *
from BinaryPeakFind import *
from tgen import *
import os

__location__ = os.path.realpath(
	os.path.join(os.getcwd(), os.path.dirname(__file__))
)

filename = 'testcase.txt'

# Generate test case with random peak
mynumfile = open(os.path.join(__location__, filename), 'w')
generate_testcase(mynumfile)
mynumfile.close()

# Get input
mynumfile = open(os.path.join(__location__, filename), 'r')
mynumlist = []

for line in mynumfile:
	mynumlist.append(int(line))

mynumfile.close()

# Find Peak
mypeak = BruteForcePeakFind(mynumlist)

print(mypeak)