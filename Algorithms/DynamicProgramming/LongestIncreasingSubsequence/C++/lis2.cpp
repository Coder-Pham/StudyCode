/**
 * @author Nhat M. Nguyen
 * @date   28-07-18
**/


/**
 * O(nlogn) solution for the Longest Increasing Subsequence problem
**/


#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;


const int MAXN = (int) 1e6;
int n;
int a[MAXN];


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Auxiliary vector to keep the ending values of candidate subsequences
    // This vector is always sorted
    // The size of this vector is the length of the LIS,
    //   since the element aux[j] is the ending element of the candidate
    //   subsequence with length (j + 1)
    // There can never be two candidate subsequences with the same length
    vector<int> aux;

    aux.push_back(a[0]);

    for (int i = 1; i < n; i++) {
        if (a[i] < aux[0]) {
            aux[0] = a[i];
        }
        else if (a[i] > aux[aux.size() - 1]) {
            aux.push_back(a[i]);
        }
        else {
            int j = upper_bound(aux.begin(), aux.end(), a[i]) - aux.begin();
            aux[j] = a[i];
        }
    }

    cout << aux.size() << '\n';

    return 0;
}
