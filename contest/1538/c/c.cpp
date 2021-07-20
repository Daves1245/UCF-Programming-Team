/*
 * Author: Zedbar
 * Date: 2021-06-27
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
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, l, r;
        cin >> n >> l >> r;
        vi v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        /*
        cout << "V: ";
        p(v);
        */
        ll c = 0;
        for (int i = 0; i < n; i++) {
            auto sup = upper_bound(v.begin(), v.end(), r - v[i]) - 1;
            auto inf = lower_bound(v.begin(), v.end(), l - v[i]);
            c += sup - inf + 1;
            if (2 * v[i] >= l && 2 * v[i] <= r) {
                c--;
            }
            /*
            cout << "(r - v[i], sup r - v[i]): (" << r - v[i] << " " << upper_bound(v.begin(), v.end(), r - v[i]) - v.begin() - 1 << ") " << endl;
            cout << "(l - v[i]), inf l - v[i]): (" <<  l - v[i] << " " << lower_bound(v.begin(), v.end(), l - v[i]) - v.begin() << endl;
            cout << "c += " << (upper_bound(v.begin(), v.end(), r - v[i]) - 1 - lower_bound(v.begin(), v.end(), l - v[i]) + 1) << endl;
            */
        }
        cout << c / 2 << endl;
    }
    return 0;
}

