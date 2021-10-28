/*
 * Author: medbar
 * Date: 2021-09-28
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

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void shift_left(vi& v, int l, int r, int d) {
    int offset[r - l + 1];
    for (int i = 0; i < r - l + 1; i++) {
        offset[i] = l + (i + d) % (r - l + 1);
    }
    for (int i = 0; i < r - l + 1; i++) {
        printf("%d ", offset[i]);
    }
    printf("\n");
}

int main() {
    /*
    int t;
    cin >> t;
    */

    vi a(10);
    for (int i = 0; i < a.size(); i++) {
        a[i] = i;
    }
    shift_left(a, 1, 5, 3);
    /*
    while (t--) {
        int n;
        cin >> n;
        vi a(n), b;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        b = a;
        sort(b.begin(), b.end());
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != b[i]) {
                int j = find(a.begin(), a.end(), b[i]);
            }
        }
    }
    */
    return 0;
}

