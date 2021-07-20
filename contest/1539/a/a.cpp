/*
 * Author: Zedbar
 * Date: 2021-06-25
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ull max(ull a, ull b) {
    return a > b ? a : b;
}

ull min(ull a, ull b) {
    return a < b ? a : b;
}

ull solve(ull n, ull x, ull t) {
    ull lim = min(n, t / x);
    return n * lim - lim * (lim + 1) / 2;
}

int main() {
    int T;
    cin >> T;
    for (int t0 = 0; t0 < T; t0++) {
        ull n, x, t;
        cin >> n >> x >> t;
        cout << solve(n, x, t) << endl;
    }
    return 0;
}
