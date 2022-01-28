/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int start = 0;
    int dir = 1;
    for (int i = 1; i < 100; i++) {
        if (start % 2 == 1) {
            dir = -1;
        } else {
            dir = 1;
        }
        start += i * dir;
        cout << i << ": " << (start) << endl;
    }
    return 0;
}

