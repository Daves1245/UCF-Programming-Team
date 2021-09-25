/*
 * Author: medbar
 * Date: 2021-09-02
 */

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

#define UNVISITED 0
#define VISITED 1

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

int constexpr N = 100000;

vi dfs_num(N + 10);
vector<vii> adjlist(2 * N + 10);

void dfs(int u) {
    dfs_num[u] = VISITED;
    for (int i = 0; i < (int) adjlist[u].size(); i++) {
        ii v = adjlist[u][i];
        //printf("v is %d %d\n", v.first, v.second);
        if (dfs_num[v.first] == UNVISITED) {
            dfs(v.first);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    dfs_num.assign(n + 1, UNVISITED);
    adjlist.resize(n);
    vii new_roads;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjlist[a].push_back(ii(b, UNVISITED));
        adjlist[b].push_back(ii(a, UNVISITED));
    }

    int cc = 0;
    ii entry;
    int prev_road = -1;
    for (int i = 0; i <= n; i++) {
        if (dfs_num[i] == UNVISITED) {
            cc++;
            dfs(i);
            if (prev_road > 0) {
                new_roads.push_back(ii(prev_road, i));
            }
            prev_road = i;
        }
    }
//    printf("cc is %d\n", cc);
    printf("%ld\n", new_roads.size());
    for (int i = 0; i < new_roads.size(); i++) {
        printf("%d %d\n", new_roads[i].first, new_roads[i].second);
    }
    return 0;
}

