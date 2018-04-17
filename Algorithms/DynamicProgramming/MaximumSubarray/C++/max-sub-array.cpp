/**
 * @author Nhat M. Nguyen
 * @date   17-04-18
 *
 *
 * Maximum subarray problem with Kadane algorithm
 * Time complexity: O(n)
**/


#include <iostream>


using namespace std;


int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_sum = a[0];
    int max_prefix_sum = a[0];
    int left = 0, right = n - 1;
    int prefix_left = 0;
    for (int i = 1; i < n; i++) {
        if (max_prefix_sum + a[i] > a[i]) {
            max_prefix_sum += a[i];
        }
        else {
            max_prefix_sum = a[i];
            prefix_left = i;
        }

        if (max_prefix_sum > max_sum) {
            max_sum = max_prefix_sum;
            left = prefix_left;
            right = i;
        }
    }

    cout << "Max subarray:\n";
    for (int i = left; i <= right; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    cout << "Sum = " << max_sum << "\n";
    cout << "Left = " << left << "\n";
    cout << "Right = " << right << "\n";
    return 0;
}


/*
Testcase

+ Input
    -2, -3, 4, -1, -2, 1, 5, -3

+ Output
    Max Subarray:
    4, -1, -2, 1, 5
    Sum = 7
    Left = 2
    Right = 6
*/
