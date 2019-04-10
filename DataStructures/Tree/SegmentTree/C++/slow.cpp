#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> sum(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sum[0] = a[0];

    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + a[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) { // update
            int pos, new_val;
            cin >> pos >> new_val;
            a[pos] = new_val;
            sum[pos] = (pos == 0) ? (a[0]) : (sum[pos - 1] + a[pos]);

            for (int j = pos + 1; j < n; j++) {
                sum[j] = sum[j - 1] + a[j];
            }
        }
        else {
            int low, high;
            cin >> low >> high;
            if (low == 0) {
                cout << sum[high] << '\n';
            }
            else {
                cout << (sum[high] - sum[low - 1]) << '\n';
            }
        }
    }

    return 0;
}
