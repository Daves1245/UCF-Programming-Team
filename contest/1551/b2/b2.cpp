/*
 * Author: medbar
 * Date: 2021-07-23
 */

#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <queue>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>
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
    while (t--) {
        int n, k;
        cin >> n >> k;
        unordered_map<int, ii> count;
        vi v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            count[v[i]].first++;
            count[v[i]].second++;
            if (count[v[i]].second > k) {
                count[v[i]].second = k;
            }
        }
        vi extra;
        for (int i = 0; i < n; i++) {
            if (count[v[i]].first < k) {
                extra.push_back(v[i]);
            }
        }
        int color = k;
        for (int i = 0; i < extra.size() - 3; i += 3) {
            for (int j = 0; j < 3; j++) {
                count[extra[i + j]].second = color;
                color--;
                if (color == 0) {
                    color = k;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (count[v[i]].second == 0) {
                cout << 0 << " ";
            } else {
                cout << count[v[i]].second-- << " ";
            }
            count[v[i]].first--;
        }
        cout << endl;
    }
    return 0;
}

