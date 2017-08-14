#include <stdio.h>
#include <vector>

using namespace std;

int n, k;

void printSeq(vector<int> seq) {
    for (int i = 1; i <= k; i++) {
        printf("%d ", seq[i]);
    }
    printf("\n");
}

int upperBound(int i) {
    return (n - k + i);
}

void ogSubSet(vector<int> &seq) {
    // print out current sequence
    printSeq(seq);

    // generate the next sequence (if any)
    bool done = true;
    
    // find the first element from the right
    // that has not reached its upper-bound
    for (int i = k; i > 0; i--) {
        if (seq[i] != upperBound(i)) {
            // increase the found element by one
            seq[i]++;

            // set all elements behind it to their lower-bounds
            for (int j = i + 1; j <= k; j++) {
                seq[j] = seq[i] + (j - i);
            }

            done = false;
            break;
        }
    }
    
    if (!done) {
        ogSubSet(seq);
    }
}

int main() {
    scanf("%d %d", &n, &k);
    
    // first sequence
    vector<int> seq(k + 1);
    for (int i = 1; i <= k; i++) {
        seq[i] = i;
    }
    ogSubSet(seq);
    return 0;
}
