import os
import time

# start_time = time.time()

__location__ = os.path.realpath(
	os.path.join(os.getcwd(), os.path.dirname(__file__))
)

tfile = open(os.path.join(__location__, 'sudoku.txt'), 'r')
puzzle = []

i = 0
for line in tfile:
	row_inp = line.rstrip()
	puzzle.append(row_inp.split(" "))

#debug
for i in range(9):
	print(puzzle[i])

# run_time = time.time() - start_time
# print("Run time: " + str(run_time))