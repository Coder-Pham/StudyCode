#include <bits/stdc++.h>


using namespace std;


const int N = (int) 1e6;
int n;
int a[N];


void queryType1() {
    int pos, inc;
    cin >> pos >> inc;
    for (int i = pos; i < n; i++) {
        a[i] += inc;
    }
}


void queryType2() {
    int l, r;
    cin >> l >> r;
    if (l == 0) {
        cout << a[r] << '\n';
    }
    else {
        cout << (a[r] - a[l - 1]) << '\n';
    }
}


int main() {
    cin >> n;
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
        if (type == 1) queryType1();
        else queryType2();
    }

    return 0;
}
