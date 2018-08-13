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
 *
 *  Brute-force version - Time complexity: O(2^n)
**/


const int N = (int) 1e2;
const int W = (int) 1e5;
int n;
int value[N];
int weight[N];
int weightCap;


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


int backtrack(int prevWeight, int prevVal, int item, bool taken) {
    int curWeight = (taken) ? (prevWeight + weight[item]) : (prevWeight);
    int curVal = (taken) ? (prevVal + value[item]) : (prevVal);

    if (curWeight > weightCap) return prevVal;
    if (curWeight == weightCap || item == n) return curVal;

    return max(backtrack(curWeight, curVal, item + 1, true),
               backtrack(curWeight, curVal, item + 1, false));
}


int main() {
    input();

    cout << backtrack(0, 0, 0, true) << '\n';

    return 0;
}
