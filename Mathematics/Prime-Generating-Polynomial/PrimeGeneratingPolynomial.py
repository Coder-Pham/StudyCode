# Euler's Prime Generating Polynomial
import os

__location__ = os.path.realpath(
	os.path.join(os.getcwd(), os.path.dirname(__file__))
)

filename = "PrimeGeneratingPolynomial.txt"
f = open(os.path.join(__location__, filename), 'r')

a = []

def PGP(x):
	return x*x + x + 41

for i in range(40):
	a.append(PGP(i))

for i in range(1, 40):
	diff = a[i] - a[i-1]
	f.write("PGP(" + str(i) + ") = " + str(a[i]) + "\n")

f.close()