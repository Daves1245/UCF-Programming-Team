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
typedef vector<pair<ll, ll>> vll;

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void p(vii v) {
    printf("vii size: %ld ", v.size());
    cout << "vii: ";
    for (int i = 0; i < v.size(); i++) {
        printf("(%d, %d), ", v[i].first, v[i].second);
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vll v(n);
        for (int i = 0; i < n; i++) {
            ll tmp;
            cin >> tmp;
            v[i] = pair<int, int>(tmp, (ll) i + 1);
        }
        sort(v.begin(), v.end());
//        p(v);
        int c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
//                printf("(i, j) = (%d, %d), ai * aj == %d, vs i + j == %d\n", v[i].second, v[j].second, v[i].first * v[j].first, v[i].second + v[j].second);
                if (v[i].first * v[j].first == v[i].second + v[j].second) {
                    c++;
                }
                if (v[i].first * v[j].first > 2 * n) {
//                    cout << " exiting! " << endl;
                    break;
                }
            }
        }
        cout << c << endl;
    }
    return 0;
}

