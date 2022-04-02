/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    while (a > b) {
        if (a % 2) {
            a++;
            cnt++;
        }
        a /= 2;
        cnt++;
    }
    
    cout << cnt + b - a;
    return 0;
}

