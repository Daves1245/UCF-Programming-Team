/*
 * bounds
 * clear data structures
 * epsilon
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string in; cin >> in;
    int a = 0, b = 0;
    bool overtime = false;
    for (int i = 0; i < in.size() - 1; i += 2) {
        int s = in[i + 1] - '0';
        if (overtime) {
            if (in[i] == 'A') {
                a += s;
                if (a >= b + 2) {
                    cout << 'A' << endl;
                    return 0;
                }
            } else if (in[i] == 'B') {
                b += s;
                if (b >= a + 2) {
                    cout << 'B' << endl;
                    return 0;
                }
            }
        } else {
            if (in[i] == 'A') {
                a += s;
                if (a >= 11) {
                    cout << 'A' << endl;
                    return 0;
                }
            } else {
                b += s;
                if (b >= 11) {
                    cout << 'B' << endl;
                    return 0;
                }
            }

            if (a == 10 && b == 10) {
                overtime = true;
            }
        }
    }

    return 0;
}
