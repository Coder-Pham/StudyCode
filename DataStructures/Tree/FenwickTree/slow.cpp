#include <bits/stdc++.h>


using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n];
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    int q;
    cin >> q;

    for (int j = 0; j < q; j++) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, inc;
            cin >> pos >> inc;
            for (int i = pos; i < n; i++) {
                a[i] += inc;
            }
        }
        else {
            int pos;
            cin >> pos;
            cout << a[pos] << '\n';
        }
    }

    return 0;
}
