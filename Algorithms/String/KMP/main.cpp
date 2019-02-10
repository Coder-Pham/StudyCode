/**
 * @author Nhat M. Nguyen
 * @update 10-02-2019
**/

#include <bits/stdc++.h>

using namespace std;

struct KMP {
    string p; int len_p;
    string t; int len_t;
    vector<int> f;

    KMP(string& p, string& t) : p(p), t(t) {
        len_p = p.length();
        len_t = t.length();
        f.resize(len_p);
    }

    void BuildPrefixFunc() {
        f[0] = 0;
        int len = 0;

        for (int i = 1; i < len_p; i++) {
            len = f[i - 1];
            while (len > 0 && p[i] != p[len]) {
                len = f[len - 1];
            }
            if (p[i] == p[len]) {
                ++len;
            }
            f[i] = len;
        }
    }

    void Match() {
        BuildPrefixFunc();
        int len = 0;

        for (int i = 0; i < len_t; i++) {
            while (len > 0 && p[len] != t[i]) {
                len = f[len];
            }
            if (p[len] == t[i]) {
                ++len;
            }
            if (len == len_p) {
                cerr << "Match at " << (i - len + 1) << '\n';
                len = f[len];
            }
        }
    }
};

int main() {
    string p = "ACGT";
    string t = "ACGTAACTGTACGTGATTGCACGT"; // match positions: 0, 10, 20
    KMP kmp(p, t);
    kmp.Match();
    return 0;
}
