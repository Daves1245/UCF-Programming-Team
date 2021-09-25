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

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

const int N = 10e5;
const int M = 1000000007;

int memo[N];

int ways(int n) {
    if (n < 1) return 0;
    if (n == 1) return 1;
    if (memo[n] != 0) return memo[n];
    int ret = n <= 6;
    for (int i = 1; i <= 6; i++) {
        ret = (ret + ways(n - i)) % M;
    }
    return memo[n] = ret % M;
}

int main() {
    int n;
    cin >> n;
    cout << ways(n) << endl;
    return 0;
}

