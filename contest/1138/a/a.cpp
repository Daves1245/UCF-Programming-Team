/*
 * Author: Zedbar
 * Date: 2021-06-29
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

#define dbg printf

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
    int n;
    cin >> n;

    vi v;
    int cur, prev, count = 1;

    cin >> prev;
    for (int i = 0; i < n - 1; i++) {
        cin >> cur;
        if (cur != prev) {
            v.push_back(count);
            count = 1;
        } else {
            count++;
        }
        prev = cur;
    }
    v.push_back(count);

    int mi = 0, ma = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        mi = min(v[i], v[i + 1]);
        ma = max(ma, mi);
    }
    cout << 2 * ma << endl;
    return 0;
}

