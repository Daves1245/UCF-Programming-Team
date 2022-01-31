/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    long long prev; cin >> prev;
    long long count = 0;
    while (--n) {
        int tmp; cin >> tmp;
        if (prev > tmp) {
            count += prev - tmp + 1;
        } else {
            prev = tmp;
        }
    }
    cout << count << endl;
    return 0;
}

