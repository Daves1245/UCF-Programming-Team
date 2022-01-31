/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long n;
    cin >> n;
    while (n != 1) cout << n << " ", n = (n % 2) ? 3 * n + 1 : n / 2;
    cout << n << endl;
    return 0;
}

