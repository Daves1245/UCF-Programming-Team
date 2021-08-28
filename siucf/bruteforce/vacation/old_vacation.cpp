/*
 * Author: medbar
 * Date: 2021-08-07
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

bool path_blocked(vii blocked, int a, int b) {
    for (int i = 0; i < blocked.size(); i++) {
        if (blocked[i].first == a && blocked[i].second == b) {
            return true;
        }
    }
    return false;
}

double distance(vii rides, int a, int b) {
    return sqrt(pow(rides[a].first - rides[b].first, 2) + pow(rides[a].second - rides[b].second, 2));
}

double try_path(vii rides, vii blocked, vector<bool> visited, int k) {
    bool complete = true;
    int r = rides.size(), b = blocked.size();
    bool done = true;
    for (int i = 0; i < visited.size(); i++) {
        if (!visited[i]) {
            done = false;
            break;
        }
    }
    if (done) {
        return 0;
    }
    double min_path = INFINITY;
    for (int i = 0; i < r; i++) {
        if (!visited[i] && !path_blocked(rides, k, i)) {
            visited[i] = true;
            min_path = min(min_path, distance(rides, k, i) + 120.0 + try_path(rides, blocked, visited, i));
            visited[i] = false;
        }
    }
    return min_path;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, b;
        cin >> r >> b;
        vii rides(r);
        vii blocked(b);
        for (int i = 0; i < r; i++) {
            cin >> rides[i].first >> rides[i].second;
        }

        for (int i = 0; i < b; i++) {
            cin >> blocked[i].first >> blocked[i].second;
        }

        if (!possible(r, blocked)) {
            cout << "no" << endl;
            continue;
        }
        vector<bool> visited(r, false);
        cout << try_path(rides, blocked, visited, 1) << endl;
    }
    return 0;
}

