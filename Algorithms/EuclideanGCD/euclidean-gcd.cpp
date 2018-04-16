/**
 * @author Nhat M. Nguyen
 * @date   07-04-2018
**/


#include <iostream>
#include <utility> // std::swap

using namespace std;

int calc_gcd(int a, int b) {
    if (a < b) {
        swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    while (a % b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return b;
}

int calc_lcm(int a, int b) {
    return a * b / calc_gcd(a, b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << "GCD: " << calc_gcd(a, b) << endl;
    cout << "LCM: " << calc_lcm(a, b) << endl;
    return 0;
}
