/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 2018;
    for (int i = 0; i < 2018; i++) {
        for (int j = 0; j < 2018; j++) {
            if (i * i + j * j == 2018 * 2018) {
                cout << i << " " << j << endl;
            }
        }
    }
    return 0;
}

