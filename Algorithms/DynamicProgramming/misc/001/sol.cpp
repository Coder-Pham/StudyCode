/**
 * @author Nhat M Nguyen
 * @update 05-10-18
**/


/*
 * Tested at: https://www.hackerrank.com/challenges/coin-change/problem
 */


#include <bits/stdc++.h>


using namespace std;


const int MAX_NUM_COINS = 50;
const int MAX_CHANGE = 250;
vector<int> coins;
int n_coins;
int change;
int64_t dp[MAX_NUM_COINS][MAX_CHANGE + 1];


/*
 * dp[n][s]: number of different ways to make the change where the largest coin
 * is the nth coin and the amount of change is s.
 */


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> change >> n_coins;
    coins.resize(n_coins);
    for (int i = 0; i < n_coins; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end());
    for (int i = 0; i < n_coins; i++) {
        dp[i][coins[i]] = 1;
    }
    for (int i = 0; i < n_coins; i++) {
        for (int c = coins[i] + 1; c <= change; c++) {
            for (int j = 0; j <= i; j++) {
                dp[i][c] += dp[j][c - coins[i]];
            }
        }
    }
    int64_t ans = 0;
    for (int i = 0; i < n_coins; i++) {
        ans += dp[i][change];
    }
    cout << ans << '\n';
    return 0;
}
