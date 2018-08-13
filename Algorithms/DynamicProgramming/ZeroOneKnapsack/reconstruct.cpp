/**
 *  @author Nhat M. Nguyen
 *  @update 13-08-18
**/


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
 *  This version also reconstruct the list of chosen items
**/


const int N = (int) 1e2;
const int W = (int) 1e5;
int n;
int value[N];
int weight[N];
int weightCap;
int maxValue[N][W];
pair<int, int> rebuild[N][W];
stack<int> knapsack;


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


void dfs(pair<int, int> curPair) {
    int curItem = curPair.first;
    int curWeight = curPair.second;
    int nextItem = rebuild[curItem][curWeight].first;
    int nextWeight = rebuild[curItem][curWeight].second;

    if (nextWeight != curWeight) {
        knapsack.push(curItem);
    }

    if (nextItem == 0 || nextWeight == 0) return;

    dfs(rebuild[curItem][curWeight]);
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
                rebuild[item][cap] = make_pair(item - 1, cap);
            }
            else {
                int notTakeOutcome = maxValue[item - 1][cap];
                int takeOutcome = maxValue[item - 1][cap - weight[item]] + value[item];
                if (takeOutcome > notTakeOutcome) {
                    maxValue[item][cap] = takeOutcome;
                    rebuild[item][cap] = make_pair(item - 1, cap - weight[item]);
                }
                else {
                    maxValue[item][cap] = notTakeOutcome;
                    rebuild[item][cap] = make_pair(item - 1, cap);
                }
            }
        }
    }

    cout << "Max value: " << maxValue[n][weightCap] << '\n';

    dfs(make_pair(n, weightCap));

    cout << "List of items: ";
    while (!knapsack.empty()) {
        cout << value[knapsack.top()] << ' ';
        knapsack.pop();
    }
    cout << '\n';

    return 0;
}
