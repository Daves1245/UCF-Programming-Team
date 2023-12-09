#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        cout << !((b & 1) ^ (c & 1)) << " " << !((a & 1) ^ (c & 1)) << " " << !((a & 1) ^ (b & 1)) << endl;
    }

    return 0;
}
