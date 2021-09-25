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

#define btoa(x) ((x) ? "YES" : "NO")

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int extended_gcd(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

bool sumdiv(int n) {
    int ret = 0;
    while (n > 0) {
        ret += n % 10;
        n /= 10;
    }
    return ret % 3 == 0;
}

bool no(int n) {
    return (n % 10 == 3) || sumdiv(n);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int count = 0;
        int i;
        for (i = 1; count < n; i++) {
            if (no(i)) continue;
            count++;
        }
        cout << i - 1 << endl;
    }
    return 0;
}

