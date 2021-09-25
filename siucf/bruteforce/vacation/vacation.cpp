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
#include <math.h>

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

bool path_blocked(vii &blocked, int a, int b) {
    for (int i = 0; i < blocked.size(); i++) {
        if (blocked[i].first == a && blocked[i].second == b
                || blocked[i].first == b && blocked[i].second == a) {
            return true;
        }
    }
    return false;
}

int distance(vii &rides, int a, int b) {
    return sqrt(pow(rides[a].first - rides[b].first, 2) + pow(rides[a].second - rides[b].second, 2));
}

bool next_perm(int *nums, int n) {
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;

    if (i == -1) return false;

    int x = nums[i];
    int j = n - 1;
    while (j > i && nums[j] <= x) j--;

    nums[i] = nums[j];
    nums[j] = x;

    sort(nums + i + 1, nums + n);
    return true;
}

double try_path(vii &rides, vii &blocked) {
    int r = rides.size();
    int perm[r];
    for (int i = 0; i < r; i++) {
        perm[i] = i;
    }

    double min_weight = INFINITY;
    while (next_perm(perm + 1, r - 1)) {
        double weight = 0;
        for (int i = 0; i < r - 1; i++) {
            if (path_blocked(rides, perm[i], perm[i + 1])) {
                weight = INT_MAX;
                break;
            }
            weight += distance(rides, perm[i], perm[i + 1]);
        }
        weight += r * 120;
        min_weight = min(min_weight, weight);
    }
    return min_weight;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
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

        printf("Vacation #%d:\n", t + 1);
        double time = try_path(rides, blocked);
        if (time == INFINITY) {
            printf("Jimmy should plan this vacation a different day.\n");
        } else {
            printf("Jimmy can finish all of the rides in %.3lf seconds.\n", time);
        }
    }
    return 0;
}

