/**
 * @author Nhat M. Nguyen
 * @date   20-04-18
**/


#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;


int main() {
    int n;
    cout << "Length of rod: ";
    cin >> n;

    vector<int> price(n + 1);
    vector<int> revenue(n + 1);

    fill(price.begin(), price.end(), 0);
    fill(revenue.begin(), revenue.end(), 0);

    cout << "Price according to length:\n";
    for (int i = 1; i <= n; i++) {
        cout << "price[" << i << "] = ";
        cin >> price[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            revenue[i] = max(revenue[i], price[j] + revenue[i - j]);
        }
    }

    int max_revenue = 0;
    for (int i = 1; i <= n; i++) {
        max_revenue = max(max_revenue, revenue[i]);
    }

    cout << "Max revenue: " << max_revenue << "\n";
    return 0;
}


/**
 * Testcase
 *
 * + In:
 * Length of rod: 8
 * price[1] = 1
 * price[2] = 5
 * price[3] = 8
 * price[4] = 9
 * price[5] = 10
 * price[6] = 17
 * price[7] = 17
 * price[8] = 20
 *
 * + Out
 * Max revenue: 22
**/
