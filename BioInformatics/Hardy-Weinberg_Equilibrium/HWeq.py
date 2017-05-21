"""
This program is an implementation of Hardy-Weinberg principle
"""

# *** GET INPUT ***
# Acquire the frequency of each genotype of the P-generation: AA, Aa and aa
AA = float(input("AA = "))
Aa = float(input("Aa = "))
aa = float(input("aa = "))

# Acquire the number of filial generations
num_of_fgs = int(input("Number of filial generations: "))

# *** PROCESS ***
# Map the genotype frequencies to  the range of 1
init_range = AA + Aa + aa
AA /= init_range
Aa /= init_range
aa /= init_range

# Work out the frequency of each allene
A = AA + Aa/2
a = aa + Aa/2

# Put genotype frequency through the generation in a list
# where the 0-indexed element is the genotype frequency of of the P-generation
# Initialize the genotype frequencies of the filial generations as 0.0
fAA = [0.0 for i in range(num_of_fgs + 1)]
fAa = [0.0 for i in range(num_of_fgs + 1)]
faa = [0.0 for i in range(num_of_fgs + 1)]

# Add the genotype frequencies of P-generation to the lists
fAA[0] = AA
fAa[0] = Aa
faa[0] = aa

# Recursively analyze each generation
def HWeq(fg_no):
	# Print out the genotype frequencies of F(fg_no) generation
	if(fg_no != 0):
		print("F(" + str(fg_no) + "):  ", end="")
		print("AA = " + str(round(fAA[fg_no], 4)) + " ;  ",  end="")
		print("Aa = " + str(round(fAa[fg_no], 4)) + " ;  ",  end="")
		print("aa = " + str(round(faa[fg_no], 4)) + " ;    ",  end="")

	p = fAA[fg_no] + fAa[fg_no]/2
	q = faa[fg_no] + fAa[fg_no]/2
	pp = p**2
	qq = q**2
	
	# Check if H-W equilibrium is achieved
	# The round function is used to avoid floating point error
	if (round(fAA[fg_no]*faa[fg_no], 10) == round(fAa[fg_no]**2/4, 10)):
		if (fg_no == 0):
			print("H-W equilibrium has been achieved at the P-generation!")
		else:
			print("H-W equilibrium achieved!")
	else:
		print()

	# Check if the program have reached the final filial generation
	if (fg_no == num_of_fgs):
		return
	else:
		fAA[fg_no + 1] = pp
		fAa[fg_no + 1] = 2*p*q
		faa[fg_no + 1] = qq
		# Recursively analyze each generation
		HWeq(fg_no + 1)

HWeq(0)
for i in range(5):
	print()