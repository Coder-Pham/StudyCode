/**
 *  Author Nhat M. Nguyen
 *  Date   11-01-18
 *  Description: This program checks whether pairs of numbers are in the same
 *  set by implementing disjoint sets.
 *
 *  ____________________________________________________________________________
 *  * Input:
 *    + 1st line: a number n
 *    + 2rd line: a number m
 *    + Next m lines: each contains 1 pair of number x, y (1 <= x, y <= n).
 *    Join the sets of each pair with the function unionSet().
 *    + Next line: a number q
 *    + Next q lines: each contains 1 pair of number. Check if each pair are
 *    from the same set.
 *  * Output:
 *    + q lines: if the ith pair are from the same set, print "YES",
 *    else print "NO"
 *  ____________________________________________________________________________
**/


#include <algorithm> // std::sort
#include <iostream>
#include <vector>


using namespace std;


const int INF = (int) 1e6;
int n, m, q;
int parent[INF];
int depth[INF];


/*
 * @param: u
 * @return: root of the disjoint set containing u
 */
int findRoot(int u) {
    int v = u;
    while (v != parent[v]) {
        v = parent[v];
    }
    return v;
}


/*
 * @param: 2 roots of 2 different disjoint sets
 * @expla: in order to limit the depth of the tree, join the shorter tree
   to the longer tree
 */
void unionSet(int a, int b) {
    if (depth[a] < depth[b]) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
        if (depth[a] == depth[b]) {
            depth[a]++;
        }
    }
}


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        depth[i] = 0;
    }
    cin >> m;
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        unionSet(rootX, rootY);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> x >> y;
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX == rootY) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}

/*
  TEST
+ IN:
10
6
1 3
2 4
9 5
3 7
5 8
2 10
6
1 3
10 2
6 1
3 8
1 10
7 3
+ OUT:
YES
YES
NO
NO
NO
YES
*/

