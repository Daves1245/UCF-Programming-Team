/*
 * Author: medbar
 * Date: 2021-07-30
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

ll solve(int coinList[], int weights[], int n, int value) {
    int coins[value+1];       //store minimum coins for value i
    ll ret = 0;

    if(value == 0)
        return 0;              //for value 0, it needs 0 coin

    coins[0] = 0;

    for (int i=1; i<=value; i++)
        coins[i] = INT_MAX;            //initially all values are infinity except 0 value

    for (int i=1; i<=value; i++) {      //for all values 1 to value, find minimum values
        for (int j=0; j<n; j++)
            if (coinList[j] <= i) {
                int tempCoins = coins[i-coinList[j]];
                if (tempCoins != INT_MAX && tempCoins + 1 < coins[i])
                    coins[i] = tempCoins + 1;
            }
    }
    return coins[value];
}

int main() {
    int t;
    cin >> t;

    int slices[] = {6, 8, 10};
    int weights[] = {15, 20, 25};

    while (t--) {
        int n;
        cin >> n;
    }
    return 0;
}

