#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define M 1000
#define B 10000

ll score(ll x, ll y) {
    ll alpha = (x + 1) * (y + 1);
    return (alpha * (x + y)) / 2;
}

int main() {
    ll m, b; cin >> m >> b;
    ll ret = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << score(i, j) << "\t";
        }
        cout << endl;
    }
    cout << ret << endl;
    return 0;
}

