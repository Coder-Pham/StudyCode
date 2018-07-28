/**
 * @author Nhat M. Nguyen
 * @date   28-07-18
**/


#include <iostream>
#include <vector>


using namespace std;


const int MAXL = (int) 1e4;
const int MAXN = (int) 1e2;
int l;
int n;
int p[MAXN];
int r[MAXL];
int c[MAXL];
vector<int> pieces;


void construct() {
    int i = l;
    while (c[i] != i) {
        pieces.push_back(i - c[i]);
        i = c[i];
    }
    pieces.push_back(i);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> l;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // DP
    for (int i = 1; i <= l; i++) {
        if (i <= n) {
            r[i] = p[i];
            c[i] = i;
        }
        else {
            r[i] = 0;
        }

        for (int j = 1; i - j > 0 && j <= n; j++) {
            if (r[i] < p[j] + r[i - j]) {
                r[i] = p[j] + r[i - j];
                c[i] = i - j;
            }
        }
    }

    cout << "Max revenue: " << r[l] << '\n';

    // Construct the solution from dp result
    construct();
    cout << "Number of pieces: " << pieces.size() << '\n';
    cout << "Pieces: \n";
    
    for (int& piece : pieces) {
        cout << piece << ' ';
    }
    cout << '\n';

    return 0;
}
