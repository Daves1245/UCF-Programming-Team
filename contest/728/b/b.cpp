/*
 * Author: Zedbar
 * Date: 2021-06-28
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
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vii v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first;
        }
        sort(v.begin(), v.end());
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (v[i].first * v[j].first == v[i].second + v[j].second) {
                    c++;
                }
                if (v[i].first * v[j].first > 2 * n) {
                    break;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}

