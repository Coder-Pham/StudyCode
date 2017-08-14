#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    freopen("ASCIICode.txt", "w", stdout);
    for (int i = 0; i < 255; i++) {
        cout << i << " : " << (char) i << "\n";
    }
}