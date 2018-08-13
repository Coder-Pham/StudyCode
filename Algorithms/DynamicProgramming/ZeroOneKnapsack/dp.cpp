#include <bits/stdc++.h>


using namespace std;


/**
 *  0-1 knapsack problem
 *  Input:
 *    * n: number of items
 *    * array v: value of every item
 *    * array w: weight of every item
 *    * weightCap: weight capacity of the knapsack
 * 
 *  Time complexity: O(n * weightCap)
**/


const int N = (int) 1e2;
const int W = (int) 1e5;
int n;
int value[N];
int weight[N];
int weightCap;
int maxValue[N][W];


void input() {
    cin >> n;
    cin >> weightCap;
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }
}


int main() {
    input();

    for (int cap = 0; cap <= weightCap; cap++) {
        maxValue[0][cap] = 0;
    }
    for (int item = 1; item <= n; item++) {
        for (int cap = 1; cap <= weightCap; cap++) {
            if (weight[item] > cap) {
                maxValue[item][cap] = maxValue[item - 1][cap];
            }
            else {
                maxValue[item][cap] = max(maxValue[item - 1][cap],
                                          maxValue[item - 1][cap - weight[item]] + value[item]);
            }
        }
    }

    cout << maxValue[n][weightCap] << '\n';

    return 0;
}
