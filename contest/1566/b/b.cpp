/*
 * Author: medbar
 * Date: 2021-09-12
 */

#include <climits>
#include <set>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>
#include <queue>
#include <bits/stdc++.h>

#define btoa(x) ((x) ? "YES" : "NO")

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

int main() {
    int t;
    cin >> t;
    string s;
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        int i = 0;
        if (s[i] == '0') {
            while (s[i] == '0') i++;
            if (s[i] != '1') {
                cout << 1 << endl;
                continue;
            }
            while (s[i] == '1') i++;
            if (i == s.size()) {
                cout << 1 << endl;
                continue;
            }
            cout << 2 << endl;
            continue;
        } else {
            while (s[i] == '1') i++;
            if (s[i] != '0') {
                cout << 0 << endl;
                continue;
            }
            while (s[i] == '0') i++;
            if (i == s.size()) {
                cout << 1 << endl;
            }
            while (s[i] == '1') i++;
            if (i == s.size()) {
                cout << 1 << endl;
                continue;
            }
            cout << 2 << endl;
        }
    }

    return 0;
}

