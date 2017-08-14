#include <iostream>
#include <stdio.h>

using namespace std;

void binPrint(int binNum[], int binLength) {
	for (int i = 0; i < binLength; i++) {
		printf("%d", binNum[i]);
	}
	printf("\n");
}

void binGenerate(int binNum[], int binLength) {
	binPrint(binNum, binLength);
	int firstZeroPos = -1;
	for (int i = binLength - 1; i > -1; i--) {
		if (binNum[i] == 0) {
			firstZeroPos = i;
            binNum[i] = 1;
			for (int j = i + 1; j < binLength; j++) {
				binNum[j] = 0;
			}
			break;
		}
	}
	if (firstZeroPos != -1) {
		binGenerate(binNum, binLength);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n];
    fill(a, a + n, 0);
    binGenerate(a, n);
	return 0;
}
