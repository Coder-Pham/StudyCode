#include <bits/stdc++.h>


using namespace std;


/**
 * dp[i][j]: maximum length of the palindrome subsequence from i to j
 *
 * Cases:
 *   i == j     : dp[i][j] == 1
 *   i == j - 1 :          == 2 if s[i] == s[j]
 *                         == 1 if s[i] != s[j]
 *   else       :          == (dp[i + 1][j - 1] + 2)          if s[i] == s[j]
 *                         == max(dp[i + 1][j], dp[i][j - 1]) otherwise
**/


const int N = (int) 1e3;
string s;


void solve() {
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            dp[i - 1][i] = 2;           
        }
        else {
            dp[i - 1][i] = 1;
        }
    }
    
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = length + i - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    
    cout << dp[0][n - 1] << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    solve();
    return 0;
}
