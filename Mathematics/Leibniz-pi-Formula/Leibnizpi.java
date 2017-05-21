/*
Calculating PI using Leibniz's formula
pi/4 = 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
*/

import java.util.Scanner;

class Leibnizpi {
	public static void main(String args[]) {
		System.out.println("Calculating PI using Leibniz's formula");
		System.out.print("n = ");
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		double denom = 1;
		double pion4 = 1;
		double pi;

		while (denom < n) {
			if (denom > 0) {
				denom += 2;
			}
			else {
				denom -= 2;
			}

			denom = -denom;
			System.out.print("denom = ");
			System.out.println(denom);

			pion4 += 1/denom;

		   	pi = pion4 * 4;

		   	System.out.print("PI = ");
		   	System.out.println(pi);
		}
	}
}