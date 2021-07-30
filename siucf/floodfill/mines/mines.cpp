/*
 * Author: medbar
 * Date: 2021-07-29
 */

#include <cstring>
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

struct custom_hash {
    // http://xorshift.di.unimi.it/splitmix64.c
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef unordered_map<long long, int, custom_hash> safe_map;

int fast_gcd(int a, int b) {
    if (!a || !b) {
        return a | b;
    }
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) {
            swap(a, b);
        }
        b -= a;
    } while (b);
    return a << shift;
}

int lcm(int a, int b) {
    return a / fast_gcd(a, b) * b;
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

bool space[30][30][30];
bool visited[30][30][30];

ll floodfill(int x, int y, int z, int n) {
    if (x < 0 || y < 0 || z < 0 || x >= n || y >= n 
            || z >= n) {
        return 0;
    }
    if (visited[x][y][z]) {
        return 0;
    }
    if (!space[x][y][z]) {
        return 0;
    }
    visited[x][y][z] = true;
    return 1 + floodfill(x + 1, y, z, n)
        + floodfill(x - 1, y, z, n)
        + floodfill(x, y + 1, z, n)
        + floodfill(x, y - 1, z, n)
        + floodfill(x, y, z + 1, n)
        + floodfill(x, y, z - 1, n);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                int tmp;
                cin >> tmp;
                space[i][j][k] = tmp;
            }
        }
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        printf("Simulation #%d, volume cleared is %lld cubic feet.\n\n", i, floodfill(x, y, z, n));
        memset(visited, false, sizeof visited);
    }
    return 0;
}

