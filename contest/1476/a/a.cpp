/*
 * Author: medbar
 * Date: 2021-06-30
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <queue>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (;t--;) {
        ull n, k;
        cin >> n >> k;
        if (k == 1 || n == k) {
            cout << 1 << endl;
            continue;
        }
        ll ans = (n / k) + ((n % k == 0) ? 0 : 1);
        ll sum = ans * k;
        ans = sum / n;
        ans += (sum % n == 0) ? 0 : 1;
        cout << ans << endl;
    }
    return 0;
}

