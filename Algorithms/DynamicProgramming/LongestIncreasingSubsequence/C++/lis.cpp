/**
 * @author Nhat M. Nguyen
 * @date   22-04-18
**/


/**
 *  Idea: LIS(i) must contains MAX(LIS(j)) where
 *      0 < j < i and a[j] < a[i]
 *  Time complexity: O(n^2)
**/

#include <iostream>


using namespace std;


const int N = (int) 1e4;
int n;
int a[N];
int dp[N];


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    fill(dp, dp + n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] >= a[i]) continue;
            dp[i] = max(dp[j], dp[i]);
        }
        dp[i]++;
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}
