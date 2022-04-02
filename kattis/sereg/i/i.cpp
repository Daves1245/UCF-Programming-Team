/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    char *a[] = {"Either", "Odd", "Either", "Even"};
    int n; cin >> n;
    cout << a[(n - 1) % 4] << endl;
    return 0;
}

