/**
 * @author Nhat M. Nguyen
 * @date   28-07-18
**/


/**
 * O(nlogn) solution for the Longest Increasing Subsequence problem
 * In this particular version, not only the length of LIS is computed but
 * the subsequence is also constructed.
**/


#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <utility>


using namespace std;


const int MAXN = (int) 1e6;
int n;
int a[MAXN];
int pre[MAXN];


bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first < p2.first;
}


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
    //
    // In this version, the aux vector is a vector of pairs where
    // first is the value of the element, and second is its index
    vector<pair<int, int> > aux;

    // To construct the LIS, use an array pre[] to keep track of the index
    // of the precedent element in the subsequence

    aux.push_back(make_pair(a[0], 0));
    pre[0] = 0;
    int lastIndex = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] < aux[0].first) {
            pre[i] = i;
            aux[0] = make_pair(a[i], i);
        }
        else if (a[i] > aux[aux.size() - 1].first) {
            pre[i] = aux[aux.size() - 1].second;
            aux.push_back(make_pair(a[i], i));
            lastIndex = i;
        }
        else {
            int j = lower_bound(aux.begin(), aux.end(), make_pair(a[i], 0), cmp) - aux.begin();
            pre[i] = aux[j - 1].second;
            aux[j] = make_pair(a[i], i);
        }
    }

    cout << "Length of the LIS: ";
    cout << aux.size() << '\n';

    stack<int> st;

    int k = lastIndex;
    while (true) {
        st.push(a[k]);
        if (k == pre[k]) break;
        k = pre[k];
    }

    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << '\n';

    return 0;
}
