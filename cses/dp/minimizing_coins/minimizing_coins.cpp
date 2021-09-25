/*
 * Author: medbar
 * Date: 2021-09-16
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

#define btoa(x) ((x) ? "YES" : "NO")

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

int memo[1000000 + 10] = {0};

int min_change(vector<int> &coins, int n, int s) {
    if (s < 0) {
        return 1000000000;
    }
    if (s == 0) {
        return 0;
    }
    if (memo[s] != 0) {
        return memo[s];
    }
    int ret = INT_MAX;
    for (int i = 0; i < coins.size(); i++) {
        ret = min(ret, 1 + min_change(coins, n, s - coins[i]));
    }
    return memo[s] = ret;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < coins.size(); i++) {
        cin >> coins[i];
    }
    int m = min_change(coins, n, x);
    if (m >= 1000000000) {
        cout << -1 << endl;
    } else {
        cout << m << endl;
    }
    return 0;
}

