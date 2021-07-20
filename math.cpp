/*
 * Author: $%U%$
 * Date: $%Y%$-$%M%$-$%D%$
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
typedef vector<bool> vb;
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

vb primes(int n) {
    vb is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// O(sqrt(n))
vector<pair<ll, int>> slow_prime_factorization(ll n) {
    vector<pair<ll, int>> ret;
    for (int i = 2; (ll) i * i <= n; i++) {
        ll factor = 1;
        int exp = 0;
        while (n % i == 0) {
            factor *= i;
            n /= i;
            exp++;
        }
        if (factor != 1) {
            ret.push_back(pair<ll, int>(i, exp));
            ret.push_back(pair<ll, int>(n, 1));
        }
    }
    return ret;
}

void p(vi v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    for (int i = 1; i < 100; i++) {
        vector<pair<ll, int>> prime_factorization = slow_prime_factorization(i);
        cout << "i: " << i << " = ";
        for (auto j : prime_factorization) {
            if (j.second == 1) {
                cout << j.first;
            } else {
                cout << j.first << "^" << j.second;
            }
            cout << " * ";
        }
        cout << endl;
    } 
    return 0;
}

