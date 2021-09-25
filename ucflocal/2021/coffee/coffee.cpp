/*
 * Author: medbar
 * Date: 2021-09-04
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

const double pi = 3.1415926535897932384;

double vol(double r, double h) {
    return pi * r * r * h / 3;
}

int main() {
    double r, s, h, m, d;
    cin >> r >> s >> h >> m >> d;
    double coffee_r = s - (h - d) * (s - r) / h;
    double hp = h * r / (s - r);

    double vol_t = vol(s, h + hp);
    double vol_c = vol(coffee_r, d + hp);

    double rate = (vol(s, h + hp) - vol(coffee_r, d + hp)) / m;
    printf("%.9lf\n", (vol(coffee_r, d + hp) - vol(r, hp)) / rate);
    return 0;
}

