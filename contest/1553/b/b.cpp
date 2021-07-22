/*
 * Author: medbar
 * Date: 2021-07-22
 */

#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
#include <utility>
#include <math.h>
#include <queue>
#include <stdint.h>
#include <chrono>
#include <numeric>
#include <unordered_set>
#include <queue>

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

int find_first(int pos, string s, char c) {
    for (int j = 0; j < s.size(); j++) {
        if (j == pos) {
            continue;
        }
        if (s[j] == c) {
            return j;
        }
    }
    return -1;
}

int find_last(int pos, string s, char c) {
    for (int j = s.size() - 1; j >= 0; j--) {
        if (j == pos) {
            continue;
        }
        if (s[j] == c) {
            return j;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    string s, t;
    getline(cin, s);
    while (T--) {
        getline(cin, s);
        getline(cin, t);
        int pos = s.find(t[0]);
        int j = -1;
        for (int i = 1; i < t.size(); i++) {
            j = find_last(pos, s, t[i]);
            printf("found %c at %d\n", t[i], j);
            if (j < 0) {
                goto fail;
            }
            pos = j;
            i++;
            if (i == t.size()) {
                goto win;
            }
            j = find_first(pos, s, t[i]);
            printf("found %c at %d\n", t[i], j);
            if (j < 0) {
                goto fail;
            }
            pos = j;
        }
win:
        cout << "YES" << endl;
        continue;
fail:
        cout << "NO" << endl;
        continue;
    }
}

