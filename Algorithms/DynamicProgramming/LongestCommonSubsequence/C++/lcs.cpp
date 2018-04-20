/**
 * @author Nhat M. Nguyen
 * @date   20-04-18
**/


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>


using namespace std;


const int N = 1000;
char x[N];
char y[N];


int main() {
    /* Input */
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }

    /* Initialize tables */
    vector<vector<int> > length_table;
    vector<vector<pair<int, int> > > construct_table;
                             
    for (int i = 0; i <= m; i++) {
        vector<int> row;
        for (int j = 0; j <= n; j++) {
            row.emplace_back(0);
        }
        length_table.emplace_back(row);
    }

    for (int i = 0; i <= m; i++) {
        vector<pair<int, int> > row;
        for (int j = 0; j <= n; j++) {
            row.emplace_back(make_pair(0, 0));
        }
        construct_table.emplace_back(row);
    }

    /* Generate length table */
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i] == y[j]) {
                length_table[i][j] = length_table[i - 1][j - 1] + 1;
                construct_table[i][j].first = -1;
                construct_table[i][j].second = -1;
            }
            else {
                if (length_table[i - 1][j] >= length_table[i][j - 1]) {
                    length_table[i][j] = length_table[i - 1][j];
                    construct_table[i][j].first = -1;
                }
                else {
                    length_table[i][j] = length_table[i][j - 1];
                    construct_table[i][j].second = -1;
                }
            }
        }
    }

    /* Construct the LCS */
    string lcs = "";
    int i = m;
    int j = n;
    
    while (i != 0 && j != 0) {
        if (construct_table[i][j].first == -1
               && construct_table[i][j].second == -1) {
            lcs = x[i] + lcs;
        }
        int new_i = i + construct_table[i][j].first;
        int new_j = j + construct_table[i][j].second;
        i = new_i;
        j = new_j;
    }

    /* Output */
    cout << "Length of subsequence: " << length_table[m][n] << endl;
    cout << "Subsquence: " << lcs << endl;

    return 0;
}


/**
 * TEST
 *
 * + Input
 * 7
 * 6
 * ABCBDAB
 * BDCABA
 *
 * + Output
 * Length of subsequence: 4
 * Subsequence: BCBA
**/
