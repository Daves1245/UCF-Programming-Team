/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string alphabet, s;
        cin >> alphabet >> s;
        int dist = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            dist += abs(find(alphabet.begin(), alphabet.end(), s[i]) -
                    find(alphabet.begin(), alphabet.end(), s[i + 1]));
        }
        cout << dist << endl;
    }
    return 0;
}

